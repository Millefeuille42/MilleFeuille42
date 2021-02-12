CREATE USER 'wp_user'@'localhost' IDENTIFIED by 'password';
CREATE USER 'wp_user'@'%' IDENTIFIED by 'password';

CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;

GRANT ALL ON wordpress.* TO 'wp_user'@'localhost' IDENTIFIED BY 'password';
GRANT ALL ON wordpress.* TO 'wp_user'@'%' IDENTIFIED BY 'password';

FLUSH PRIVILEGES;
