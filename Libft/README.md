# Libft
>흔히 쓰이는 함수들을 재편성한 C 라이브러리 구현

## Part 1 - Libc functions

man에 정의되어 있는 대로 libc 함수들의 구성을 다시 구현합니다. 함수들은 원본과 같은 형식의 프로토타입을 선언하고 함수 이름 앞에는 `ft_`를 붙입니다. 함수의 프로토타입의 일부는 `restrict` 한정자를 사용합니다. 이 키워드는 c99 표준의 일부분입니다. 그러므로 이 키워드를 프로토타입에 포함시키는 것과 -std=c99 플리그를 사용하여 컴파일 하는 것은 금지됩니다.

|함수명|프로토타입|man 설명|
|:--|:--|:--|
|memset|`void *ft_memset(void *b, int c, size_t len)`|배열 b를 입력받아 len의 길이만큼 문자 c로 초기화하는 함수|
|bzero|`void ft_bzero(void *s, size_t n)`|문자열 s를 입력받아 문자열 s의 요소들을 n의 길이만큼 0으로 초기화하는 함수 <span style="color:red">*(n이 0이면 아무것도 하지 않음)*</span>|
|memcpy|`void *ft_memcpy(void *dst, const void *scr, size_t n)`|배열 src의 내용을 n길이만큼 배열 dst에 복사하는 함수 <span style="color:red">*(dst와 src가 겹치면 정의되지 않은 행동 발생; 그럴 시엔 memmove(3) 사용)*</span>|
|memccpy|`void *ft_memccpy(void *dst, const void *src, int c, size_t n)`|배열 src의 내용을 n의 길이만큼 배열 dst에 복사하되 문자 c를 만나게되면 복사를 중단하고 배열 dst에서 문자 c 다음 인덱스의 주소를 반환하는 함수 <span style="color:red">*(dst와 src가 겹치면 정의되지 않은 행동 발생)*</span>|
|memmove|`void *ft_memmove(void *dst, const void *src, size_t len)`|배열 src의 내용을 n의 길이만큼 배열 dst에 복사하되 `dst < src` 이면 순차적으로 복사, `dst > src` 이면 뒤에서부터 복사하는 함수 <span style="color:red">*(임시 배열을 사용하기 때문에 dst와 src가 겹쳐도 상관 없음)*</span>|
|memchr|`void *ft_memchr(const void *s, int c, size_t n)`|배열 s를 처음부터 n의 길이까지 검사하되 도중 요소 c를 발견하면 그 지점의 주소를 반환하는 함수 <span style="color:red">*(n바이트 내에서 없을 시 NULL 반환)*</span>|
|memcmp|`int ft_memcmp(const void *s1, const void *s2, size_t n)`|배열 s1과 s2를 n의 길이만큼 비교하되 같지 않은 부분이 나오면 그 인덱스의 `s1 - s2` 의 값을 반환하는 함수 <span style="color:red">*(n == 0 \|\| s1 == s2 일 시 0반환)*</span>|

## Part 2 - Additional fuctions


## Part 3 - List fuctions