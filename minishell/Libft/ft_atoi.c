/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:05:52 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/13 16:05:50 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int
	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v'
		|| c == '\n' || c == '\f')
		return (1);
	return (0);
}

static int
	check_range(unsigned int result, int sign)
{
	if (result > 2147483648 && sign == -1)
		return (0);
	else if (result > 2147483647 && sign == 1)
		return (-1);
	else
		return (sign * result);
}

int
	ft_atoi(const char *str)
{
	int		result;
	int		sign;

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
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (check_range(result, sign));
}
