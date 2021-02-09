FROM alpine:latest

EXPOSE 3306

ADD data/create_tables.sql /create_tables.sql
ADD data/init_remote.sql /init_remote.sql
ADD data/init_wp.sql /init_wp.sql
ADD data/init_wordpress_data.sql /init_wp_data.sql

ADD data/my.cnf /etc/mysql/my.cnf
ADD data/my.cnf /etc/my.cnf
ADD data/init.sh /init.sh

RUN apk update && apk upgrade
RUN apk add mysql mysql-client

RUN addgroup mysql mysql
RUN mkdir /run/mysqld
RUN touch /var/lib/mysql/isUp

#CMD tail -f /dev/null
CMD /init.sh
