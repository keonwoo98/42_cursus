#include "checker.h"

int
	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' \
	|| c == '\v' || c == '\n' || c == '\f')
		return (1);
	return (0);
}

long long
	ft_atoi_long(const char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*str && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == 0)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}
