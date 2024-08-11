import React, { useEffect, useState } from 'react';
import { useSelector, useDispatch } from 'react-redux';
import { Grid, List, ListItem, Button, Container, Typography, Alert } from '@mui/material';
import { StyledLink, StyledPaper, StyledContainer } from './styledFunctions';
import { useNavigate } from 'react-router-dom';

const Home = () => {
    const [gamesList, setGamesList] = useState([]);
    const [leaderboard, setLeaderboard] = useState([]);
    const [error, setError] = useState('');
    const [errorGame, setErrorGame] = useState('');
    const [errorBoard, setErrorBoard] = useState('');
    const username = useSelector((state) => state.auth.username);
    const socket = useSelector((state) => state.socket.socket);
    const navigate = useNavigate();
    const dispatch = useDispatch();

    const joinGame = (game) => {
        navigate(`/${game}/${username}`);
    };

    const handleCreateGame = (event) => {
        event.preventDefault();
        setError('');
        socket.emit('createGame', { playerId: socket.id });
        socket.once('createGame', (response) => {
            if (response.status === 'success')
                joinGame(response.data.gameId);
            else
                setError(response.message);
        });
    };

    const handleJoinGame = (gameId) => (event) => {
        event.preventDefault();
        socket.emit('joinGame', { gameId: gameId, playerId: socket.id });
        socket.once('joinGame', (response) => {
            if (response.status === 'success')
                joinGame(gameId);
            else
                setError(response.message);
        });
    };

    useEffect(() => {
        if (!socket)
            return ;

        socket.on('reloadHome', () => {
            setErrorGame('');
            socket.emit('getGames');
            socket.once('getGames', (response) => {
                if (response.status === 'success')
                    setGamesList(response.data.games);
                else
                    setErrorGame(response.message);
            });
        });
        socket.emit('getGames');
        socket.once('getGames', (response) => {
            if (response.status === 'success')
                setGamesList(response.data.games);
            else
                setErrorGame(response.message);
        });
        socket.emit('getLeaderboard');
        socket.once('getLeaderboard', (response) => {
            if (response.status === 'success')
                setLeaderboard(response.data.leaderboard);
            else
                setErrorBoard(response.message);
        });

        const handleBeforeUnload = () => {
            dispatch({ type: 'LOGOUT' });
            dispatch({ type: 'SOCKET_DISCONNECT' });
        };
        window.addEventListener('beforeunload', handleBeforeUnload);
        return (() => {
            window.removeEventListener('beforeunload', handleBeforeUnload);
            socket.off('reloadHome');
        });
    }, [username, socket, dispatch]);
    return (
        <>
            <StyledContainer>
                <StyledLink>
                    <div
                        onClick={() => {
                            dispatch({ type: 'LOGOUT' });
                            dispatch({ type: 'SOCKET_DISCONNECT' });
                        }}
                        style={{ cursor: 'pointer'}}
                    >
                        <h1 className='blinking-text'>RED TETRIS</h1>
                    </div>
                </StyledLink>
            </StyledContainer>
            <Container>
                <Grid container direction="row" justify="center" alignItems="flex-start" spacing={2}>

                    {/* LEADERBOARD */}
                    <Grid item xs={4}>
                        <StyledPaper variant='outlined' square={false}>
                            <Typography variant='h4'><b>Leaderboard</b></Typography>
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
                                    leaderboard.length > 0 &&
                                    leaderboard.map((entry, index) => (
                                        <ListItem key={index} sx={{ fontSize: '1.5em' }}>
                                            {index + 1} - {entry.user}: {entry.score}
                                        </ListItem>
                                    ))
                                }
                                {
                                    leaderboard.length === 0 && <Alert severity="info" sx={{ marginBottom: '10px'}}>No entry in leaderboard</Alert>
                                }
                                {
                                    errorBoard && <Alert severity="info" sx={{ marginBottom: '10px'}}>{errorBoard}</Alert>
                                }
                            </List>
                        </StyledPaper>
                    </Grid>

                    {/* CREATE GAME + ERRORS' MESSAGES */}
                    <Grid item xs={4}>
                        <Typography
                            variant='h4'
                            textAlign="center"
                            sx={{
                                textShadow: '2px 2px 4px rgba(0, 0 , 0, 0.6)',
                                color: 'rgba(11, 21, 93, 0.8)',
                                fontFamily: 'Arial',
                            }}
                        >
                            {username}
                        </Typography>
                        <StyledPaper variant='outlined' square={false}>
                            { error && <Alert severity="error" sx={{ marginBottom: '10px'}}>{error}</Alert> }
                            <Button variant="contained" size="large" fullWidth sx={{ marginTop: "10px" }} onClick={handleCreateGame}>
                                Create
                            </Button>
                        </StyledPaper>
                    </Grid>

                    {/* ROOMS' LIST */}
                    <Grid item xs={4}>
                    <StyledPaper variant='outlined' square={false}>
                            <Typography variant='h4'><b>Rooms</b></Typography>
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
                                    !errorGame && gamesList.length > 0 && gamesList.map((game, index) => (
                                        <StyledLink
                                            to={game.isStarted ? '#' : `/${game.gameId}/${username}`}
                                            key={index}
                                            onClick={game.isStarted ? (e) => e.preventDefault() : handleJoinGame(game.gameId)}
                                            data-gameid={game.gameId}
                                            style={{ color: game.isStarted ? 'gray' : 'inherit', pointerEvents: game.isStarted ? 'none' : 'auto' }}
                                        >
                                            <ListItem 
                                                key={index}
                                                sx={{ 
                                                    fontSize: '2em',
                                                    backgroundColor: game.isStarted ? '#e0e0e0' : 'inherit',
                                                    cursor: game.isStarted ? 'default' : 'pointer'
                                                }}
                                            >
                                                {game.owner}'s room {game.players}/4 {game.isStarted && '(In Progress)'}
                                            </ListItem>
                                        </StyledLink>
                                    ))
                                }
                                {
                                    errorGame && <Alert severity="info" sx={{ marginBottom: '10px'}}>{errorGame}</Alert>
                                }
                            </List>
                        </StyledPaper>
                    </Grid>
                </Grid>

            </Container>
        </>
    );
}

export default Home;
