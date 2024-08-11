FROM node:lts

WORKDIR /app

COPY package*.json ./

ENTRYPOINT ["/bin/sh", "-c", "npm install ; npm start"]
