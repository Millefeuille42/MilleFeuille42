FROM alpine:latest

EXPOSE 3000

RUN echo 'http://dl-cdn.alpinelinux.org/alpine/edge/testing' >> /etc/apk/repositories
RUN apk update && apk upgrade
RUN apk add grafana

ADD data/grafana.ini /usr/share/grafana/conf/grafana.ini
ADD data/influx.yaml /usr/share/grafana/conf/provisioning/datasources/datasources.yaml
ADD data/dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/dashboards.yaml

ADD data/dashboards/docker.json /docker.json

CMD grafana-server -homepath="/usr/share/grafana/" -config="/usr/share/grafana/conf/grafana.ini"
