FROM debian:buster
MAINTAINER mlabouri@student.42.fr

EXPOSE 80
ENV DEBIAN_FRONTEND=noninteractive

    #Init
RUN apt-get update && apt-get -y upgrade

    #Install packages
RUN apt-get -y install wget curl vim \
    nginx \
    php-fpm php-common php-mbstring php-xmlrpc php-soap php-gd php-xml php-intl php-mysql php-cli php-zip php-curl \
    mariadb-server-10.3 default-mysql-server

WORKDIR /tmp

    #Install PHPMyAdmin
RUN wget -q https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz\
    && tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz && rm phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages/ /usr/share/phpMyAdmin/
RUN mkdir -p /usr/share/phpMyAdmin/tmp \
    && chmod -R 777 /usr/share/phpMyAdmin && chown -R www-data:www-data /usr/share/phpMyAdmin
RUN ln -s /usr/share/phpMyAdmin /var/www/html/pma

    #Setup MYSQL
RUN ["/bin/bash", "-c", "debconf-set-selections <<< 'mariadb-server-5.5 mysql-server/root_password password'"]
RUN ["/bin/bash", "-c", "debconf-set-selections <<< 'mariadb-server-5.5 mysql-server/root_password_again password'"]
RUN service mysql start \
    && mysql < /usr/share/phpMyAdmin/sql/create_tables.sql \
    && echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql -u root \
    && echo "GRANT ALL ON wordpress.* TO 'wordpress_user'@'localhost' IDENTIFIED BY 'password';" | mysql -u root \
    && echo "FLUSH PRIVILEGES;" | mysql -u root \
    && echo "update mysql.user set plugin = 'mysql_native_password' where user='root';" | mysql -u root

    #Install WordPress
RUN cd /tmp && curl -LO https://wordpress.org/latest.tar.gz
RUN tar xzvf /tmp/latest.tar.gz && cp /tmp/wordpress/wp-config-sample.php /tmp/wordpress/wp-config.php
RUN cp -a /tmp/wordpress/. /var/www/html && cd

RUN chown -R www-data:www-data /var/www/
RUN chmod -R 777 /var/www/

ADD --chown=www-data:www-data srcs/nginx_conf /etc/nginx/sites-enabled/default
ADD --chown=www-data:www-data srcs/config.inc.php /usr/share/phpMyAdmin/config.inc.php
ADD --chown=www-data:www-data srcs/wp-config.php /var/www/html/wp-config.php
ADD --chown=www-data:www-data srcs/localhost.cert /etc/nginx/certs/localhost.cert
ADD --chown=www-data:www-data srcs/localhost.key /etc/nginx/certs/localhost.key

CMD service mysql start & service php7.3-fpm start & service nginx start & /bin/bash

