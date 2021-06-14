/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:35:38 by keokim            #+#    #+#             */
/*   Updated: 2021/06/14 15:52:20 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				type_hexa(t_format *format)
{
	char			*str;
	char			*str_ret;
	char			*str_width;
	unsigned int	num;
	int				len;

	num = va_arg(format->ap, unsigned int);
	str = ft_itoa_base(format, num);
	len = ft_strlen(str);
	if (format->prec != -1)
		str = chk_prec_ui(format, str, num, len);
	str = chk_sharp(format, str, num);
	if (format->width > 0 && (size_t)format->width > ft_strlen(str))
	{
		str_width = ft_malset(format, (int)ft_strlen(str));
		str = ft_align(format, str, str_width);
		free(str_width);
	}
	str = chk_sharp2(format, str, num);
	str_ret = chk_zero(format, str);
	format->ret += ft_putstr(str_ret);
	free(str);
}

void				type_point(t_format *format)
{
	char			*str;
	char			*str_ret;
	char			*str_width;
	unsigned long	num;
	int				len;

	num = va_arg(format->ap, unsigned long);
	str = ft_ultoa_base(format, num);
	len = ft_strlen(str);
	if (format->prec != -1)
		str = chk_prec_ui(format, str, num, len);
	str = ft_strjoin_free("0x", str);
	if (format->width > 0 && (size_t)format->width > ft_strlen(str))
	{
		str_width = ft_malset(format, (int)ft_strlen(str));
		str = ft_align(format, str, str_width);
		free(str_width);
	}
	str_ret = chk_zero(format, str);
	format->ret += ft_putstr(str_ret);
	free(str);
}

void				type_percent(t_format *format)
{
	char			*c_width;

	if (format->width > 0)
		c_width = ft_malset(format, 1);
	else
		c_width = ft_strdup("");
	if (format->minus == 0)
	{
		format->ret += ft_putstr(c_width);
		format->ret += ft_putchar(format->type);
	}
	else
	{
		format->ret += ft_putchar(format->type);
		format->ret += ft_putstr(c_width);
	}
	free(c_width);
}
