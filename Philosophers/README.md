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

> * 밀리 초 : 1/1000초  
> * 마이크로 초 : 1/1000000초  
> * `useconds_t` : [0, 1000000] 범위의 정수를 담을 수 있는 부호 없는 정수 타입

**`gettimeofday`**

Jan. 1, 1970 이후 경과된 seconds와 microseconds를 구하는 함수
* 헤더 : `#include <sys/time.h>`
* 형식 : `int gettimeofday(struct timeval *restrict tp, void *restrict tzp)`
* 인자 :
	
    * `struct timeval *restrict tp` : Jan. 1, 1970 이후 경과된 seconds와 microseconds를 저장할 buffer
	
    * `void *restrict tzp` : 사용하지 않으므로 NULL로 초기화
* 반환 :
	
    * -1 : 실패 (errno 설정)
	
    * 0 : 성공

```c
struct timeval
{
	time_t			tv_sec;		// seconds since Jan. 1, 1970
	suseconds_t		tv_usec;	// and microseconds
}
```

**`pthread_create`**

쓰레드 생성
* 헤더 : `#include <pthread.h>`
* 형식 : `pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)`
* 인자 :
	
    * `pthread_t *thread` : 쓰레드가 성공적으로 생성되었을때 생성된 쓰레드를 식별하기 위해서 사용되는 쓰레드 식별자
	
    * `const pthread_attr_t *attr` : 쓰레드 특성을 지정하기 위해서 사용하며, 기본 쓰레드 특성을 이용하고자 할 경우에 NULL을 사용
	
    * `void *(*start_routine)(void *)` : 분기시켜서 실행할 쓰레드 함수
	
    * `void *arg` : 위 start_routine 쓰레드 함수의 매겨변수로 넘겨짐
* 반환 : 성공 시 0 반환, 실패 시 errno 설정

**`pthread_detach`**

특정 쓰레드를 분리시킨다.  
일반적으로 `pthread_create()`를 사용하여 쓰레드를 생성하면, 쓰레드가 종료되더라도 사용했던 모든 자원이 해제되지 않는다. 반면 `pthread_join()`을 사용하여 종료될때까지 기다렸다가 종료시점이 되면, 자원이 반납된다. `pthread_deach()` 함수는 `pthread_join()`을 사용하지 않더라도, 쓰레드 종료 시 모든 자원을 해제한다.
* 헤더 : `#include <pthread.h>`
* 형식 : `int pthread_detach(pthread_t thread)`
* 인자 : 분리시킬 쓰레드 식별자
* 반환 : 성공 시 0 반환, 실패 시 errno 설정

**`pthread_join`**

특정 쓰레드가 종료하기를 기다린다.  
join된 쓰레드(종료된 쓰레드)는 모든 자원을 반납한다.
* 헤더 : `#include <pthread.h>`
* 형식 : `int pthread_join(pthread_t thread, void **value_ptr)`
* 인자 :
	
    * `pthread_t thread` : 기다릴 쓰레드 식별자
	
    * `void **value_ptr` : 쓰레드의 리턴값
* 반환 : 성공 시 0 반환, 실패 시 errno 설정

**`pthread_mutex_init`**

뮤텍스 생성
* 헤더 : `#include <pthread.h>`
* 형식 : `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)`
* 인자 :
	
    * `pthread_mutex_t *mutex` : 뮤텍스가 성공적으로 생성되었을때 생성된 뮤텍스를 식별하기 위해서 사용되는 뮤텍스 식별자
	
    * `const pthread_mutexattr_t *attr` : 뮤텍스 특성을 지정하기 위해서 사용하며, 기본 뮤텍스 특성을 이용하고자 할 경우에 NULL을 사용
	
    > 뮤텍스 특성에는 `fast`, `recurisev`, `error checking`이 있으며 디폴트로 `fast`가 사용된다.

* 반환 : 성공 시 0 반환, 실패 시 errno 설정

> 뮤텍스는 여러 개의 쓰레드가 공유하는 데이터를 보호하기 위해서 사용되는 도구로써, 보호하고자 하는 데이터를 다루는 코드 영역을 단지 `한번에 하나의 쓰레드만` 실행 가능하도록 하는 방법으로 공유되는 데이터를 보호한다. 이러한 코드영역(하나의 쓰레드만 점유 가능한)을 `critical section`(임계 구역)이라고 하며, 뮤텍스 관련 API를 이용해서 관리할 수 있다.

**`pthread_mutex_destroy`**

할당된 뮤텍스를 해제(반납)한다.
* 헤더 : `#include <pthread.h>`
* 형식 : `int pthread_mutex_destroy(pthread_mutex_t *mutex)`
* 인자 : 해제할 뮤텍스
* 반환 : 성공 시 0 반환, 실패 시 errno 설정

**`pthread_mutex_lock`**

(critical section 시작)  
뮤텍스를 잠근다. 이미 잠겨 있으면 호출 쓰레드는 뮤텍스를 사용할 수 있을 때까지 차단된다.
* 헤더 : `#include <pthread.h>`
* 형식 : `int pthread_mutex_lock(pthread_mutex_t *mutex)`
* 인자 : lock할 뮤텍스
* 반환 : 성공 시 0 반환, 실패 시 errno 설정

**`pthread_mutex_unlock`**

(critical section 종료)  
뮤텍스가 잠겨있으면 잠금 해제한다. 호출 쓰레드가 보유하지 않은 뮤텍스일시 정의되지 않은 동작이 발생한다.
* 헤더 : `#include <pthread.h>`
* 형식 : `int pthread_mutex_unlock(pthread_mutex_t *mutex)`
* 인자 : unlock할 뮤텍스
* 반환 : 성공 시 0 반환, 실패 시 errno 설정

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
* 반환 : 성공시 0, 실패시 -1

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

세마포어를 초기화하고 여는 함수
* 헤더 : `#include <semaphore.h>`
* 형식 : `sem_t *sem_open(const char *name, int oflag, ...)`
* 인자 :
	
    * `const char *name` : 세마포어 이름 지정
	
    * `int oflag` : `O_CREAT` / `O_EXCL`
* 반환 : 성공 시 세마포어 주소 반환, 실패 시 `SEM_FAILED` 반환 및 errno 설정
* name으로 이름이 지정된 세마포어는 oflag에 지정된대로 초기화되어 생성되고 세마포어 설명자가 호출 프로세스로 반환된다.
* 이름이 `/`로 시작하면, 세마포어는 `/dev/sem/`폴더에 생성된다. (`/dev/sem/name`)
* 이름이 `/`로 시작하지 않으면, 세마포어는 `/dev/sem/현재폴더/` 폴더에 생성된다. (`/dev/sem/현재폴더/name`)
* 이 세마포어는 `sem_close()` 등을 호출하여 세마포어를 닫기 전까지 사용할 수 있다.

|oflag|내용|
|:--|:--|
|O_CREAT|존재하지 않는 경우 세마포어를 생성한다. 이 flag는 추가적으로 2개의 인수를 필요로 한다. `mode_t mode`와 `unsigned형 value`이다. 세마포어는 `value`의 값을 초기값으로 생성한다. `value`는 0보다 큰 양수여야 한다. unlock된 세마포어의 수를 의미한다. 이 값은 `SEM_VALUE_MAX`를 초과할 수 없다.|
|O_EXCL|만일 `O_EXCL`와 `O_CREAT`이 설정되었고 세마포어 이름이 존재한다면 `sem_open()`함수는 실행에 실패한다. 만일 `O_EXCL`은 설정되었고 `O_CREAT`가 설정되지 않은 경우에는 함수 실행에 대한 결과가 정의되지 않는다.|
|이외의 flag|함수 실행 결과는 정의되지 않는다.|


**`sem_close`**

세마포어를 종료한다.  
프로세스가 세마포어를 사용하도록 시스템이 할당한 자원을 전부 할당 해제한다.
* 헤더 : `#include <semaphore.h>`
* 형식 : `int sem_close(sem_t *sem)`
* 인자 : 종료할 세마포어
* 반환 : 성공 시 0 반환, 실패시 -1 반환 후 errno 설정

**`sem_post`**

세마포어의 잠금이 해제되고 세마포어 값이 증가하며 세마포어를 기다리고 있는 모든 쓰레드가 깨어난다.
* 헤더 : `#include <semaphore.h>`
* 형식 : `int sem_post(sem_t *sem)`
* 인자 : 잠금을 해제할 세마포어
* 반환 : 성공 시 0 반환, 실패시 -1 반환 후 errno 설정

**`sem_wait`**

세마포어를 잠근다.  
만일 현재의 세마포어 값이 0이라면, 호출하는 스레드는 세마포어를 잠그거나 시그널에 의해서 호출이 중단되기 전까지 `sem_wait()`으로부터 돌아오지 않는다. 성공적으로 실행되면 `sem_post()`로 잠금을 해제하기 전까지 잠금상태를 유지한다.
* 헤더 : `#include <semaphore.h>`
* 형식 : `int sem_wait(sem_t *sem)`
* 인자 : 잠궈야 할 세마포어
* 반환 : 성공 시 0 반환, 실패시 -1 반환 후 errno 설정

**`sem_unlink`**

이름이 명명된 세마포어를 제거한다.  
현재 name으로 명명된 세마포어가 어떤 프로세스에 의해 참조되고 있다면, 이 함수는 해당 세마포어에 영향을 미치지 않는다. 만약 하나 이상의 프로세스가 이 함수를 호출했을 때, 해당 세마포어를 열고 있다면 모든 참조되고 있는 세마포어가 `sem_close()` 등에 의해 종료될 때까지 세마포어의 제거는 연기된다.
* 헤더 : `#include <semaphore.h>`
* 형식 : `int sem_unlink(const char *name)`
* 인자 : 제거해야 할 세마포어 이름
* 반환 : 성공 시 0 반환, 실패시 -1 반환 후 errno 설정

&nbsp;

> 참고 사이트
> * https://bitsoul.tistory.com/category/C
> * https://velog.io/@jongeun/Philosophers-Day-05