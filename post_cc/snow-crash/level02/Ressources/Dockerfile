FROM ubuntu:latest

WORKDIR /usr/src/app

RUN apt-get update && apt-get upgrade -y && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y wireshark

COPY level02.pcap .

CMD ["tail", "-f", "/dev/null"]

