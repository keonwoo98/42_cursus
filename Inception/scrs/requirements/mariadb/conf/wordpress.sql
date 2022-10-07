CREATE DATABASE wordpress;
CREATE USER 'keokim'@'localhost' IDENTIFIED BY 'keokim';
GRANT ALL PRIVILEGES ON wordpress.* TO 'keokim'@'localhost' WITH GRANT OPTION;
USE wordpress
exit
