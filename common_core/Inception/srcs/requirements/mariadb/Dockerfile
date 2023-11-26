FROM alpine:3.17

RUN apk update; apk add --no-cache mariadb mariadb-client

COPY ./tools/sc_db.sh /tmp/db.sh

RUN chmod 777 /tmp/db.sh

ENTRYPOINT ["sh", "/tmp/db.sh"]