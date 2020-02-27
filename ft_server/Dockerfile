FROM debian:buster
MAINTAINER mlabouri@student.42.fr

EXPOSE 80
ENV DEBIAN_FRONTEND=noninteractive

# /var/www/ft_server/phpmyadminconfig.inc.php
# /etc/nginx/conf.d/phpMyAdmin.conf

    #init
RUN apt-get update && apt-get -y upgrade

    #nginx
RUN apt-get -y install wget curl vim nginx

    #MySQL
RUN apt-get -y install mariadb-server-10.3
RUN ["/bin/bash", "-c", "debconf-set-selections <<< 'mariadb-server-5.5 mysql-server/root_password password rootpass'"]
RUN ["/bin/bash", "-c", "debconf-set-selections <<< 'mariadb-server-5.5 mysql-server/root_password_again password rootpass'"]

    #PHP
WORKDIR /root
RUN apt-get -y install default-mysql-server php-fpm php-mysql php-mbstring php-zip php-gd

    #Configure nginx for PHP
RUN mkdir /var/www/ft_server && rm -rf /var/www/html && chown -R root:root /var/www/ft_server
ADD --chown=root srcs/ft_server /etc/nginx/sites-available/ft_server
RUN ln -s /etc/nginx/sites-available/ft_server /etc/nginx/sites-enabled/ && rm -rf /etc/nginx/sites-enabled/default
RUN echo "loule" >> /var/www/ft_server/index.html

    #Install PHPMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages/ /var/www/ft_server/phpmyadmin

    #Configure PHPMyAdmin
RUN mkdir -p /var/lib/phpmyadmin/tmp
RUN chown -R www-data:www-data /var/lib/phpmyadmin
RUN cp /var/www/ft_server/phpmyadmin/config.sample.inc.php /var/www/ft_server/phpmyadmin/config.inc.php

CMD  service nginx start; echo "IP : $(hostname -I)"; while [ 1 ]; do sleep 2; done




#RUN mariadb < /var/www/ft_server/phpmyadminsql/create_tables.sql
#RUN mariadb < CREATE DATABASE test;
 #RUN mariadb < GRANT ALL ON example_database.* TO 'example_user'@'localhost' IDENTIFIED BY 'password' WITH GRANT OPTION;