const initialState = {
    socket: null,
    error: null,
};

const socketReducer = (state = initialState, action) => {
    switch (action.type) {
        case 'SOCKET_CONNECT':
            return {
                ...state,
                socket: action.payload,
            };
        case 'SOCKET_ERROR':
            return {
                ...state,
                error: action.payload,
            };
        case 'SOCKET_DISCONNECT':
            return {
                ...state,
                socket: null,
            };
        default:
            return state;
    }
};

export default socketReducer;