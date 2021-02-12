FROM alpine:latest

EXPOSE 80 443

RUN apk update && apk upgrade

RUN apk add nginx unzip
RUN adduser -D www
RUN mkdir -p /run/nginx

RUN apk add php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php-mysqli php7-fpm php7-session php7-mbstring

RUN mkdir -p /usr/share && mkdir -p /var/www

RUN wget -q https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.zip\
    && unzip phpMyAdmin-5.0.4-all-languages.zip && rm phpMyAdmin-5.0.4-all-languages.zip
RUN mv phpMyAdmin-5.0.4-all-languages /usr/share/phpmyadmin
RUN ln -s /usr/share/phpmyadmin/ var/www/phpmyadmin
RUN ln -s /usr/share/phpmyadmin/ var/lib/phpmyadmin

RUN mkdir /usr/share/phpmyadmin/tmp

ADD ./data/localhost.cert /localhost.cert
ADD ./data/localhost.key /localhost.key
ADD ./data/nginx.conf /etc/nginx/nginx.conf
ADD ./data/config.inc.php /usr/share/phpmyadmin/
ADD ./data/php-fpm.conf /etc/php7/php-fpm.conf

RUN chown -R www:www /usr/share/phpmyadmin
RUN chmod -R 777 /usr/share/phpmyadmin/tmp

CMD php-fpm7 -F & nginx && tail -f /dev/null
