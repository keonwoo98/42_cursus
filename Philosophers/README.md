# **Philosophers**

> 본 프로젝트의 개요와 프로젝트를 진행하기 위한 개념 확립

## **프로젝트 소개**

`식사하는 철학자(Dining philosophers problem)`는 운영체제 강의에서 전통적으로 흔히 소개되는 운영체제의 교착(Deadlock)상태를 설명하기 위한 문제로 1965년 에츠허르 다익스트라(Edsger Wybe Dijkstra)가 만든 문제이다.

![](https://images.velog.io/images/dogfootbirdfoot/post/126372e4-5c99-4115-aff4-4854d2758c17/philosophers.png)

예를 들어, n명의 철학자가 원탁에 앉아서 식사를 하고 있다. 철학자들 사이에는 포크가 하나씩 놓여 있고, 철학자들은 다음의 과정을 통해 식사를 한다.

* 철학자는 다음과 같은 세 행동을 반복한다 : 먹기 ➔ 잠자기 ➔ 생각하기
* 식사를 할 때는 양쪽의 포크를 모두 사용하여야 한다.
* 양쪽의 포크를 모두 들었다면 일정 시간동안 식사를 한다.
* 식사를 마쳤다면 포크를 내려놓는다.
* 한 명의 철학자도 일정 시간 식사를 하지 못하여 사망하면 안된다.

만약 모든 철학자가 동시에 배가 고파서 왼쪽 젓가락을 집어든다면 오른쪽 젓가락은 이미 자신의 우측에 앉은 철학자가 집어들었을 것이므로, 모두가 영원히 오른쪽 젓가락을 들지 못하게 된다. 즉, 더 이상 진행하지 못하고 철학자들은 영원히 대기 상태에 머물러 있다. 이런 현상을 교착상태(Deadlock)라고 한다. 한번 교착상태에 빠진 철학자들은 계속 고뇌만 하다가 기아현상(Starvation)으로 굶어 죽는다.

해당 과제는 이 문제점을 `뮤텍스(Mutex)` 또는 `세마포어(Semaphore)`를 활용해 해결하는 프로그램을 구현하는 것이다.

&nbsp;

## **허용 함수**

### **Mandatory**

**`memset`**

`malloc()`이나 `calloc()`에서 할당 받은 메모리를 특정 값으로 초기화한다. 보통 어떤 작업을 하기 전에 `NULL`로 초기화할 때 많이 사용한다.
* 헤더 : `#include <string.h>`
* 형식 : `void *memset(void *s, int c, size_t n)`
* 인자 :
	* `void *s` : 초기화하고자 하는 메모리 시작 주소
	* `int c` : 초기화 값
	* `size_t size` : 초기화 크기
* 반환 : 성공 시 `void *s`에 대한 포인터 반환, 실패 시 NULL 반환

**`printf`**

C언어의 표준 출력 함수로, 여러 중류의 data를 다양한 서식에 맞춰 출력할 수 있게 해준다.
* 헤더 : `#include <stdio.h>`
* 형식 : `int printf(const char *format, ...)`
* 인자 : %[플래그(flag)][폭(width)][.정밀도][크기(length)]서식 문자(specifier)
* 반환 : 성공 시 출력된 전체 문자의 개수, 실패 시 음수 반환

**`malloc`**

메모리를 동적으로 할당받는다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void *malloc(size_t size)`
* 인자 : 필요한 메모리 바이트 크기
* 반환 : 성공 시`void *` 메모리가 할당된 포인터, 실패 시 NULL 반환

**`free`**

`malloc()` 이나 `calloc()`에서 할당받은 메모리를 시스템에 반환한다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void free(void *ptr)`
* 인자 : 메모리를 해제할 포인터

**`write`**

`open()` 함수로 열기를 한 파일에 쓰기를 한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `ssize_t write(int fd, const void *buf, size_t n)`
* 인자 :
    * `int fd` : 파일 디스크립터
    * `void *buf` : 파일에 쓰기를 할 내용을 담은 버퍼
    * `size_t n` : 쓰기할 파이트 수
* 반환 : 성공 시 쓰기한 바이트 수, 실패 시 -1 반환

**`usleep`**

지정한 마이크로 초 동안 대기 상태 유지
* 헤더 : `#include <unistd.h>`
* 형식 : `int usleep(useconds_t microseconds)`
* 인자 : 대기 마이크로 초
* 반환 :
	* -1 : 실패 (errno 설정)
	* 0 : 성공

> 밀리 초 : 1/1000초  
> 마이크로 초 : 1/1000000초  
> `useconds_t` : [0, 1000000] 범위의 정수를 담을 수 있는 부호 없는 정수 타입

**`gettimeofday`**

**`pthread_create`**

**`pthread_detach`**

**`pthread_join`**

**`pthread_mutex_init`**

**`pthread_mutex_destroy`**

**`pthread_mutex_lock`**

**`pthread_mutex_unlock`**

### **Bonus**

**`fork`**

현재 실행되는 프로세스에 대해 복사본 프로세스를 생성한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `pid_t fork(void)`
* 반환 :
    * -1 : 실패
    * 0 : 자식 프로세스가 0 (새로 생성된 프로세스)
    * 양수 : 생성된 자식 프로세스 PID

**`kill`**

쉘에서 프로세스를 죽이는 kill명령과는 다르게 프로세스에 시그널을 전송한다.
프로세스에 SIGKILL을 보내면 쉘 명령의 kill과 같은 역할을 한다.
* 헤더 : `#include <signal.h>`
* 형식 : `int kill(pid_t pid, int sig)`
* 인자 :
  * `pid_t pid` : process id
  * `int sig` : 시그널 번호
* 반환값 : 성공시 0, 실패시 -1

|pid|의미|
|:---:|:---:|
|양수|지정한 process id에만 시그널 전송|
|0|함수를 호출하는 프로세스와 같은 그룹에 있는 모든 프로세스에 시그널 전송|
|-1|함수를 호출하는 프로세스가 전송할 수 있는 권한을 가진 모든 프로세스에 시그널 전송|
|음수|첫번째 pid의 절대값 프로세스 그룹에 속하는 모든 프로세스에 시그널 전송|

**`exit`**

프로세스를 종료한다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void exit(int status)`
* 인자 : `int main()` 함수의 반환값에 해당하는 정수

**`waitpid`**

`wait()`함수처럼 자식 프로세스가가 종료될 때까지 대기한다. 차이점은 `wait()`함수가 자식 프로세스 중 어느 하나라도 종료되면 대기에서 풀리지만 `waitpid()`는 특정 자식 프로세스가 종료될 때까지 대기한다.
* 헤더 : `#include <sys/wait.h>`
* 형식 : `pid_t waitpid(pid_t pid, int *status, int options)`
* 인자 :
    * `pid_t pid` : 감시할 자식 프로세스 PID
    * `int *status` : 자식 프로세스 종료 상태 정보
    * `int options` : 대기를 위한 옵션
* 반환 :
    * 0 : WNOHANG를 사용했고 자식 프로세스가 종료되지 않았을 때
    * -1 : 실패
    * 자식 프로세스의 PID : 자식 프로세스 종료

**`sem_open`**

**`sem_close`**

**`sem_post`**

**`sem_wait`**

**`sem_unlink`**

&nbsp;

## **규칙**