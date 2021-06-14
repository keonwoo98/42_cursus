/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:09:16 by keokim            #+#    #+#             */
/*   Updated: 2021/06/14 15:56:53 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int				ft_putstr(const char *str)
{
	int			i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

size_t			ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int				ft_strchr(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
