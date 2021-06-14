/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:09:52 by keokim            #+#    #+#             */
/*   Updated: 2021/06/14 16:47:49 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_itoa(int n)
{
	int				len;
	char			*str;
	long			nb;

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

char				*ft_uitoa(unsigned int n)
{
	int				len;
	char			*str;
	long			nb;

	len = get_ulen(n);
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

char				*ft_itoa_base(t_format *format, unsigned int n)
{
	char			*s;
	int				i;

	i = get_hexlen(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	if (format->type == 'X')
	{
		while (i--)
		{
			s[i] = (n % 16 < 10) ? n % 16 + '0' : n % 16 + 'A' - 10;
			n /= 16;
		}
	}
	else if (format->type == 'x')
	{
		while (i--)
		{
			s[i] = (n % 16 < 10) ? n % 16 + '0' : n % 16 + 'a' - 10;
			n /= 16;
		}
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char				*ft_ultoa_base(t_format *format, unsigned long num)
{
	char			*s;
	unsigned long	n;
	int				i;

	i = 1;
	n = num;
	while ((num /= 16) >= 1)
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	if (format->type == 'p')
	{
		while (i--)
		{
			s[i] = (n % 16 < 10) ? n % 16 + '0' : n % 16 + 'a' - 10;
			n /= 16;
		}
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
