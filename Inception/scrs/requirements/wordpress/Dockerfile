FROM debian:buster

RUN apt-get update
RUN apt-get upgrade
RUN apt-get install -y wget php-fpm php-mysql php-mbstring

COPY ./tools/create_wordpress.sh /usr/local/bin/
ENTRYPOINT ["create_wordpress.sh"]

WORKDIR /var/www/html/

EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.3", "-F"]
