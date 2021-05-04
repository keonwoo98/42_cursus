#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	dst[50];
	char	dst2[50] = { 0 };
	char	dst3[32] = "Destination memory";
	char	dst4[50];
	char	*src = "Hello World!!";
	char	src2[32] = "Source memory";
	char	src3[50] = "The quick brown dog jumps over the lazy fox";
	char	*s1 = "42Cursus";
	char	*s2 = "42Piscine";
	char	arr[] = "Hello World!!";
	char	*pdst;
	char	mem[5] = "eeeee";

	printf("ft_atoi\n%d\n\n", ft_atoi("   -123abc   "));
	printf("ft_strlen\n%zu\n\n", ft_strlen("123456abcd"));
	printf("ft_strlcpy\n%zu\n%s\n\n", ft_strlcpy(dst, src, 6), dst);
	printf("ft_strlcat\n%zu\n%s\n\n", ft_strlcat(dst2, src, 9), dst2);
	printf("ft_strncmp\n%d\n\n", ft_strncmp(s1, s2, 5));
	printf("ft_strchr\n%s\n\n", ft_strchr(src, 'o'));
	printf("ft_strrchr\n%s\n\n", ft_strrchr(src, 'o'));
	printf("ft_strnstr\n%s\n\n", ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 15));
	printf("ft_isalpha\n%d\n\n", ft_isalpha('K'));
	printf("ft_isdigit\n%d\n\n", ft_isdigit('9'));
	printf("ft_isalnum\n%d\n\n", ft_isalnum('A'));
	printf("ft_isascii\n%d\n\n", ft_isascii(127));
	printf("ft_isprint\n%d\n\n", ft_isprint(32));
	printf("ft_toupper\n%c\n\n", ft_toupper('a'));
	printf("ft_tolower\n%c\n\n", ft_tolower('A'));
	printf("ft_memset\n%s\n\n", ft_memset(arr, 'x', 5));
	printf("ft_bzero\n");
	ft_bzero(mem, 5); printf("%s\n\n", mem);
	printf("ft_memcpy\n%s\n\n", ft_memcpy(dst3, src2, 32));
	pdst = memccpy(dst4, src3, 's', 50); *pdst = '\0';
	printf("ft_memccpy\n%s\n\n", dst4);

	return (0);
}
