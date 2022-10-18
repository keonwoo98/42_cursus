FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade && apt-get -y install nginx openssl

EXPOSE 443

COPY ./conf/nginx.conf /etc/nginx/sites-enabled/default
COPY ./tools/nginx_start.sh /var/www

RUN chmod +x /var/www/nginx_start.sh && ln -sf /deb/stdout /var/log/access.log

ENTRYPOINT [ "var/www/nginx_start.sh" ]

CMD ["nginx", "-g", "daemon off;"]

# ENTRYPOINT [ "tail", "-f", "/dev/null" ]

# FROM : Docker Base Image (기반이 되는 이미지, <이미지 이름>:<태그> 형식으로 설정)
# MAINTAINER : 메인테이너 정보 (작성자 정보)
# RUN : Shell Script 또는 명령을 실행
# CMD : 컨테이너가 실행되었을 때 명령이 실행
# LABEL : 라벨 작성 (docker inspect 명령으로 label 확인할 수 있습니다.)
# EXPOSE : 호스트와 연결할 포트 번호를 설정
# ENV : 환경변수 설정
# ADD : 파일 / 디렉터리 추가
# COPY : 파일 복사
# ENTRYPOINT : 컨테이너가 시작되었을 때 스크립트 실행
# VOLUME : 볼륨 마운트
# USER : 명령 실행할 사용자 권한 지정
# WORKDIR : "RUN", "CMD", "ENTRYPOINT" 명령이 실행될 작업 디렉터리
# ARG : Dockerfile 내부 변수
# ONBUILD : 다른 이미지의 Base Image로 쓰이는 경우 실행될 명령 수행
# SHELL : Default Shell 지정
