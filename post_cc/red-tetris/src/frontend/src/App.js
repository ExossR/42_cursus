import React, { useEffect } from 'react';
import { BrowserRouter as Router, Route, Routes, Navigate} from 'react-router-dom';
import { useDispatch, useSelector } from 'react-redux';

// Files
import Home from './Components/Home';
import Login from './Components/Login';
import Game from './Components/Game';
import { connectSocket } from './actions/socketActions';

// Css
import './App.css';

function App() {

    const background = {
        background: 'linear-gradient(-180deg, rgba(255,255,255,0.50) 0%, rgba(0,0,0,0.50) 100%)',
        minHeight: '100vh',
    }

    const username = useSelector((state) => state.auth.username);
    const socket = useSelector((state) => state.socket.socket);
    const dispatch = useDispatch();

    useEffect(() => {
        if (!socket && !username)
            dispatch(connectSocket());
    }, [dispatch, username, socket]);

    return (
        <Router>
            <div style={background}>
                <Routes>
                    <Route path="/" element={username ? <Home /> : <Login />} />
                    <Route path="/:room/:player" element={<Game />} />
                </Routes>
            </div>
        </Router>
    );
}

export default App;
