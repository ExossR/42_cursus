jest.mock('http', () => ({
  createServer: jest.fn().mockImplementation(app => ({
    listen: jest.fn((port, callback) => callback())
  }))
}));

jest.mock('express', () => {
  const mockExpress = () => ({
    use: jest.fn(),
    get: jest.fn(),
    post: jest.fn(),
    listen: jest.fn((port, callback) => callback())
  });
  mockExpress.Router = jest.fn(() => ({
    get: jest.fn(),
    post: jest.fn()
  }));
  return mockExpress;
});

jest.mock('../socketConfig', () => ({
  setupSocket: jest.fn()
}));

describe('server.js', () => {
  beforeEach(() => {
    jest.resetModules();
  });

  it('should create an HTTP server', () => {
    jest.isolateModules(() => {
      const http = require('http');
      const express = require('express');
      const app = express();
      require('../server');
      expect(http.createServer).toHaveBeenCalled();
    });
  });

  it('should setup sockets', () => {
    jest.isolateModules(() => {
      const { setupSocket } = require('../socketConfig');
      const express = require('express');
      const app = express();
      require('../server');
      expect(setupSocket).toHaveBeenCalled();
    });
  });

  it('should handle server listening event', () => {
    jest.isolateModules(() => {
      const logSpy = jest.spyOn(console, 'log');
      const express = require('express');
      const app = express();
      require('../server');
      expect(logSpy).toHaveBeenCalledWith('Server listening on port 3000');
    });
  });
});
