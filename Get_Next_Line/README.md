# **Get Next Line**
>Get Next Line의 개요와 프로젝트를 진행하기 위한 개념 확립

## **개요**

### **1. 프로젝트의 목적**

이 프로젝트는 파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수를 코드화 하는 것이다.

### **2. 주요 지침 사항**

* 본 프로젝트는 정적 변수를 배울 수 있도록 도울 것이다.
* `get_next_line` 함수를 반복문 안에서 호출하면, 파일 디스크립터에 존재하는 텍스트를 EOF 전까지 한 번에 한 줄씩 읽어들인다.
* 컴파일 방식 : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
* read 함수를 사용할 때에는, 파일 또는 표준 입력으로부터 값을 읽어들이기 위해 컴파일 시에 정의되는 BUFFER_SIZE를 사용해야 한다.
* read 함수를 사용할 때에는, 파일 또는 표준 입력으로부터 값을 읽어들이기 위해 컴파일 시에 정의되는 BUFFER_SIZE를 사용해야 한다.
* lseek은 허용된 함수가 아니다. 파일 읽기는 오로지 한번만 행해져야 한다.
* 전역 변수는 금지되어 있다.
* 하나의 정적변수로 get_next_line 성공하기 `(Bonus)`
* get_next_line을 사용하여 여러 개의 파일 디스크립터를 관리할 수 있는 것 `(Bonus)`

## **선행 지식**

### **1. 파일 디스크립터(fd)**

파일 디스크립터(File Descriptor)란 리눅스 혹은 유닉스 계열의 시스템에서 프로세스(process)가 파일(file)을 다룰 때 사용하는 개념으로, 프로세스에서 특정 파일에 접근할 때 사용하는 추상적인 값이다. 파일 디스크럽터는 일반적으로 0이 아닌 정수값을 갖는다. 

흔히 유닉스 시스템에서 모든 것을 파일이라고 한다. 일반적인 정규파일부터 디렉토리, 소켓, 파이프, 블록 디바이스, 케릭터 디바이스 등 모든 객체들을 파일로 관리한다. 유닉스 시스템에서 프로세스가 이 파일들을 접근할 때 파일 디스크립터라는 개념일 이용한다. 프로세스가 실행 중에 파일을 Open하면 커널은 해당 프로세스의 파일 디스크립터 숫자 중 사용하지 않는 가장 작은 값을 할당해준다. 그 다음 프로세스가 열려있는 파일에 시스템 콜을 이용해서 접근할 때, 파일 디스크립터(FD)값을 이용해서 파일을 지칭할 수 있다.

프로그램이 프로세스로 메모리에서 실행될 때, 기본적으로 할당되는 파일디스크립터는 표준입력(Standard Input), 표준 출력(Standard Output), 표준에러(Standard Error)이며 이들에게 각각 0, 1, 2라는 정수가 할당된다. (unistd.h 헤더파일에 명시)

Fd의 최대값은 `OPEN_MAX`라는 값이다. 즉, 하나의 프로세스 당 최대 OPEN_MAX개의 파일을 열 수 있다. OPEN_MAX는 단일 프로그램에 허용되는 최대 열린 파일 수를 정의하는 상수다. Unix 시스템에서 C언어의 OPEN_MAX는 `limits.h`에 정의되어있다.

### **2. gcc -D 옵션**

* -D{macro_name} : 매크로를 외부에서 define할 때 사용한다. 이는 디버깅에서 많이 쓰인다.
* -D{macro_name}={value} : `#define macro name`한 것과 동일한 결과를 나타낸다.

아래에서는 `BUFFER_SIZE`를 컴파일할 때 정하게 된다 :

`gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c`

### **3. read 함수**

* 함수 원형 : `ssize_t read(int fd, void *buf, size_t nbytes)`
    * fd : 데이터를 전송해주는 대상을 가리키는 파일 디스크립터
    * buf : 수신한 데이터를 주는 대상을 가리키는 포인터
    * nbytes : 수신할 바이트 수
* 반환 값 : 성공 시 수신한 바이트 수, 실패시 -1
* open(2), creat(2), socket(2), accept(2) 등으로 생성한 file descriptor로 부터 데이터를 읽는다.
* 파일을 읽으면 읽은 size만큼 파일의 다음 읽을 위치가 이동된다.
* 읽을 위치가 파일의 끝에 도달하면 더 이상 읽을 데이터가 없으므로 0을 반환한다.

> *참고*  
> - *size_t : unsigned int*  
> - *ssize_t : signed int (반환값으로 IO 함수의 실패 여부 알려줌)*

### **4. 정적(static) 변수**

정적으로 할당되는 변수이며, 프로그램 실행 전반에 걸쳐 변수의 수명이 유지된다.

기억 장소가 콜 스택에서 할당 및 할당 해제되는, 수명이 더 짧은 자동 변수(지역 변수가 일반적으로 자동임)와는 반대되는 개념이다. 즉, 기억 장소가 힙 메모리에 동적 할당되는 객체와 반의어이다. 정적 메모리 할당은 일반적으로 관련 프로그램을 실행하기 앞서 컴파일 시간에 메모리를 할당하는 것을 일컬으며 이는 메모리가 런타임 중에 필요할 때 할당되는 동적 메모리 할당이나 자동 메모리 할당과는 다르다.

데이터 영역에 저장되어 프로그램 종료 시까지 남아있기 때문에, 다음 line을 읽을 시작 주소을 계속 저장할 수 있도록(line마다 따로 저장할 때 함수가 끝나도 날아가지 않도록) 버퍼를 static 변수로 선언해야 한다.

>참고 사이트 :
>* https://twofootdog.tistory.com/51
>* https://velog.io/@hidaehyunlee/GetNextLine-%EC%82%BD%EC%A7%88%EC%9D%98-%EA%B8%B0%EB%A1%9D
>* https://ko.wikipedia.org/wiki/%EC%A0%95%EC%A0%81_%EB%B3%80%EC%88%98