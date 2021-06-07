/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:09:16 by keokim            #+#    #+#             */
/*   Updated: 2021/06/07 19:09:42 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		        ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void            ft_putchar(char c, int width)
{
    write(1, &c, width);
}

void            ft_putstr(const char *str)
{
    int         i;

    i = 0;
    while (str[i])
        ft_putchar(str[i++], 1);
}

size_t		    ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int             ft_strchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	// if (c == 0)
	// 	return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			// return ((char *)s + i);
            return (1);
		i++;
	}
	return (0);
}
