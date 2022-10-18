#!/bin/sh

wp core downloaded --local=nl_NL --allow-root

sleep 2

chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*

wp config create --dbname=$DB_NAME --dbuser=$WP_ADMIN_USER --dbpass=$WP_ADMIN_PWD --dbhost=$DB_HOST  --dbcharset="utf8" --dbcollate="utf8_general_ci"  --allow-root

wp core install --url=url_example.com --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --dbhost=$DB_HOST  --allow-root

exec php-fpm7.3 -F
