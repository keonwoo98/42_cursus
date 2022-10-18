FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade && \
    apt-get -y install mariadb-server && \
    rm -rf /var/lib/apt/lists/*

RUN sed -i "s/127.0.0.1/0.0.0.0/g" /etc/mysql/mariadb.conf.d/50-server.cnf
# RUN mkdir -p tools && chown mysql:mysql /var/lib/mysql

WORKDIR /tools

EXPOSE 3306

RUN chmod +x ./tools/create_db.sh

ENTRYPOINT [ "./tools/create_db.sh" ]
