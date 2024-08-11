FROM ubuntu:latest

WORKDIR /usr/src/app

RUN apt-get update && apt-get upgrade -y && \
	apt-get install pocl-opencl-icd ocl-icd-opencl-dev -y

COPY hashcat-6.2.6 .

CMD ["tail", "-f", "/dev/null"]
