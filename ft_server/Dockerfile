FROM debian:buster
MAINTAINER mlabouri@student.42.fr

EXPOSE 80
ENV DEBIAN_FRONTEND=noninteractive

# /var/www/nginx_conf/phpmyadminconfig.inc.php
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
ADD --chown=root srcs/nginx_conf /etc/nginx/sites-enabled/default
RUN echo "<?php \n phpinfo();" >> /var/www/html/index.php

    #Install PHPMyAdmin
RUN wget -q https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
RUN mv phpMyAdmin-4.9.0.1-all-languages/ /var/www/html/phpmyadmin/

    #Configure PHPMyAdmin
RUN mkdir -p /var/lib/phpmyadmin/tmp
RUN chown -R www-data:www-data /var/lib/phpmyadmin && chown -R www-data:www-data /var/www/html/phpmyadmin/
RUN cp /var/www/html/phpmyadmin/config.sample.inc.php /var/www/html/phpmyadmin/config.inc.php

CMD service nginx start; echo "IP : $(hostname -I)"; while [ 1 ]; do sleep 2; done