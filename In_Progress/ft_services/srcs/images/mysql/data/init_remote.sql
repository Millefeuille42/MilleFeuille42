CREATE USER 'remote'@'localhost' IDENTIFIED BY 'password';
CREATE USER 'remote'@'%' IDENTIFIED BY 'password';

GRANT ALL ON *.* TO 'remote'@'localhost';
GRANT ALL ON *.* TO 'remote'@'%';
