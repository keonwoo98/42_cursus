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

int            ft_putchar(char c)
{
    write(1, &c, 1);
	return (1);
}

int            ft_putstr(const char *str)
{
    int         i;

    i = 0;
    while (str[i])
        ft_putchar(str[i++]);
	return (i);
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

size_t	get_len(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = get_len(n);
	nb = (long)n;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}
