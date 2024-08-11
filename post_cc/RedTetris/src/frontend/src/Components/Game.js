import React, { useEffect, useState } from 'react';
import { useParams, useNavigate, useLocation } from 'react-router-dom';
import { useSelector, useDispatch } from 'react-redux';
import { StyledLink, StyledPaper, StyledContainer } from './styledFunctions';
import { Container, Grid, Typography, Button, List, ListItem, ListItemAvatar, Avatar, ListItemText, Radio, Alert, Checkbox } from '@mui/material';

import Tetris from './Tetris';

const Game = () => {
    const [hasBegun, setHasBegun] = useState(false);
    const [difficulty, setDifficulty] = useState('easy');
    const [isInfinite, setIsInfinite] = useState(false);
    const [namePlayers, setNamePlayers] = useState([]);
    const [isOwner, setIsOwner] = useState(false);
    const [error, setError] = useState('');
    const username = useSelector((state) => state.auth.username);
    const socket = useSelector((state) => state.socket.socket);
    const navigate = useNavigate();
    const dispatch = useDispatch();
    const location = useLocation();
    const { room, player } = useParams();

    const handleLaunch = async (event) => {
        setError('');
        event.preventDefault();
        socket.emit("startGame", { gameId: room, playerId: socket.id });
        socket.once("startGame", (response) => {
            if (response.status === 'success') 
                setHasBegun(true);
            else
                setError('Error while starting game.');
        });
    };

    const handleChangeDifficulty = (event) => {
        const { name, value, checked } = event.target;
        setError('');
        event.preventDefault();
        if (name === 'infinite-mode')
            setIsInfinite(checked);
        else
            setDifficulty(value);
        socket.emit('setDifficulty', { 
            gameId: room, 
            difficulty: name === "infinite-mode" ? difficulty : value,
            isInfinite: name === "infinite-mode" ? checked : isInfinite
        });
        socket.once('setDifficulty', (response) => {
            if (response.status !== 'success') 
                setError('Error while changing difficulty.');
        });
    };

    useEffect(() => {
        if (!socket) {
            dispatch({ type: 'LOGOUT' });
            dispatch({ type: 'SOCKET_DISCONNECT' });
            navigate('/');
            return ;
        }
        if (location.action === 'POP') {
            dispatch({ type: 'LOGOUT' });
            dispatch({ type: 'SOCKET_DISCONNECT' });
            socket.emit('leaveRoom', { gameId: room, playerId: socket.id });
            return ;
        }

        if (!hasBegun) {
            socket.on('startGame', (response) => {
                if (response.data.gameId === room)
                    setHasBegun(true);
            });
            socket.on('reloadGame', () => {
                socket.emit('getGame', { gameId: room });
                socket.once('getGame', (response) => {
                    if (response.status === 'success') {
                        setNamePlayers(response.data.players);
                        setDifficulty(response.data.difficulty);
                        setIsInfinite(response.data.isInfinite);
                        if (response.data.owner === socket.id)
                            setIsOwner(true);
                        else
                            setIsOwner(false);
                    }
                    else
                        setError(response.message);
                });
            });

            socket.emit('getGame', { gameId: room });
            socket.once('getGame', (response) => {
                if (response.status === 'success') {
                    setNamePlayers(response.data.players);
                    setDifficulty(response.data.difficulty);
                    setIsInfinite(response.data.isInfinite);
                    if (response.data.owner === socket.id)
                        setIsOwner(true);
                    else
                        setIsOwner(false);
                }
                else {
                    setError(response.message);
                    if (response.message === 'Game not found') {
                        dispatch({ type: 'LOGOUT' });
                        dispatch({ type: 'SOCKET_DISCONNECT' });
                        navigate('/');
                    }
                }
            });
        }
        else {
            socket.off('reloadGame');
        }

        return () => {
            dispatch({ type: 'LOGOUT' });
            dispatch({ type: 'SOCKET_DISCONNECT' });
            if (hasBegun)
                socket.emit('leaveGame', { gameId: room, playerId: socket.id });
            else
                socket.emit('leaveRoom', { gameId: room, playerId: socket.id });
            navigate('/');
        };
    }, [username, socket, navigate]);

    return (
        <>
            {
                hasBegun &&
                <>
                    <Tetris setIsInGame={setHasBegun}/>
                </>
            }
            {
                !hasBegun &&
                <>
                    <StyledContainer>
                        <StyledLink>
                            <div
                                onClick={ async () => {
                                    await dispatch({ type: 'LOGOUT' });
                                    await dispatch({ type: 'SOCKET_DISCONNECT' });
                                    navigate('/');
                                    socket.emit('leaveRoom', { gameId: room, playerId: socket.id });
                                }}
                                style={{ cursor: 'pointer' }}
                            >
                                <h1 className='blinking-text'>RED TETRIS</h1>
                            </div>
                        </StyledLink>
                    </StyledContainer>
                    <Container>
                        <Grid container direction="row" justify="center" alignItems="flex-start" spacing={2}>

                            {/* DIFFICULTIES' CHOICE */}
                            <Grid item xs={4}>
                                <StyledPaper variant='outlined' square={false}>
                                    <Typography variant='h4'><b>Difficulties</b></Typography>
                                    <List>
                                        {
                                            isOwner &&
                                            <>
                                                {['easy', 'medium', 'hard'].map((text, index) => {
                                                    return (
                                                        <ListItem
                                                            key={index}
                                                            sx={{ fontSize: '2em' }}
                                                            secondaryAction={
                                                                <Radio
                                                                    checked={difficulty === text}
                                                                    onChange={handleChangeDifficulty}
                                                                    value={text}
                                                                    name='radio-buttons'
                                                                    inputProps={{ 'aria-label': text }}
                                                                />
                                                            }
                                                        >
                                                            <ListItemAvatar>
                                                                <Avatar
                                                                    alt={text}
                                                                    src={`/${text}.jpeg`}
                                                                />
                                                            </ListItemAvatar>
                                                            <ListItemText primary={text} />
                                                        </ListItem>
                                                    );
                                                })}
                                                <hr/>
                                                <ListItem
                                                    key="infinite"
                                                    secondaryAction={
                                                        <Checkbox 
                                                            label="Infinite mode"
                                                            checked={isInfinite}
                                                            onChange={handleChangeDifficulty}
                                                            value="infinite"
                                                            name="infinite-mode"
                                                        />
                                                    }
                                                >
                                                    <ListItemText primary="Infinite mode" />
                                                </ListItem>
                                            </>
                                        }
                                        {
                                            !isOwner &&
                                            <>
                                                <Typography>
                                                    <b>Difficulty set by owner: {difficulty}</b>
                                                </Typography>
                                                <hr/>
                                                <Typography>
                                                    <b>Infinite mode: {isInfinite ? 'Yes' : 'No'}</b>
                                                </Typography>
                                            </>
                                        }
                                    </List>

                                </StyledPaper>
                            </Grid>

                            {/* ROOM'S NAME AND PLAYER'S NAME + LAUNCH GAME*/}
                            <Grid item xs={4}>
                                <StyledPaper variant='outlined' square={false}>
                                    {
                                        isOwner &&
                                        <>
                                            <Typography>
                                                Room's name: <b>{room}</b><br />
                                                <b>You are the owner</b>
                                            </Typography>
                                            { error && <Alert severity='error'>{error}</Alert> }
                                            <Button variant="contained" size="large" fullWidth sx={{ marginTop: "10px" }} onClick={handleLaunch}>
                                                Launch
                                            </Button>
                                        </>
                                    }
                                    {
                                        !isOwner &&
                                        <>
                                            <Typography>
                                                Room's name: <b>{room}</b><br />
                                                <b>Waiting for owner to begin...</b>
                                            </Typography>
                                            <Button variant="contained" size="large" fullWidth sx={{ marginTop: "10px" }} disabled>
                                                Launch
                                            </Button>
                                        </>
                                    }
                                </StyledPaper>
                            </Grid>

                            {/* PLAYERS' LIST */}
                            <Grid item xs={4}>
                                <StyledPaper variant='outlined' square={false}>
                                    <Typography variant='h4'><b>Player's List</b></Typography>
                                    <List
                                        sx={{
                                            width: '100%',
                                            maxWidth: 360,
                                            bgcolor: 'background.paper',
                                            overflow: 'auto',
                                            position: 'relative',
                                            height: 450,
                                        }}
                                    >
                                        {
                                            namePlayers.length > 0 && namePlayers.map((player, index) => (
                                                <ListItem key={index} sx={{ fontSize: '2em'}}>{player.name}</ListItem>
                                            ))
                                        }
                                    </List>
                                </StyledPaper>
                            </Grid>

                        </Grid>
                    </Container>
                </>
            }
        </>
    );
};

export default Game;
