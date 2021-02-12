FROM alpine:latest

EXPOSE 80 443 22

RUN apk update && apk upgrade
RUN apk add nginx
RUN adduser -D www
RUN mkdir -p /run/nginx

ADD ./data/localhost.cert /localhost.cert
ADD ./data/localhost.key /localhost.key
ADD ./data/redir.conf /etc/nginx/nginx.conf

CMD nginx -g 'daemon off;'
