FROM debian:buster

RUN apt-get update && apt-get upgrade && apt-get install -y mariadb-server mariadb-client

EXPOSE 3306

COPY ./tools/create_db.sh /usr/local/bin/
COPY ./conf/wordpress.sql /usr/local/bin/
ENTRYPOINT [ "create_db.sh" ]

CMD ["mysqld"]
