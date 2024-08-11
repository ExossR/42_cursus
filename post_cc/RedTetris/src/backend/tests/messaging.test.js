const http = require('http');
const socketClient = require('socket.io-client');
const { setupSocket } = require('../socketConfig.js');
const { sendMessage } = require('../utils/messaging.js');

let server, httpServer, clientSocket;

function createClientSocket() {
  const port = httpServer.address().port;
  return socketClient(`http://localhost:${port}`, {
    'reconnection delay': 0,
    'reopen delay': 0,
    'force new connection': true,
    transports: ['websocket'],
  });
}

beforeAll((done) => {
  httpServer = http.createServer();
  server = setupSocket(httpServer);

  httpServer.listen(() => {
    done();
  });
});

beforeEach(done => {
  clientSocket = createClientSocket();
  clientSocket.on('connect', () => {
    done();
  });
  clientSocket.on('connect_error', error => {
    console.error("Connect error:", error);
  });
});

describe('sendMessage', () => {
  test('should send a message to a single socket', done => {
      clientSocket.on('testEvent', msg => {
        expect(msg).toEqual({ status: 'success', message: 'Test message', data: null });
        done();
      });
      sendMessage(clientSocket, 'testEvent', null, 'success', 'Test message');
      done();
    });
});

test('should send a message to all', done => {
    clientSocket.on('testEvent', msg => {
      expect(msg).toEqual({ status: 'success', message: 'Test message', data: null });
      done();
    });
    sendMessage(server, 'testEvent', "all", 'success', 'Test message');
    done();
  }
);

afterEach(() => {
  if (clientSocket.connected) {
    clientSocket.disconnect();
  }
});

afterAll((done) => {
  httpServer.close(done);
});
