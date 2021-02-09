FROM debian:buster
MAINTAINER mlabouri@student.42.fr
ENV DEBIAN_FRONTEND=noninteractive

##SETUP
#Database Related ENVs
ENV DBUSER=segbot
ENV DBPASSWORD=segbot
#BotRelated ENVs
ENV USERS=mlabouri\ tefroiss
#Ports
EXPOSE 3000
EXPOSE 5432

RUN apt update && apt -y upgrade

##Installation
#Install Grafana
RUN apt install -y apt-transport-https software-properties-common wget adduser libfontconfig1
RUN wget https://dl.grafana.com/oss/release/grafana_7.0.1_amd64.deb
RUN dpkg -i grafana_7.0.1_amd64.deb

#Install PostgreSQL
RUN apt install -y postgresql libpq-dev postgresql-client postgresql-client-common
USER postgres
RUN /etc/init.d/postgresql start &&\
    psql --command "CREATE USER ${DBUSER} WITH SUPERUSER PASSWORD '${DBPASSWORD}';" &&\
    createdb -O ${DBUSER} segbot
RUN echo "host all  all  0.0.0.0/0  md5" >> /etc/postgresql/11/main/pg_hba.conf
RUN echo "listen_addresses='*'" >> /etc/postgresql/11/main/postgresql.conf

#Install segBot
USER root
WORKDIR home/d42b/
RUN apt install -y golang git
RUN git clone https://github.com/Millefeuille42/piscibot /home/d42b
RUN go build -o d42b .

ADD srcs/botenvs.env /home/d42b/dev.env
ADD srcs/botenvs.env /home/d42b/dev.env
ADD srcs/grafana.ini /etc/grafana/grafana.ini
ADD srcs/postgres.yaml /etc/grafana/provisioning/datasources/datasources.yaml
ADD srcs/dashboards.yaml /etc/grafana/provisioning/dashboards/dashboards.yaml
ADD srcs/dashboards /home/dashboards
RUN chmod 777 /home/dashboards

CMD service grafana-server start & su postgres -c "/usr/lib/postgresql/11/bin/postgres -D /var/lib/postgresql/11/main -c config_file=/etc/postgresql/11/main/postgresql.conf" & ./d42b ${USERS} & tail -f /dev/null
