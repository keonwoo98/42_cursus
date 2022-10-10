-- 데이터베이스 생성
CREATE DATABASE wordpress;
-- 내부에서만 접속 가능한 keokim 사용자 생성, 비밀번호 keokim
CREATE USER 'keokim'@'localhost' IDENTIFIED BY 'keokim';
-- keokim@localhost에게 wordpress 데이터베이스의 모든 테이블에 대한 모든 권한 부여
GRANT ALL PRIVILEGES ON wordpress.* TO 'keokim'@'localhost' WITH GRANT OPTION;
-- 데이터베이스 선택
USE wordpress
exit
