FROM debian:buster

# /etc/nginx/sites-available/ft_server
# /usr/share/phpmyadmin/config.inc.php
# /etc/nginx/conf.d/phpMyAdmin.conf

#install everything
RUN sudo apt-get update \
    && sudo apt-get -y upgrade \
#nginx
    && sudo apt-get -y install ufw nginx gnupg \
    && sudo ufw allow 'Nginx Full' \
#MySQL
    && cd /tmp && wget https://dev.mysql.com/get/mysql-apt-config_0.8.13-1_all.deb \
    && sudo dpkg -i mysql-apt-config* && cd \
#PHP
    && apt-get -y install default-mysql-server php-fpm php-mysql php-mbstring php-zip php-gd\
#Configure nginx for PHP
    && sudo mkdir /var/www/ft_server && sudo rm -rf /var/www/html \
    && sudo chown -R root:root /var/www/ft_server \
    && sudo ln -s /etc/nginx/sites-available/ft_server /etc/nginx/sites-enabled/ \
    && rm -rf /etc/nginx/sites-enabled/default \
    && sudo nginx -t && sudo systemctl reload nginx \
#Install PHPMyAdmin
    && wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz \
    && tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz \
    && sudo mv phpMyAdmin-4.9.0.1-all-languages/ /usr/share/phpmyadmin \
#Configure PHPMyAdmin
    && sudo mkdir -p /var/lib/phpmyadmin/tmp \
    && sudo chown -R www-data:www-data /var/lib/phpmyadmin \
    && sudo cp /usr/share/phpmyadmin/config.sample.inc.php /usr/share/phpmyadmin/config.inc.php

sudo ln -s /usr/share/phpmyadmin

##db?
# sudo mariadb < /usr/share/phpmyadmin/sql/create_tables.sql
# sudo mariadb < GRANT SELECT, INSERT, UPDATE, DELETE ON phpmyadmin.* TO 'pma'@'localhost' IDENTIFIED BY '';
#