# **minishell**

## **1. `SIGNAL`이란?**

`Signal`은 유닉스, 유닉스 계열, POSIX 호환 운영체제에 쓰이는 제한된 형태의 프로세스 간 통신이다. 프로세스나 동일 프로세스 내의 특정 스레드로 전달되는 비동기식 통보인 것이다.

프로세스가 시그널을 받게 되면 :
1. 시그널에 해당되는 기본 동작을 하거나
2. 그 시그널을 무시하거나
3. 사용자가 정의한 함수를 통해 동작 방식을 바꿀 수 있다.

&nbsp;

## **2. `SIGNAL` 보내기**

실행 중인 프로세스의 제어 터미널에서 특정 키 조합을 입력하면 시스템이 특정 신호를 보낸다.

**`ctrl+c`**

* `INT` 신호 (`SIGINT`)를 내보낸다.
* 기본적으로 프로세스를 종료하는 역할을 한다.

**`ctrl+z`**

* `TSTP` 신호 (`SIGTSTP`)를 내보낸다.
* 기본적으로 프로세스가 실행을 유예시키는 역할을 한다.

**`ctrl+\`**

* `QUIT` 신호 (`SIGQUIT`)를 내보낸다.
* 기본적으로 프로세스를 종료시킨 뒤 코어를 덤프하는 역할을 한다.

**`ctrl+t`**

* `INFO` 신호 (`SIGINFO`)를 내보낸다.
* 명령에서 지원하는 경우 기본적으로 운영 체제가 실행 중인 명령에 대한 정보를 표시한다.
* 모든 종류의 유닉스에서 지원하지는 않는다.

> 현대 운영체제에서 이러한 기본 키 조합들은 `stty` 명령으로 변경할 수 있다.

&nbsp;

## **3. `SIGNAL` 종류**

**`SIGHUP`**

* 터미널과 연결이 끊겼을 때 발생
* 기본적으로 프로세스가 종료된다.
* 이식 가능 번호 : 1

**`SIGINT`**

* 인터럽트가 발생했을 때 발생
* 기본적으로 프로세스가 종료된다.
* 이식 가능 번호 : 2
* 키보드로부터 입력받은 인터럽트 시그널 (`ctrl_c`)

> 인터럽트란?
> * CPU로 하여금 현재 진행중인 프로그램 처리를 중단하고 다른 프로그램을 처리하도록 요구하는 매커니즘.
> * 외부 장치와 상호작용을 위해 반드시 필요하다.

**`SIGQUIT`**

* 터미널 종료 신호
* 코어덤프를 남기고 종료된다.
* 이식 가능 번호 : 3
* 키보드에서 입력받은 실행 중지 시그널 (`ctrl+\`)

**`SIGKILL`**

* 프로세스를 무조건 종료
* 절대 무시할 수 없으며 제어할 수 없다.
* 이식 가능 번호 : 9

**`SIGSEGV`**

* 프로세스가 잘못된 메로리를 참조했을 때 발생
* 코어덤프를 남기고 종료된다.
* 이식 가능 번호 : 11

**`SIGSTOP`**

* 프로세스 중단
* 종료된 상태가 아니며 제어할 수 없다.
* 이식 가능 번호 : 17
* 실행 정지 후 다시 실행을 위해 계속하기 위해 대기시키는 시그널 (`ctrl+z`)

> **`ctrl+d`**
> * `EOF`를 의미 
> * 시그널이 아니다.
> * stdin pipe를 닫는다. (`read(STDIN) return 0`)

> 리눅스 상에서 `kill -l` 명령어를 입력하면 모든 시그널의 종류를 알 수 있다.

&nbsp;

## **3. `SIGNAL` 성질**

**비신뢰성**

* 시그널을 보내면 그 시그널이 제대로 도착했는지, 잘 전달되었는지 확인하지 않는다.
* 때문에 신뢰성이 낮다.

**대기하지 않음**

* 만약 시그널 처리 함수를 시그널 처리하고 있는데 그 사이에 다시 시그널을 주게 되면 그 시그널을 무시된다.

&nbsp;

## **4. 예제**

프로세스를 직접 생성해서 시그널을 주는 예시 :

```c
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("give signal...\n");
	sleep(30);
	exit(0);
}
```

위 코드를 컴파일 후 실행하면 30초간 프로그램이 실행될 것이다.

이 상태에서 `ctrl+c`를 누르게 되면 `SIGINT` 신호를 보내게 된다. 기본동작은 종료이므로 프로세스가 종료하게 된다.

또는 `kill -시그널번호 프로세스 id`를 통해서 시그널을 보낼 수도 있다. 즉, `SIGINT`를 보내려면 `kill -2 pid` 또는 `kill -SIGINT pid`를 통해서 `SIGINT`를 보낼 수 있다.

우리는 이 시그널을 제어하고 싶다. 그래서 리눅스는 `signal` 핸들러를 제공한다.

&nbsp;

## **5. `signal` 함수**

형식 : `void (*signal(int signum, void (*handler)(int)))(int);`

첫 번째 인자 `signum`은 시그널을 발생시키는 번호이다. (`SIGINT`는 2번이었다.)

아니면 매크로를 쓸 수도 있다. `SIGINT`가 그대로 매크로에 정의되어 있다.

두 번째 인자 `handler`라는 함수 포인터에 함수를 인자로 주게 됨녀 시그널을 받았을 때 그 함수가 호출된다.

`SIGINT` 예시 :

```c
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void interruptHandler(int sig)
{
	printf("this program will be exited in 3 seconds...\n");
	sleep(3);
	exit(0);
}

int main()
{
	signal(SIGINT, interruptHandler);
	printf("input ctrl+c\n");
	while (1);
}
```

컴파일 후 실행하고 `ctrl+c`를 입력하면 메세지와 함께 3초 후 프로그램이 종료된다.

`SIGSTOP` 예시 :

```c
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void stopHandler(int sig)
{
	printf("this program will be exited in 3 seconds...\n");
	sleep(3);
	exit(0);
}

int main()
{
	signal(SIGSTOP, stopHandler);
	printf("input ctrl+z\n");
	while (1);
}
```

`ctrl+z`를 입력하여 `SIGSTOP`을 보내면 그냥 멈춰버린다. 핸들링되지 않는 것이다. `SIGKILL`과 `SIGSTOP`은 사용자가 절대 제어할 수 없다. 어떤 이유로 인해 프로세스를 무조건 죽여야하는 경우가 있다고 해보자. 만약 좀비프로세스를 계속해서 생성하는 프로세스가 있는데 이 프로세스를 죽이지 못하면 안된다. 그래서 2개는 핸들링을 하지 못하는 것이다.

또한 핸들러에 전달인자 `sig`는 시그널의 종류를 나타낸다.

그렇기 때문에 시그널의 종류에 따라 처리할 수 있다 :

```c
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signalHandler(int sig)
{
	if (sig==SIGINT)
	{
		printf("this program will stop in 3 seconds...\n");
		sleep(3);
		exit(0);
	}
	if (sig==SIGQUIT)
	{
		printf("signal SIGQUIT\n");
	}
}

int main()
{
	signal(SIGINT, signalHandler);
	signal(SIGQUIT, signalHandler);
	printf("input ctrl+c or ctrl+\\ \n");
	while (1);
}
```

프로그램을 실행하여 `ctrl+\`를 입력해서 `SIGQUIT`신호를 보내도 종료하지 않고, `SIGINT`를 보냈을 때 3초안에 종료된다.

&nbsp;

> 참고 사이트 :
> * https://reakwon.tistory.com/46