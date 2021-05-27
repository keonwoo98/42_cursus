# **Born2beRoot**

>본 Subject의 개요와 Virtual Machine과 Debian 개념 잡기

## **Subject**

### **1. Mandatory part**

* 가장 최신 버전의 `CentOS` 또는 `Debian`을 최소한으로 설치 (GUI 금지)
* `SELinux`, `AppArmor`(Debian)는 시작 시 실행되어야 한다.
* 최소한 2개 이상의 `LVM`을 사용한 암호화된 파티션을 생성해야 한다.
*ex)*
![](https://images.velog.io/images/dogfootbirdfoot/post/b2c925a0-5e4f-4be5-bd1d-bf289276df8f/Screen%20Shot%202021-05-27%20at%201.14.46%20PM.png)

* Defense 시에 선택한 운영체제에 대한 질문을 받을텐데 `aptitude`와 `apt`의 차이점, `SELinux`와 `AppArmor`가 무엇인지 등을 설명할 수 있어야 한다.
* `SSH` 서비스는 4242 포트만 사용해야하며 이러한 이유로 `SSH`를 `root`로 연결할 수 없어야 한다?
* Defense 시 `SSH`로 새 계정을 세팅해야하기 때문에 `SSH`가 어떻게 작동하는지 이해하고 있어야 한다.
* `UFW` 방화벽을 이용해야하기 때문에 4242 포트만 열어놔야 한다.
* Virtual machine을 실행할 때 방화벽이 활성화 되어 있어야 한다. CentOS의 경우 기본 방화벽 대신 `UFW`를 사용해야 한다. (설치하려면 아마 `DNF`가 필요할 듯)
* Virtual machine의 hostname은 42로 끝나야 한다. *ex) keokim42*
* 강력한 암호 정책을 구현해야 한다. (sudo 설치 및 사용)
* root user 외에도 username으로 로그인한 user가 있어야 한다? (이 사용자는 user42와 sudo groups에 속해있어야 함)
* Defense 시에 새로운 사용자를 생성하고 그룹에 등록해야 한다.
* 강력한 비밀번호 정책
    * 비밀번호는 30일마다 만료되어야 한다.
    * 비밀번호 수정 전까지 허용되는 최소 일수는 2로 설정해야 한다.
    * 사용자는 비밀번호 만료 7일 전에 경고 메시지를 받아야 한다.
    * 비밀번호는 10자 이상이어야하고 대문자와 숫자를 포함해야 한다. 또한 3개 이상의 연속된 동일한 문자를 포함해서는 안된다.
    * 비밀번호에 사용자이름이 포함되서는 안된다.
    * 이전 비밀번호와 최소 7자 이상 달라야 한다.
    * 물론 root 비밀번호는 이 정책을 준수해야 한다.
    * configuration file 세팅 후 root 계정 포함 가상 머신의 모든 계정의 비밀번호를 변경해야 한다.
* sudo group에 대한 강력한 구성을 설정하기 위한 준수 사항
    * sudo를 사용한 인증 시 비밀번호 시도는 3번으로 제한한다.
    * sudo 사용 시에 비밀번호 오류가 발생한 경우 사용자가 지정한 메시지(custom message)가 표시되어야 한다.
    * sudo를 사용하는 작업들은 inputs과 outputs 모두를 보관(archived)해야 한다. 로그파일은 `/var/log/sudo`폴더에 저장되어야 한다.
    * 보안상의 이유로 `TTY`모드를 활성화해야 한다.
    * 보안상의 이유로 sudo에서 사용할 수 있는 경로를 제한해야 한다.
    * *ex) /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin*
* 마지막으로 `monitoring.sh`라는 간단한 스크립트를 만들어야 하는데 bash에서 만들어야 한다.
* 서버 시작 시 스크립트는 10분마다 모든 터미널에 대한 아래 정보들을 표시한다. (배너는 옵션, 에러가 보이면 안됨)
    * OS의 architecture 및 kernel version
    * physical(물리적) processors 개수
    * virtual(가상) processors 개수
    * 서버에서 사용 가능한 RAM 및 사용률(%)
    * 서버에서 사용 가능한 메모리 및 사용률(%)
    * processors 사용률(%)
    * 마지막 재부팅 날짜 및 시간
    * LVM 활성화 여부
    * 작동중인 연결 개수
    * 서버를 사용하고 있는 이용자 수
    * 서버의 IPv4와 MAC주소
    * sudo 프로그램으로 실행된 명령의 수
* Defense 시 스크립트의 내용이 어떻게 작동하는지 설명할 수 있어야 한다. 또한 수정하지 않고 일시 정지할 수 있어야 한다.

*스크립트 작동 예제*
![](https://images.velog.io/images/dogfootbirdfoot/post/da334009-b9f9-4c9b-a5e1-633e39ecb494/Screen%20Shot%202021-05-27%20at%201.14.30%20PM.png)

*주제의 일부 요구 사항을 확인하는 데 사용할 수 있는 두 가지 명령*

*CentOS :*
![](https://images.velog.io/images/dogfootbirdfoot/post/eff86a0c-dca6-4b50-8524-5b6662f662d6/Screen%20Shot%202021-05-27%20at%201.14.18%20PM.png)

*Debian :*
![](https://images.velog.io/images/dogfootbirdfoot/post/30cefc97-af80-4bde-a1f9-120e70e4ec00/Screen%20Shot%202021-05-27%20at%201.14.08%20PM.png)

### **2. Bonus part**

* 파티션 설정을 통해 아래와 같은 구조를 갖는다 :
![](https://images.velog.io/images/dogfootbirdfoot/post/ee300aed-00a1-45c3-8b6e-c30687f03cd2/Screen%20Shot%202021-05-27%20at%201.13.50%20PM.png)

* `lighttpd`, `MariaDB`, `PHP` 서비스를 사용하여 기능적인 `WordPress` 웹 사이트를 설정한다.
* 유용하다고 생각되는 서비스를 선택적으로 설정한다. (`NGINX` / `Apache2` 제외) Defense 시 선택을 정당화할 수 있어야 한다.
* Bonus part를 수행하기 위해 추가적으로 서비스를 설정할 수 있다. 이 경우 필요에 맞게 포트를 더 열 수 있다. 물론 `UFW` 규칙에 따라야 한다.