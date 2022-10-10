FROM debian:buster

RUN apt-get update && apt-get upgrade && apt-get install -y wget php-fpm php-mysql php-mbstring

COPY ./tools/create_wordpress.sh /usr/local/bin/
ENTRYPOINT ["create_wordpress.sh"]

WORKDIR /var/www/html/

EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.3", "-F"]

# CGI( Common Gateway Interface )는 웹서버와 외부 프로토콜을 연결시켜주는 표준 프로토콜이다.
# CGI는 각각의 요청별로 프로세스를 생성하기 때문에 요청 때마다 생성과 삭제를 반복해야해서 속도가 느리다.
# CGI의 단점을 개선한 FastCGI는 이미 기존에 만들어진 프로세스를 바탕으로 새로운 요청들을 처리해 나간다.
# 프로세스의 생성과 삭제를 통해 발생하는 부하를 줄이기 위한 FastCGI를 활용하기 위해 사용되어지는 것이 php-fpm이다.
# php가 FastCGI 모드에서 동작하여 처리될 수 있도록 해준다.
