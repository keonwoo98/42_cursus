#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	dst[50];
	char	dst2[50] = { 0 };
	char	*src = "Hello World!!";
	char	*s1 = "42Cursus";
	char	*s2 = "42Piscine";

	printf("ft_atoi\n%d\n\n", ft_atoi("   -123abc   "));
	printf("ft_strlen\n%zu\n\n", ft_strlen("123456abcd"));
	printf("ft_strlcpy\n%zu\n%s\n\n", ft_strlcpy(dst, src, 6), dst);
	printf("ft_strlcat\n%zu\n%s\n\n", ft_strlcat(dst2, src, 9), dst2);
	printf("ft_strncmp\n%d\n\n", ft_strncmp(s1, s2, 5));
	printf("ft_strchr\n%s\n\n", ft_strchr(src, 'o'));
	printf("ft_strrchr\n%s\n\n", ft_strrchr(src, 'o'));

	return (0);
}
