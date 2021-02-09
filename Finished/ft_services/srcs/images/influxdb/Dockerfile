FROM alpine:latest

EXPOSE 8086

RUN echo 'http://dl-cdn.alpinelinux.org/alpine/edge/testing' >> /etc/apk/repositories
RUN apk update && apk upgrade
RUN apk add influxdb
RUN apk add telegraf

ADD ./data/influxdb.conf /etc/influxdb/influxdb.conf
ADD ./data/telegraf.conf /etc/telegraf/telegraf.conf
ADD ./data/init.inf /init.inf
ADD ./data/init.sh /init.sh

CMD ./init.sh
