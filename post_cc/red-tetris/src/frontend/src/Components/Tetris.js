import React, { useEffect, useState } from 'react';
import { StyledLink, StyledAsideLeft, StyledAsideRigt, StyledDisplay } from './styledFunctions';
import { useNavigate, useParams, useLocation } from 'react-router-dom';
import { useSelector, useDispatch } from 'react-redux';
import { Button, Container, Grid, Typography, Paper, Dialog, DialogContentText, DialogActions, DialogTitle, DialogContent } from '@mui/material';
import { styled } from '@mui/material/styles';

function createEmptyGrid() {
    return Array.from(Array(20), () => Array(10).fill(0));
}

const Tetris = ({ setIsInGame }) => {
    const socket = useSelector((state) => state.socket.socket);
    const navigate = useNavigate();
    const dispatch = useDispatch();
    const location = useLocation();
    const { room, player } = useParams();
    const [grid, setGrid] = useState(createEmptyGrid());
    const [score, setScore] = useState(0);
    const [nextPiece, setNextPiece] = useState([]);
    const [shadowGrids, setShadowGrids] = useState([]);
    const [hardDropPressed, setHardDropPressed] = useState(false);
    const [rotatePressed, setRotatePressed] = useState(false);
    const [gameOver, setGameOver] = useState(false);
    const [winner, setWinner] = useState(false);
    const [owner, setOwner] = useState('');
    const [ownerId, setOwnerId] = useState('');
    const [canRestart, setCanRestart] = useState(false);
    // update wait finished game to print button restart for owner

    const handleLeave = (event) => {
        event.preventDefault();
        dispatch({ type: 'LOGOUT' });
        dispatch({ type: 'SOCKET_DISCONNECT' });
        socket.emit('leaveGame', { gameId: room, playerId: socket.id });
        navigate('/');
    };

    const handleGameOver = (event) => {
        event.preventDefault();
        dispatch({ type: 'LOGOUT' });
        dispatch({ type: 'SOCKET_DISCONNECT' });
        socket.emit('leaveGame', { gameId: room, playerId: socket.id });
        navigate('/');
    };

    const handleRestart = (event) => {
        event.preventDefault();
        if (canRestart) {
            socket.emit('restartGame', { gameId: room });
            setIsInGame(false);
        }
        else
            alert('You must wait for other people to finish.');
    };

    const mapColor = (value) => {
        switch (value) {
            case 0:
                return '#ffffff';
            case "1":
                return '#45efe5';
            case "2":
                return '#161eec';
            case "3":
                return '#f0a823';
            case "4":
                return '#edfc04';
            case "5":
                return '#22f334';
            case "6":
                return '#e412e6';
            case "7":
                return '#ec1818';
            case "81":
                return '#32aea6';
            case "82":
                return '#1217a2';
            case "83":
                return '#996c18';
            case "84":
                return '#9fa904';
            case "85":
                return '#179f23';
            case "86":
                return '#920b94';
            case "87":
                return '#9f0f0f';
            case 9:
                return '#9a9a9a';
            default:
                return '#ffffff';
        }
    };

    const mapColorPreview = (value) => {
        switch (value) {
            case 0:
                return '#000000';
            case "1":
                return '#45efe5';
            case "2":
                return '#161eec';
            case "3":
                return '#f0a823';
            case "4":
                return '#edfc04';
            case "5":
                return '#22f334';
            case "6":
                return '#e412e6';
            case "7":
                return '#ec1818';
            default:
                return '#000000';
        }
    };

    const mapColorShadow = (value) => {
        switch (value) {
            case 0:
                return '#9a9a9a';
            case 1:
                return '#515151';
            default:
                return '#9a9a9a';
        }
    };

    const printShadowGrid = (grid) => {
        return (
            <>
                <GridTetris elevation={0}>
                    {grid.map((row, rowIndex) => (
                        <Grid key={rowIndex} container>
                            {row.map((cell, cellIndex) => (
                                <Grid key={cellIndex} item>
                                    <div style={{ background: mapColorShadow(cell), width: '5px', height: '5px', border: '1px solid' }} />
                                </Grid>
                            ))}
                        </Grid>
                    ))}
                </GridTetris>
            </>
        );
    };

    const handleKeyPressed = (event) => {
        switch (event.key) {
            case 'ArrowLeft':
                socket.emit('moveBlock', { gameId: room, direction: true });
                break;
            case 'ArrowRight':
                socket.emit('moveBlock', { gameId: room, direction: false });
                break;
            case 'ArrowDown':
                socket.emit('moveDown', { gameId: room });
                break;
            case 'ArrowUp':
                setRotatePressed(true);
                socket.emit('rotateBlock', { gameId: room });
                break;
            case ' ':
                setHardDropPressed(true);
                socket.emit('hardDrop', { gameId: room });
                break;
            default:
                return ;
        }
    };

    const handleKeyDown = (event) => {
        if (rotatePressed || hardDropPressed) {
            event.preventDefault();
            return ;
        }
        handleKeyPressed(event);
    };

    const handleKeyUp = () => {
        setRotatePressed(false);
        setHardDropPressed(false);
    };

    useEffect(() => {
        if (!socket) 
            return ;
        if (location.action === 'POP') {
            dispatch({ type: 'LOGOUT' });
            dispatch({ type: 'SOCKET_DISCONNECT' });
            socket.emit('leaveGame', { gameId: room, playerId: socket.id });
            return ;
        }

        socket.on('allowRestart', () => {
            setCanRestart(true);
        });

        socket.on('updateGame', (response) => {
            setGrid(response.data.board);
            setScore(response.data.score);
            setNextPiece(response.data.nextPiece);
            setShadowGrids(response.data.shadowGrids);
            setOwner(response.data.owner);
            setOwnerId(response.data.ownerId);
        });

        socket.on('gameOver', (response) => {
            try {
                if (response && typeof response.data.winner !== 'undefined') {
                    setWinner(response.data.winner);
                }
                if (response && typeof response.data.score !== 'undefined') {
                    setScore(response.data.score);
                }
                setGameOver(true);
            } catch (error) {
            }
        });

        socket.on('restartGame', () => {
            setIsInGame(false);
        });

        window.addEventListener('keydown', handleKeyDown);
        window.addEventListener('keyup', handleKeyUp);
        return () => {
            window.removeEventListener('keydown', handleKeyDown);
            window.removeEventListener('keyup', handleKeyUp);
            socket.off('updateGame');
        };
    }, [socket, dispatch, location.action, room, handleKeyDown]);

    const GridTetris = styled(Paper)(({ theme }) => ({
        ...theme.typography.body2,
        backgroundColor: 'transparent',
        placeContent: 'center',
        display: 'grid',
    }));

    return (
        <>
            <div
                style={{
                    display: 'flex',
                    justifyContent: 'center',
                    alignItems: 'center',
                    paddingBottom: '20px',
                    paddingTop: '10px',
                }}
            >
                <StyledLink to={'/'} onClick={handleLeave} sx={{ cursor: 'pointer' }}>
                    <Button variant='contained' size='large' fullWidth>
                        Leave
                    </Button>
                </StyledLink>
            </div>
            <Grid container columnSpacing={2} rowSpacing={2} >

                { /* Shadow Grids */ }
                <Grid item md={3.75}>
                    <StyledAsideLeft>
                        {shadowGrids.length > 0 && shadowGrids.map((player, index) => (
                            <div key={index}>
                                <Typography>{player.playerName}</Typography>
                                { printShadowGrid(player.shadowGrid) }
                            </div>
                        ))}
                    </StyledAsideLeft>
                </Grid>

                { /* Grid */ }
                <Grid item md={4.5} justifyContent="center" justifySelf="center">
                    <GridTetris elevation={0}>
                            {grid.map((row, rowIndex) => (
                                <Grid key={rowIndex} container>
                                    {row.map((cell, cellIndex) => (
                                        <Grid key={cellIndex} item>
                                            <div style={{ background: mapColor(cell), width: '30px', height: '30px', border: '1px solid' }} />
                                            {/* </div> */}
                                        </Grid>
                                    ))}
                                </Grid>
                            ))}
                    </GridTetris>
                </Grid>

                { /* Infos jeu */ }
                <Grid item md={3.75}>
                    <StyledDisplay>
                        <StyledAsideRigt>
                            <Typography variant="h3" >{owner}'s room</Typography>
                            <Typography variant="h3">{player}</Typography>
                            <Container>
                                <div style={{ display: 'ruby' }}>
                                    <Typography variant="h3">Score :</Typography>
                                    <Typography variant="h4" sx={{ marginLeft: "25px", placeContent: 'center' }}>{score}</Typography>
                                </div>
                                <br/>
                                <div style={{ display: 'grid' }}>
                                    <Typography variant="h3" sx={{ placeContent: 'start' }}>Next :</Typography>
                                    <Container>
                                        {nextPiece && nextPiece.map((row, rowIndex) => (
                                            <Grid key={rowIndex} container>
                                                {row.map((cell, cellIndex) => (
                                                    <Grid key={cellIndex} item>
                                                        <div style={{ background: mapColorPreview(cell), width: '30px', height: '30px', border: '1px solid black' }} />
                                                    </Grid>
                                                ))}
                                            </Grid>
                                        ))}
                                    </Container>
                                </div>
                            </Container>
                        </StyledAsideRigt>
                    </StyledDisplay>
                </Grid>

            </Grid>
            <Dialog
                open={gameOver}
                onClose={handleGameOver}
                aria_labelledby="alert-dialog-title"
                aria-describedby="alert-dialog-description"
            >
                <DialogTitle id="alert-dialog-title">
                    {"Game Over"}
                </DialogTitle>
                <DialogContent>
                <DialogContentText id="alert-dialog-description">
                    {winner ? `Congratulations! You won the game with a score of ${score}.\nYou can wait for the owner to restart, or leave.` : `Game over. You lost. Your score is ${score}. You can wait for the owner to restart, or leave.`}
                </DialogContentText>
                </DialogContent>
                <DialogActions>
                    <Button onClick={handleGameOver}>
                        Leave
                    </Button>
                    {
                        socket && ownerId === socket.id
                        &&
                        <Button onClick={handleRestart}>
                            Restart
                        </Button>
                    }
                </DialogActions>
            </Dialog>
        </>
    );
};

export default Tetris;
