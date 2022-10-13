#!/bin/sh

cat << EOF > config.sql
CREATE DATABASE IF NOT EXISTS $DB_NAME;
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$DB_ROOT_PWD';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_PWD';
FLUSH PRIVILEGES;
EOF

service mysql start && sleep 2 && mysql < config.sql && service mysql stop && mysqld_safe

# @'localhost' : 로컬 접속만 허용
# @'%' : 외부 접속 허용
