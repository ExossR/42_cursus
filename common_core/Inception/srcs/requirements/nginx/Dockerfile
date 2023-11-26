FROM debian:buster

RUN apt-get update -y
RUN apt-get install -y nginx openssl

RUN mkdir -p /etc/nginx/ssl; mkdir -p /run/nginx
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/asahonet.crt \
	-keyout /etc/nginx/ssl/asahonet.key \
	-subj "/C=FR/ST=AM/L=NICE/O=42/OU=asahonet/CN=asahonet/"

COPY ./conf/nginx.conf /etc/nginx/conf.d/default.conf

ENTRYPOINT ["nginx", "-g", "daemon off;"]
