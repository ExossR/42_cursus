FROM node:lts

WORKDIR /app

COPY package*.json ./

EXPOSE 3000

ENTRYPOINT ["/bin/sh", "-c", "npm install --non-interactive && npm run start"]
