#!/bin/sh

cat << EOF > config.sql
CREATE DATABASE IF NOT EXISTS $DB_NAME;
CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PWD';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$DB_ROOT_PWD';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%' WITH GRANT OPTION;
USE $DB_NAME;
FLUSH PRIVILEGES;
EOF

service mysql start && sleep 2 && mysql < config.sql && service mysql stop && mysqld_safe

# @'localhost' : 로컬 접속만 허용
# @'%' : 외부 접속 허용
# ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PWD';
# service mysql start && sleep 2 && mysql -uroot -p$DB_ROOT_PWD< config.sql && mysqladmin -uroot -p$DB_ROOT_PWD shutdown && mysqld_safe