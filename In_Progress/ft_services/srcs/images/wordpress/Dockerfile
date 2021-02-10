FROM alpine:latest

EXPOSE 80 443

RUN apk update && apk upgrade

RUN apk add nginx
RUN adduser -D www
RUN mkdir -p /run/nginx

RUN apk add php7-common php7-iconv php7-json php7-gd php7-curl \
php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql \
php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap \
php7-ctype php7-dom php-mysqli php7-fpm php7-session

RUN mkdir -p /usr/share && mkdir -p /var/www

RUN wget http://wordpress.org/latest.tar.gz && tar -xvzf latest.tar.gz \
&& rm latest.tar.gz && mv wordpress /usr/share/wordpress

RUN ln -s /usr/share/wordpress /var/www/wordpress

ADD --chown=www:www ./data/localhost.cert /localhost.cert
ADD --chown=www:www ./data/localhost.key /localhost.key
ADD --chown=www:www ./data/nginx.conf /etc/nginx/nginx.conf
ADD --chown=www:www ./data/wp-config.php /var/www/wordpress/wp-config.php


RUN chown -R www:www /usr/share/wordpress
RUN chmod -R 777 /etc/nginx && chmod -R 777 /usr/share/wordpress


CMD php-fpm7 -F & nginx && tail -f /dev/null
