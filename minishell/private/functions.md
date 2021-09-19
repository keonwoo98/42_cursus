# **minishell**

## **minishell 허용 함수**

**`readline`**

prompt를 출력하고 사용자로부터 한줄의 문자를 입력받고 리턴한다. `readline()` 리턴값은 `malloc()`에 의해 할당되어 있다. 반드시 `free()`해야함.
* 헤더 : `#include <readline/readline.h>`
* 형식 : `char *readline (char *prompt)`
* 인수 :
  * char *prompt : 출력할 메세지(prompt)
* 반환값 : 개행을 제거한 문자열을 리턴, `EOF`를 만날시 `(char *)NULL` 리턴
* ex : char *line = readline ("Enter a line : ")

**`rl_on_new_line`**

Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.
* 헤더 : `#include <readline/readline.h>`
* 형식 : `int rl_on_new_line (void)`

**`rl_replace_line`**

Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.
* 헤더 : `#include <readline/readline.h>`
* 형식 : `void rl_replace_line (const char *text, int clear_undo)`

**`rl_redisplay`**

If non-zero, Readline will call indirectly through this pointer to update the display with the current contents of the editing buffer. By default, it is set to rl_redisplay, the default Readline redisplay function (see section 2.4.6 Redisplay).
* 헤더 : `#include <realine/readline.h>`
* 형식 : `void rl_redisplay(void)`
  

**`add_history`**

Place string at the end of the history list. The associated data field (if any) is set to NULL. If the maximum number of history entries has been set using stifle_history(), and the new number of history entries would exceed that maximum, the oldest history entry is removed.
string을 history list의 맨끝에 위치시킨다. 관련된 데이터 필드는 NULL로 셋팅된다. history 항목이 최대 개수를 넘을  경우, 오래된 항목들은 삭제된다.
* 헤더 : `#include <readline/history.h>`
* 형식 : `add_history(const char *string)`

**`wait3`**

자식 프로세스가 종료되는 것을 기다리며, 종료된 프로세스의 상태와 자원 사용량을 알려주는 함수.
* 헤더 : `#include <sys/wait.h>`
* 형식 : `pid_t wait3(int *statloc, int options, struct rusage *rusage)`
* 인자 :
  * statloc : 자식 프로세스의 종료 상태를 나타내는 정보를 담는다.
  * options : 프로세스의 종료 상태 체크 시 옵션을 걸 수 있다.
  * rusage : 자식 프로세스의 리소스 사용량에 대한 정보가 담긴다.
* 반환값 : 성공시 Process ID, 실패시 -1, WNOHANG 옵션으로 실행되고, 자식 프로세스가 아직 종료되지 않았으면 0 return

**`wait4`**

* 형식 : `pid_t wait4(pid_t pid, int *statloc, int options, struct rusage *rusage)`
* 인자 : 
  * pid : pid에 해당하는 프로세스만 기다린다.

stactloc에 사용가능한 매크로
|macro|내용|
|:---:|:---:|
|WIFEXITED(status)|자식 프로세스가 정상적으로 종료된 경우 true|
|WEXITESTATUS(status)|exit()의 인자에서 하위 8비트 값을 리턴|
|WIFSIGNALED(status)|자식 프로세스가 시그널을 받아 비정상적으로 종료된 경우 true|
|WIFTERMSIG(status)|시그널 번호를 리턴|
|WIFCOREDUMP(status)|코어 파일이 생성된 경우 true|
|WIFSTOPPED(status)|현재 중지 상태이면 true|
|WSTOPSIG(status)|실행을 중단시킨 시그널 번호를 리턴|
|WIFCONTINUED(status)|작업 제어 중지 이후 실행이 재개되었으면 true|

options
|option|내용|
|---|---|
|WCONTINUED|중지되었다가 실행을 재개한 이후 상태가 아직 보고되지 않은 자식도 리턴|
|WNOHANG|종료 상태를 즉시 회수 할 수 없는 상황이라고 하여도 waitpid() 호출이 차단되지 않고 0 리턴|
|WUNTRACED|중지되었으나 그 상태가 아직 보고되지 않은 자식도 리턴|

**`signal`**

시그널 처리를 설정한다.
* 헤더 : `#include <signal.h>`
* 형식 : `void (*signal(int sig, void (*func)(int)))(int)`
* 인자 :
  * int sig : 시그널 번호
  * void (*func)(int) : 시그널을 처리할 핸들러
* 반환값 : void *()(int) 이전에 설정된 시그널 핸들러

시그널을 처리하는 방법
|유형|의미|
|:---:|:---:|
|SIG_DFL|기존 방법을 따른다.|
|SIG_IGN|시그널을 무시한다.|
|함수 이름|시그널이 발생하면 지정된 함수 호출|

**`kill`**

쉘에서 프로세스를 죽이는 kill명령과는 다르게 프로세스에 시그널을 전송한다.
프로세스에 SIGKILL을 보내면 쉘 명령의 kill과 같은 역할을 한다.
* 헤더 : `#include <signal.h>`
* 형식 : `int kill(pid_t pid, int sig)`
* 인자 :
  * pid_t pid : process id
  * int sig : 시그널 번호
* 반환값 : 성공시 0, 실패시 -1

|pid|의미|
|:---:|:---:|
|양수|지정한 process id에만 시그널 전송|
|0|함수를 호출하는 프로세스와 같은 그룹에 있는 모든 프로세스에 시그널 전송|
|-1|함수를 호출하는 프로세스가 전송할 수 있는 권한을 가진 모든 프로세스에 시그널 전송|
|음수|첫번째 pid의 절대값 프로세스 그룹에 속하는 모든 프로세스에 시그널 전송|

**`getcwd`**

현재 작업중인 디렉토리의 절대 경로를 buf에 복사하고 buf의 포인터를 리턴한다.
buf가 NULL이면 공백이 할당되고, size는 무시된다.
버퍼가 작으면 에러가 발생할 수 있으므로 크게 잡는다.

* 헤더 : `#include <unistd.h>`
* 형식 : `char *getcwd(char *buf, size_t size)`
* 인자 :
  * char *buf : 작업 디렉토리 문자열을 담을 버퍼
  * size_t size : 버퍼의 크기
* 반환값 : 성공시 현재 작업 디렉토리를, 실패시 NULL 포인터를 리턴, errno설정.

**`chdir`**

현재 작업 디렉토리를 변경한다. (change directory)
디렉토리의 실행 권한이 있어야한다. path의 시작이 '\'이면 안된다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int chdir(const char *path)`
* 인자 :
  * const char *path : 경로
* 반환값 : 성공시 0, 실패시 -1 리턴, errno에 저장.

**`stat`**

파일의 크기, 권한, 생성일시, 최종 변경일등 파일의 상태나 정보를 얻는 함수. symbolic link인 파일을 path 로 넘기면 그 원본 파일의 정보를 얻는다. `lstat` 함수는 symbolic link 파일 자신의 정보를 얻는다.

* 헤더 : `#include <sys/stat.h>`
* 형식 : `int stat(const char *path, struct stat *buf)`
* 인자 :
  * const char *path : 파일명 또는 파일에 대한 상대 / 절대 경로
  * buf : 파일의 상태 및 정보를 저장할 buf 구조체<br>
구조체 정보 : https://www.it-note.kr/173
* 반환값 : 성공시 0, 실패시 -1 리턴, errno에 저장.

**`lstat`**

stat함수와 동작하는 기능이 같다.
symbolic link인 파일을 path로 넘기면 symbolic link인 파일 자체의 정보를 얻는다.
* 형식 : `int lstat(const char *path, struct stat * buf)`

**`fstat`**

열려진 파일의 크기, 파일의 권한, 파일의 생성일시, 최종 변경일 등 파일의 상태나 파일의 정보를 얻는 함수.
* 형식 : `int fstat(int fd, struct stat *buf)`
* 인자 :
  * fd : open 등으로 생성한 file descriptor
  * buf : 파일의 상태 및 정보를 저장할 buf 구조체
* 리턴값 : 성공시 0, 실패시 -1 리턴, errno에 저장


**`open`**

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

**`unlink`**

링크를 삭제한다.

* 헤더 : `#include <unistd.h>`
* 형식 : `int unlink(const char *path)`
* 인수 : 삭제하려는 링크 이름
* 반환 : 성공 시 0, 실패 시 -1 반환

**`close`**

`open()` 함수로 열기를 한 파일을 닫는다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int close(int fd)`
* 인수 : 파일 디스크립터
* 반환 : 성공 시 0, 실패 시 -1 반환

**`read`**

`open()` 함수로 열기를 한 파일의 내용을 읽는다.
* 헤더 : `#include <unistd.h>`
* 형식 : `ssize_t read(int fd, void *buf, size_t n)`
* 인수 :
    * int fd : 파일 디스크립터
    * void *buf : 파일을 읽어들일 버퍼
    * size_t n : 버퍼의 크기
* 반환 : 성공 시 읽어들인 바이트 수, 실패 시 -1 반환

**`write`**

`open()` 함수로 열기를 한 파일에 쓰기를 한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `ssize_t write(int fd, const void *buf, size_t n)`
* 인수 :
    * int fd : 파일 디스크립터
    * void *buf : 파일에 쓰기를 할 내용을 담은 버퍼
    * size_t n : 쓰기할 파이트 수
* 반환 : 성공 시 쓰기한 바이트 수, 실패 시 -1 반환

**`malloc`**

메모리를 동적으로 할당받는다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void *malloc(size_t size)`
* 인수 : 필요한 메모리 바이트 크기
* 반환 : `void *` 메모리가 할당된 포인터, 실패 시 NULL 반환

**`waitpid`**

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

**`wait`**

자식 프로세스 작업이 끝날 때까지 대기한다.
* 헤더 : `#include <sys/wait.h>`
* 형식 : `pid_t wait(int *status)`
* 인수 : 자식 프로세스 종료 상태 정보
* 반환 : 종료된 자식 프로세스 PID

**`free`**

`malloc()` 이나 `calloc()`에서 할당받은 메모리를 시스템에 반환한다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void free(void *ptr)`
* 인수 : 메모리를 해제할 포인터

**`pipe`**

파이프를 생성하여 fildes에 파이프에 대한 fd값을 할당한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int pipe(int fildes[2])`
* write end인 fildes[1]에 쓰여진 내용은 read end인 fildes[0]을 통해 읽을 수 있다.
* `dup2`를 이용해서 stdout이 write end를 향하게 하고 stdin이 read end를 향하게 하는 방식으로 파이프 구현 가능하다.

**`dup`**

파일 디스크립터 복사본을 만든다. 원본 디스크립터와 복사된 디스크립터의 읽기/쓰기 포인터는 공유된다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int dup(int fildes)`
* 인수 : 파일 디스크립터
* 반환 : 복사된 fd 번호 중 가장 작은 번호가 자동적으로 지정되어 반환, 실패 시 -1 반환

**`dup2`**

fd의 파일 서술자를 복사하여 fd2에도 부여한다. (fd가 가리키는 파일을 fd2도 가리키도록)
* 헤더 : `#include <unistd.h>`
* 형식 : `int dup2(int fildes, int fildes2)`
> 참고 : 파일 디스크립터 복사본을 만드는 함수로는 `dup()`와 `dup2()`가 있다. `dup()`는 사용하지 않는 디스크립터 번호 하나가 자동으로 지정되지만 `dup2()`는 원하는 번호를 지정할 수 있다. 지정한 번호가 이미 사용중이면 자동으로 그 파일을 닫고 다시 지정해준다.

**`execve`**

execve함수를 호출한 프로세스를 새 프로세스로 바꿔준다.
* 헤더 : `#include <unistd.h>`
* 형식 : `int execve(const char *path, char *const argv[], char *const envp[])`
* 인수 :
    * const char *path : 전체 경로 명
    * char *const argv[] : 인수 목록
    * char *const envp[] : 환경 설정 목록
* 반환 : 실패 시 -1 반환

**`fork`**

현재 실행되는 프로세스에 대해 복사본 프로세스를 생성한다.
* 헤더 : `#include <unistd.h>`
* 형식 : `pid_t fork(void)`
* 반환 :
    * -1 : 실패
    * 0 : 자식 프로세스가 0 (새로 생성된 프로세스)
    * 양수 : 생성된 자식 프로세스 PID

**`strerror`**

* 헤더 : `#include <string.h>`
* 형식 : `char *strerror(int errnum)`
* 반환 :
    * errnum에 해당하는 스트링을 가리키는 포인터 반환
    * errnum이 식별이 안 되는 경우 "Unknown errer : 인자값"의 스트링 반환

**`errno`**

* 헤더 : `#include <sys/errno.h>`
* 형식 : `extern int errno`
* 반환 : 마지막으로 발생한 에러 번호

**`exit`**

프로세스를 종료한다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `void exit(int status)`
* 인수 : `int main()` 함수의 반환값에 해당하는 정수

**`opendir`**

지정한 디렉토리 열기
특정 디렉토리 안에 있는 파일과 디렉토리를 검색하기 위해 사용한다.
* 헤더 : `#include <dirent.h>`
* 형식 : `DIR *opendir(const char *filename)`
* 인수 : 열기 대상 디렉토리
* 반환 :
    * DIR 포인터 : 성공
    * NULL : 실패

**`readdir`**

`opendir()`로 연 디렉토리에 대해, 그 안에 있는 모든 파일과 디텍토리 정보를 구한다.
* 헤더 : `#include <dirent.h>`
* 형식 : `struct dirent *readdir(DIR *dirp)`
* 인수 : 열기한 디렉토리 정보
* 반환 :
    * 파일 또는 디렉토리 정보 : 성공
    * NULL : 실패

**`closedir`**

`opendir()`로 연 디렉토리를 닫는다.
* 헤더 : `#include <dirent.h>`
* 형식 : `int closedir(DIR *dirp)`
* 인수 : 열기한 디렉토리 정보
* 반환 :
    * 0 : 성공
    * -1 : 실패

**`isatty`**

`fd`에 대하여 유효한 단말 타입 디바이스를 참조하고 있는지 판단
* 헤더 : `#include <unistd.h>`
* 형식 : `int isatty(int fd)`
* 반환 :
    * 1 : 성공
    * 0 : 실패(errno에 오류 값 설정)

**`ttyname`**

`isatty`함수로 유효한 디바이스를 발견한 경우 디바이스 이름을 반환
* 헤더 : `#include <unistd.h>`
* 형식 : `char *ttyname(int fd)`
* 반환 :
    * null로 끝나는 디바이스 이름
    * NULL : 실패

**`ttyslot`**

디바이스 파일 발견 시 그 유니크 번호 반환
* 헤더 : `#include <unistd.h>`
* 형식 : `int ttyslot(void)`
* 반환 :
    * 번호
    * 0 : 실패

**`ioctl`**

하드웨어의 제어와 상태 정보를 얻기 위한 함수
* 헤더 : `#include <sys/ioctl.h>`
* 형식 : `int ioctl(int fd, unsigned long request, ...)`
* 인수 :
    * int fd : `open`한 디바이스의 fd값
    * unsigned long request : 디바이스에게 전달할 명령

**`getenv`**

환경 변수 목록 중에 원하는 변수값을 구한다.
* 헤더 : `#include <stdlib.h>`
* 형식 : `char *getenv(const char *name)`
* 인수 : 구하려는 환경 변수 이름
* 반환 : char* 형 환경 변수 값

**`tcgetattr`**

터미널 파일 fd에 대한 터미널 속성을 termios_p에 저장
* 헤더 : `#include <termios.h>`
* 형식 : `int tcgetattr(int fd, struct termios *termios_p)`
* 인수 :
    * const struct termios *termios_p : 터미널 속성을 저장할 주소
* 반환 :
    * 0 : 성공
    * -1 : 실패 (errno에 오류 값 설정)

**`tcsetattr`**

터미널 파일 fd에 대한 터미널 속성을 설정
* 헤더 : `#include <termios.h>`
* 형식 : `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p)`
* 인수 :
    * int optional_actions이 갖을 수 있는 값 :
        * TCSANOW : 속성을 바로 변경
        * TCSADRAIN : 송신을 완료한 후 변경
        * TCSAFLUSH : 송수신 완료한 후 변경
    * const struct termios *termios_p : 터미널 속성을 저장할 주소
* 반환 :
    * 0 : 성공
    * -1 : 실패 (errno에 오류 값 설정)

**`tgetent`**

단말명의 입력을 `bp`의 버퍼에 추출한다.
* 헤더 :
    * `#include <curses.h>`
    * `#include <term.h>`
* 형식 : `int tgetent(char *bp, const char *name)`
* 인수 :
    * char *bp : size 1024의 char형 버퍼가 아니면 안되며 거기에 계속되어 함수 `tgetnum()`, `tgetflga()`, `tgetstr()` 등의 호출을 해도 보관 유지된다.
    * const char *name : 단말명
* 반환 :
    * 1 : 성공
    * 0 : 해당 항목(단말명) 없음
    * -1 : database를 찾을 수 없음

**`tgetflag`**

`id`가 단말 엔트리에 존재하는지에 대한 boolean 정보
* 헤더 :
    * `#include <curses.h>`
    * `#include <term.h>`
* 형식 : `int tgetflag(char *id)`
* 반환 :
    * 1 : 존재
    * 0 : 존재하지 않음

**`tgetnum`**

`id`가 단말 엔트리에 존재하는지에 대한 numeric 정보
* 헤더 :
    * `#include <curses.h>`
    * `#include <term.h>`
* 형식 : `int tgetnum(char *id)`
* 반환 :
    * 양수 : numeric 정보
    * -1 : 존재하지 않음

**`tgetstr`**

`id`가 단말 엔트리에 존재하는지에 대한 string 정보
* 헤더 :
    * `#include <curses.h>`
    * `#include <term.h>`
* 형식 : `char *tgetstr(char *id, char **area)`
* 반환 :
    * 문자열 포인터 : string 정보 (char **area 에도 저장됨)
    * NULL : 존재하지 않음

**`tgoto`**

매개변수를 지정된 기능으로 인스턴스화한다. 반환값은 `tputs`함수로 전달된다.
* 헤더 :
    * `#include <curses.h>`
    * `#include <term.h>`
* 형식 : `char *tgoto(const char *cap, int col, int row)`

**`tputs`**

`tgetstr`에서 반환된 문자열 출력
* 헤더 :
    * `#include <curses.h>`
    * `#include <term.h>`
* 형식 : `int tputs(const char *str, int affcnt, int (*putc)(int))`
* 반환 : `tgetstr`에서 반환된 문자열


&nbsp;

## **I/O Redirection**

* **`<`** : input redirection
    * 키보드로 연결된 표준 입력 방향을 파일로 변경한다.

* **`<<`** : input redirection
    * 구분자로 입력된 단어를 만날때 까지 입력을 받는다. 

* **`>`** : output redirection
    * 파일이 존재하지 않을 경우 자동으로 생성되며, 만약 이미 존재할 경우에는 기존 파일에 덮어쓰게 된다.

* **`>>`** : output redirection
    * 이미 파일이 존재하고 덮어쓰는 것이 아니라 기존 컨텐츠에 출력 데이터가 추가한다.

&nbsp;

## **File descriptor**

|구분|장치|fd|
|:--:|:--:|:--:|
|표준 입력|키보드|0|
|표준 출력|모니터|1|
|표준 에러|모니터|2|