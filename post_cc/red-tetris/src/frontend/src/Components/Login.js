import React, { useState } from 'react';
import { Alert, Grid, Dialog, DialogTitle, DialogActions, DialogContent, DialogContentText, TextField, Button } from '@mui/material';
import { useDispatch, useSelector } from 'react-redux';
import './Login.css'

const Login = () => {
    const [open, setOpen] = useState(false);
    const [error, setError] = useState('');
    const [username, setUsername] = useState('');
    const socket = useSelector((state) => state.socket.socket);
    const dispatch = useDispatch();
    const regexUsername = /^[a-zA-Z0-9_]*$/;

    const handleClickOpen = () => {
        setOpen(true);
    };

    const handleSubmit = async (event) => {
        setError('');
        event.preventDefault();
        if (username.length > 10) {
            setError('Username is too long. Please change.');
        } else if (!regexUsername.test(username)) {
            setError('Invalid username. Please change.');
        } else {
            socket.emit('createPlayer', { playerName: username }); // Envoyer uniquement le username nécessaire
            socket.once('createPlayer', (response) => { // Utiliser `once` pour écouter une seule fois après l'envoi
                if (response.status === 'success') {
                    setOpen(false);
                    dispatch({ type: 'LOGIN', payload: username });
                } else {
                    setError(response.message); // Gérer les erreurs venant du serveur
                }
            });
        }
    };

    return (
        <div onClick={handleClickOpen} tabIndex="0">
            <Grid
                container
                spacing={0}
                direction="column"
                alignItems="center"
                justifyContent="center"
                sx={{ minHeight: '100vh' }}
            >
                <h1 className='blinking-text'>REDTETRIS</h1>
            </Grid>
            <Dialog
                open={open}
                onClose={(event) => {
                    event.stopPropagation();
                    setOpen(false);
                    setError('');
                }}
                PaperProps={{
                    component: 'form',
                    onSubmit: handleSubmit,
                }}
            >
                <DialogTitle>Choose your name</DialogTitle>
                <DialogContent>
                    { error && <Alert severity="error">{error}</Alert> }
                    <DialogContentText>
                        Please enter your Username <i>10 characters max</i>
                    </DialogContentText>
                    <TextField
                        autoFocus
                        required
                        margin="dense"
                        id="name"
                        name="username"
                        label="Username"
                        type="text"
                        fullWidth
                        variant="standard"
                        value={username}
                        onChange={(event) => setUsername(event.target.value)}
                    />
                </DialogContent>
                <DialogActions>
                    <Button onClick={(event) => {
                            event.stopPropagation();
                            setOpen(false);
                            setError('');
                        }}
                        tabIndex={0}
                    >Cancel</Button>
                    <Button type="submit">Play</Button>
                </DialogActions>
            </Dialog>
        </div>
    );
};

export default Login;
