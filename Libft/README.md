# Libft
>흔히 쓰이는 함수들을 재편성한 C 라이브러리 구현

## Part 1 - Libc functions

man에 정의되어 있는 대로 libc 함수들의 구성을 다시 구현합니다. 함수들은 원본과 같은 형식의 프로토타입을 선언하고 함수 이름 앞에는 `ft_`를 붙입니다. 함수의 프로토타입의 일부는 `restrict` 한정자를 사용합니다. 이 키워드는 c99 표준의 일부분입니다. 그러므로 이 키워드를 프로토타입에 포함시키는 것과 -std=c99 플리그를 사용하여 컴파일 하는 것은 금지됩니다.

|함수명|프로토타입|man 설명|
|:--|:--|:--|
|memset|`void *ft_memset(void *b, int c, size_t len)`|b배열을 입력받아 len의 길이만큼 c문자로 초기화하는 함수|
|bzero|`void ft_bzero(void *s, size_t n)`|문자열 s를 입력받아 문자열 s의 요소들을 n의 길이만큼 0으로 초기화하는 함수|

## Part 2 - Additional fuctions


## Part 3 - List fuctions