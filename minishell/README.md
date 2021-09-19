# minishell

 > contributor : keokim, minjkim2
### **Commit Rule**

- 가능한 작은 단위로 Commit 할 것
- 실행 가능한 상태 일 것.

### **Commit Message Rule**
- Type - 내용 의 형식으로 작성할 것.
- Add : 파일 , 폴더 추가
- Feat : 새로운 기능 추가
- Remove : 필요 없는 코드, 기능 제거
- Refactor : 변수, 함수 이름 수정, 코드 최적화
- Docs : 문서 파일 수정
- Fix : Norm, bug 수정
- etc : 기타 업무

#### ***redirection***
- redirection 뒤에는 << 제외하고 file이 와야한다.
- redirection >, <, >> 다음엔 무엇인가 있어야 한다.
- redirection 뒤에 인자로 directory가 들어올떄는 < 의 경우를 제외하면 error
- redirection >, <, >>, << 뒤에 ( < , > , << , >> , | , ' ')이 들어올시 error
- redirection << 뒤에 문자열이 없으면 syntax error (metacharacter 제외)
- \>, >> 는 파일이 존재하지 않으면 만든다.
#### ***pipe***
- pipe 뒤에는 command (metacharacter는 오면 안된다.)
