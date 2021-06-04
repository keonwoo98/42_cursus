#!/bin/sh

echo -n "#Architecture : " && uname -a
echo -n "#CPU physical : " && nproc
echo -n "#vCPU : " && cat /proc/cpuinfo | grep processor | wc -l

free -h | grep Mem | awk '{printf("#Memory Usage: %d"), $3}'
free -h | grep Mem | awk '{printf("/%dMB "), $2}'
free -t | grep Mem | awk '{printf("(%.2f%%)\n"), $3/$2*100}'

df -h | grep root | awk '{printf("#Disk Usage: %d"), $3}'
df -h | grep root | awk '{printf("/%dGb "), $4}'
df -h | grep root | awk '{printf("(%d%%)\n"), $5}'

# 세미콜론(;) : 하나의 명령어 라인에서 여러 개의 명령을 실행(하나의 명령어 다음에 추가)

# 파이프(|) : 앞에서 나온 명령 결과를 두 번째 명령에서 사용

# 더블 엠퍼센드(&&) : 첫 번째 명령이 에러 없이 정상적으로 종료했을 경우에만 두 번째 명령을 수행

# 더블 버티컬바(||) : 첫 번째 명령의 결과에서 에러가 발생하더라도 각각의 모든 명령을 수행

# $cat /proc/cpuinfo : Ubuntu Linux에서 Server의 CPU 정보를 확인 할 수 있다

# nproc : User당 사용할 수 있는 process 개수

# echo :  운영체제에서 문자열을 컴퓨터 터미널에 출력하는 명령어 
# 		-n : 마지막에 따라오는 개행 문자를 출력하지 않음

# uname : 시스템의 정보 확인
# 		-a : 시스템의 모든 정보를 출력 (—all)
# 		-s : 커널명 출력
# 		-v : 커널 버전 정보 출력

# grep : 원하는 문자열이 들어간 행을 찾아 출력

# free : 메모리의 전체적인 현황을 출력
# 		-h : 사람이 읽기 편한 단위로 출력(human-readable)
# 		-t : 합계가 계산된 total 칼럼 줄을 추가로 출력

# awk : 파일로부터 레코드(record)를 선택하고, 선택된 레코드에 포함된 값을 조작하거나 데이터화하는 것을 목적으로 사용하는 프로그램

# df : 리눅스 시스템 전체의 디스크 사용량(파일 시스템, 디스크 크기, 사용량, 여유공간, 사용률, 마운트 지점 순으로) 출력
# 		-h : 사람이 읽기 편한 단위로 출력