#!/bin/sh

if [ -f ./wordpress/wp-config.php ]
then
	echo "wordpress already downloaded"
else
	wget https://wordpress.org/lastest.tar.gz
	tar -xzvf lastest.tar.gz
	rm -rf lastest.tar.gz

	rm -rf /etc/php/7.3/fpm/pool.d/www.conf
	mv ./www.conf /etc/php/7.3/fpm/pool.d

	cd /var/www/html/wordpress
	sed -i "s/username_here/$DB_USER/g" wp-config-sample.php
	sed -i "s/password_here/$DB_PWD/g" wp-config-sample.php
	sed -i "s/localhost/$DB_HOST/g" wp-config-sample.php
	sed -i "s/database_name_here/$DB_NAME/g" wp-config-sample.php
	mv wp-config-sample.php wp-config.php
fi

exec "$@"
