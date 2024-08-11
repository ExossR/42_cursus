import io from "socket.io-client";

// actionTypes.js
export const SOCKET_CONNECT = 'SOCKET_CONNECT';
export const SOCKET_DISCONNECT = 'SOCKET_DISCONNECT';
export const SOCKET_ERROR = 'SOCKET_ERROR';

export const connectSocket = () => (dispatch) => {
    const socket = io('http://127.0.0.1:3000');

    socket.on('connect', () => {
        dispatch({ type: SOCKET_CONNECT, payload: socket });
    });

    socket.on('disconnect', () => {
        dispatch({ type: SOCKET_DISCONNECT });
    });

    socket.on('error', (error) => {
        dispatch({ type: SOCKET_ERROR, payload: error });
    });
};
