FROM debian:buster

RUN apt-get update && apt-get upgrade && \
    apt-get install -y mariadb-server mariadb-client && \
    rm -rf /var/lib/apt/lists/*

# RUN sed -i "s/127.0.0.1/0.0.0.0/g" /etc/mysql/mariadb.conf.d/50-server.conf && \
RUN mkdir -p tools && \
    chown mysql:mysql /var/lib/mysql

EXPOSE 3306

COPY ./tools/create_db.sh .
RUN chmod +x create_db.sh
ENTRYPOINT [ "create_db.sh" ]
