/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:12:17 by keokim            #+#    #+#             */
/*   Updated: 2021/06/14 14:15:23 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*chk_sharp(t_format *format, char *str, unsigned int num)
{
	if (format->sharp && num != 0 && format->zero)
		format->width -= 2;
	if (format->sharp && format->type == 'x' && num != 0 && !format->zero)
		str = ft_strjoin_free("0x", str);
	else if (format->sharp && format->type == 'X' && num != 0 && !format->zero)
		str = ft_strjoin_free("0X", str);
	return (str);
}

char			*chk_sharp2(t_format *format, char *str, unsigned int num)
{
	if (format->sharp && format->type == 'x' && num != 0 && format->zero)
		str = ft_strjoin_free("0x", str);
	else if (format->sharp && format->type == 'X' && num != 0 && format->zero)
		str = ft_strjoin_free("0X", str);
	return (str);
}

char			*ft_align(t_format *format, char *prec, char *width)
{
	char		*s;

	if (format->minus == 0)
		s = ft_strjoin(width, prec);
	else
		s = ft_strjoin(prec, width);
	free(prec);
	return (s);
}

char			*ft_malset(t_format *format, int len)
{
	char		*s;

	if (!(s = (char *)malloc(sizeof(char) * (format->width - len + 1))))
		return (NULL);
	if (format->zero == 0)
		ft_memset(s, ' ', (format->width - len));
	else
		ft_memset(s, '0', (format->width - len));
	s[format->width - len] = '\0';
	return (s);
}
