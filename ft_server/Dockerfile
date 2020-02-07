FROM debian:buster
MAINTAINER mlabouri@student.42.fr

ENV DEBIAN_FRONTEND=noninteractive

# /usr/share/phpmyadmin/config.inc.php
# /etc/nginx/conf.d/phpMyAdmin.conf

    #init
RUN apt-get update && apt-get -y upgrade

    #nginx
RUN apt-get -y install wget curl vim nginx gnupg (lsb-release)

    #MySQL
WORKDIR /tmp
RUN wget https://dev.mysql.com/get/mysql-apt-config_0.8.13-1_all.deb && dpkg -i mysql-apt-config*

    #PHP
WORKDIR /root
RUN apt-get -y install default-mysql-server php-fpm php-mysql php-mbstring php-zip php-gd

    #Configure nginx for PHP
RUN mkdir /var/www/ft_server && rm -rf /var/www/html && chown -R root:root /var/www/ft_server
ADD --chown=root srcs/ft_server /etc/nginx/sites-available/ft_server
RUN ln -s /etc/nginx/sites-available/ft_server /etc/nginx/sites-enabled/ && rm -rf /etc/nginx/sites-enabled/default

RUN nginx -t && service nginx stop && service nginx start

EXPOSE 80

##Install PHPMyAdmin
#    && wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz \
#    && tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz \
#    &&  mv phpMyAdmin-4.9.0.1-all-languages/ /usr/share/phpmyadmin \
##Configure PHPMyAdmin
#    &&  mkdir -p /var/lib/phpmyadmin/tmp \
#    &&  chown -R www-data:www-data /var/lib/phpmyadmin \
#    &&  cp /usr/share/phpmyadmin/config.sample.inc.php /usr/share/phpmyadmin/config.inc.php

##db?
#  mariadb < /usr/share/phpmyadmin/sql/create_tables.sql
#  mariadb < GRANT SELECT, INSERT, UPDATE, DELETE ON phpmyadmin.* TO 'pma'@'localhost' IDENTIFIED BY '';
#