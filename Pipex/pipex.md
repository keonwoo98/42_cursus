# **Pipex**

>본 프로젝트의 개요와 프로젝트를 진행하기 위한 개념 확립

## **Pipex 허용 함수**

**1. `access`**

프로세스가 지정한 파일이 존재하는지, 읽거나 쓰거나 실행이 가능한지를 확인한다. 만일 지정한 파일이 심볼릭 링크라면 링크의 원본을 확인한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int access(const char *pathname, int mode)`
* 인수 :
    * const char *pathname : 파일이나 디렉토리 전체 이름
    * int mode : 검사할 내용
* 반환 : 가능 또는 파일이 존재할 경우 0, 실패 시 -1 반환

|mode|내용|
|:--|:--|
|R_OK|읽기가 가능?|
|W_OK|쓰기가 가능?|
|X_OK|실행이 가능?|
|F_OK|파일이 존재하는가?|

**2. `open`**

파일을 사용하기 위해 열기(open)한다. `fopen()`은 C 라이브러리에서 제공하는 함수이고 `open()`은 리눅스에서 제공하는 함수이다.
* 헤더 : `#include <fcntl.h>`
* 형식 : `int open (const char *FILENAME, int FLAGS[, mode_t MODE])`
* 인수 :
    * char *FILENAME : 대상 파일 이름
    * int FLAGS : 파일에 대한 열기 옵션
    * [, mode_t MODE] : O_CREAT 옵션 사용에 의해 파일이 생성될 때 지정되는 파일 접근 권한
* 반환값 : 성공 시 fd의 값 (양수), 실패 시 -1 반환

|열기 옵션|설명|
|:--|:--|
|O_RDONLY|읽기 전용으로 열기|
|O_WRONLY|쓰기 전용으로 열기|
|O_RDWR|읽기와 쓰기 모두 가능|
|O_CREAT|해당 파일이 없으면 생성|
|O_EXCL|O_CREAT를 했을 때, 파일이 이미 있어도 열기가 가능하며 쓰기를 하면 이전 내용 사라짐|
||O_CREAT와 O_EXCL를 함께 사용하면, 이미 파일이 있을 때에는 open()이 되지 않아 이전 파일을 보존할 수 있음|
|O_TRUNC|기존의 파일 내용을 모두 삭제|
|O_APPEND|파일을 추가하여 쓰기가 되도록 open 후에 쓰기 포인터가 파일의 끝에 위치하게 됨|

**3. `unlink`**

링크를 삭제한다.

* 헤더 : `#include <unistd.h>`
* 형식 : `int unlink(const char *path)`
* 인수 : 삭제하려는 링크 이름
* 반환 : 성공 시 0, 실패 시 -1 반환

**4. `close`**

`open()` 함수로 열기를 한 파일을 닫는다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int close(int fd)`
* 인수 : 파일 디스크립터
* 반환 : 성공 시 0, 실패 시 -1 반환

**5. `read`**

`open()` 함수로 열기를 한 파일의 내용을 읽는다.
* 헤더 : `#include <unistd.h>`
* 형식 : `ssize_t read(int fd, void *buf, size_t n)`
* 인수 :
    * int fd : 파일 디스크립터
    * void *buf : 파일을 읽어들일 버퍼
    * size_t n : 버퍼의 크기
* 반환 : 성공 시 읽어들인 바이트 수, 실패 시 -1 반환

**6. `write`**

`open()` 함수로 열기를 한 파일에 쓰기를 한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `ssize_t write(int fd, const void *buf, size_t n)`
* 인수 :
    * int fd : 파일 디스크립터
    * void *buf : 파일에 쓰기를 할 내용을 담은 버퍼
    * size_t n : 쓰기할 파이트 수
* 반환 : 성공 시 쓰기한 바이트 수, 실패 시 -1 반환

**7. `malloc`**

메모리를 동적으로 할당받는다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void *malloc(size_t size)`
* 인수 : 필요한 메모리 바이트 크기
* 반환 : `void *` 메모리가 할당된 포인터, 실패 시 NULL 반환

**8. `waitpid`**

`wait()`함수처럼 자식 프로세스가가 종료될 때까지 대기한다. 차이점은 `wait()`함수가 자식 프로세스 중 어느 하나라도 종료되면 대기에서 풀리지만 `waitpid()`는 특정 자식 프로세스가 종료될 때까지 대기한다.
* 헤더 : `#include <sys/wait.h>`
* 형식 : `pid_t waitpid(pid_t pid, int *status, int options)`
* 인수 :
    * pid_t pid : 감시할 자식 프로세스 PID
    * int *status : 자식 프로세스 종료 상태 정보
    * int options : 대기를 위한 옵션
* 반환 :
    * 0 : WNOHANG를 사용했고 자식 프로세스가 종료되지 않았을 때
    * -1 : 실패
    * 자식 프로세스의 PID : 자식 프로세스 종료

**9. `wait`**

자식 프로세스 작업이 끝날 때까지 대기한다.
* 헤더 : `#include <sys/wait.h>`
* 형식 : `pid_t wait(int *status)`
* 인수 : 자식 프로세스 종료 상태 정보
* 반환 : 종료된 자식 프로세스 PID

**10. `free`**

`malloc()` 이나 `calloc()`에서 할당받은 메모리를 시스템에 반환한다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void free(void *ptr)`
* 인수 : 메모리를 해제할 포인터

**11. `pipe`**

파이프를 생성하여 fildes에 파이프에 대한 fd값을 할당한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int pipe(int fildes[2])`
* write end인 fildes[1]에 쓰여진 내용은 read end인 fildes[0]을 통해 읽을 수 있다.
* `dup2`를 이용해서 stdout이 write end를 향하게 하고 stdin이 read end를 향하게 하는 방식으로 파이프 구현 가능하다.

**12. `dup`**

파일 디스크립터 복사본을 만든다. 원본 디스크립터와 복사된 디스크립터의 읽기/쓰기 포인터는 공유된다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int dup(int fildes)`
* 인수 : 파일 디스크립터
* 반환 : 복사된 fd 번호 중 가장 작은 번호가 자동적으로 지정되어 반환, 실패 시 -1 반환

**13. `dup2`**

fd의 파일 서술자를 복사하여 fd2에도 부여한다. (fd가 가리키는 파일을 fd2도 가리키도록)
* 헤더 : `#include <unistd.h>`
* 형식 : `int dup2(int fildes, int fildes2)`
> 참고 : 파일 디스크립터 복사본을 만드는 함수로는 `dup()`와 `dup2()`가 있다. `dup()`는 사용하지 않는 디스크립터 번호 하나가 자동으로 지정되지만 `dup2()`는 원하는 번호를 지정할 수 있다. 지정한 번호가 이미 사용중이면 자동으로 그 파일을 닫고 다시 지정해준다.

**14. `execve`**

execve함수를 호출한 프로세스를 새 프로세스로 바꿔준다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int execve(const char *path, char *const argv[], char *const envp[])`
* 인수 :
    * const char *path : 전체 경로 명
    * char *const argv[] : 인수 목록
    * char *const envp[] : 환경 설정 목록
* 반환 : 실패 시 -1 반환

**15. `fork`**

현재 실행되는 프로세스에 대해 복사본 프로세스를 생성한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `pid_t fork(void)`
* 반환 :
    * -1 : 실패
    * 0 : 자식 프로세스가 0 (새로 생성된 프로세스)
    * 양수 : 생성된 자식 프로세스 PID

**16. `perror`**

전역변수 errno의 현재 값에 대응되는 에러 메시지를 표준에러로 출력해준다. (개행문자 포함)
* 헤더 : `#include <stdio.h>`
* 형식 : `void perror(const char *s)`

**17. `strerror`**

* 헤더 : `#include <string.h>`
* 형식 : `char *strerror(int errnum)`
* 반환 :
    * errnum에 해당하는 스트링을 가리키는 포인터 반환
    * errnum이 식별이 안 되는 경우 "Unknown errer : 인자값"의 스트링 반환

**18. `exit`**

프로세스를 종료한다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void exit(int status)`
* 인수 : `int main()` 함수의 반환값에 해당하는 정수

&nbsp;

## **I/O Redirection**

* **`<`** : input redirection

* **`>`** : output redirection
    * 파일이 존재하지 않을 경우 자동으로 생성되며, 만약 이미 존재할 경우에는 기존 파일에 덮어쓰게 된다.

* **`>>`** : output redirection
    * 이미 파일이 존재하고 덮어쓰는 것이 아니라 기존 컨텐츠에 출력 데이터가 추가한다.

&nbsp;

> 참고 사이트 :
> * https://badayak.com/category/%EC%BB%B4%ED%93%A8%ED%84%B0/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D
> * https://architectophile.tistory.com/10