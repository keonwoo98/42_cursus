#!/bin/bash

if [ ! -f /etc/ssl/certs/nginx.crt ]; then
echo "Nginx: setting up ssl...";
# 개인키 및 인증서 생성
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
# req : 인증서 요청 및 인증서 생성 유틸
# -newkey : 개인키를 성성하기 위한 옵션
# rsa:4096 : rsa 방식을 이용해 개인키와 인증서 요청을 새로 만듦 (4096 bit 사이즈의 키 생성)
# -day 365 : 인증서의 유효기간을 작성하는 옵션
# -nodes : 비밀번호 입력받지 않기 (암호화하지 않기)
# -x509 : 인증서 요청 대신 self signed 인증서 생성
# -subj : 인증서에 필요한 정보를 미리 전달해서 입력 대기하지 않기
# -keyout <키 파일 이름> : 키 파일 이름을 지정해 키 파일 생성
# -out <인증서 이름> : 인증서 이름을 지정해 인증서 생성
echo "Nginx: ssl is set up!";
fi

exec "$@"

# self-signed SSL 인증서 생성
# HTTPS(Hypertext Transfer Protocol over Secure Socket Layer)는 SSL위에서 돌아가는 HTTP의 평문 전송 대신 암호화된 통신을 하는 프로토콜이다.
# 이런 HTTPS를 통신을 서버에서 구현하기 위해서는 신뢰할 수 있는 상위 기업이 발급한 인증서가 필요한데
# 이런 발급 기관을 CA(Certificate Authority)라고 한다. CA의 인증서를 발급받는 것은 무료가 아니다.
# self-signed SSL 인증서는 자체적으로 발급받은 인증서이며, 로그인 및 기타 개인 계정 인증 정보를 암호화한다.
# self-signed SSL 인증서를 만드는 방법 중 하나는 무료 오픈소스인 openssl을 이용해 만드는 것이다.
# HTTPS를 위해 필요한 개인키(.key), 서면요청파일(.csr), 인증서파일(.crt)을 openssl이 발급해준다.
