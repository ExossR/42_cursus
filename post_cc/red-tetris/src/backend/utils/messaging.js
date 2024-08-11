/**
 * Sends a message to a socket or a group of sockets.
 * @param {Socket|Server} socket - The Socket object for a single user or the Server object for group communications.
 * @param {string} eventName - The name of the event under which the message will be sent.
 * @param {string|null} targetId - The ID of the recipient or the room to send to multiple users, if specified.
 * @param {string} status - The status of the response, e.g., 'success' or 'error'.
 * @param {string} message - Descriptive message associated with the response.
 * @param {Object|null} data - Additional data to send with the response, if necessary.
 */
export function sendMessage(socket, eventName, targetId, status, message, data = null) {
  const payload = { status, message, data };
  if (targetId) {
    socket.to(targetId).emit(eventName, payload);
  } else {
    socket.emit(eventName, payload);
  }
}
