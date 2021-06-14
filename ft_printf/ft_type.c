/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:23:50 by keokim            #+#    #+#             */
/*   Updated: 2021/06/14 15:49:07 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				chk_type(t_format *format)
{
	if (format->type == 'c')
		type_char(format);
	else if (format->type == 's')
		type_str(format);
	else if (format->type == 'd' || format->type == 'i')
		type_int(format);
	else if (format->type == 'u')
		type_unsigned_int(format);
	else if (format->type == 'x' || format->type == 'X')
		type_hexa(format);
	else if (format->type == 'p')
		type_point(format);
	else if (format->type == '%')
		type_percent(format);
}

void				type_char(t_format *format)
{
	char			*c_width;

	if (format->width > 0)
		c_width = ft_malset(format, 1);
	else
		c_width = ft_strdup("");
	if (format->minus == 0)
	{
		format->ret += ft_putstr(c_width);
		format->ret += ft_putchar(va_arg(format->ap, int));
	}
	else
	{
		format->ret += ft_putchar(va_arg(format->ap, int));
		format->ret += ft_putstr(c_width);
	}
	free(c_width);
}

void				type_str(t_format *format)
{
	char			*str;
	char			*str_prec;
	char			*str_width;
	int				len;

	str = va_arg(format->ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (format->prec > -1)
		str_prec = ft_substr(str, 0, format->prec);
	else
		str_prec = ft_strdup(str);
	if (format->width > 0 && (size_t)format->width > ft_strlen(str_prec))
	{
		str_width = ft_malset(format, (int)ft_strlen(str_prec));
		str_prec = ft_align(format, str_prec, str_width);
		free(str_width);
	}
	format->ret += ft_putstr(str_prec);
	free(str_prec);
}

void				type_int(t_format *format)
{
	char			*str;
	char			*str_ret;
	char			*str_width;
	int				num;
	int				len;

	num = va_arg(format->ap, int);
	str = ft_itoa(num);
	len = ft_strlen(str);
	if (format->prec != -1)
		str = chk_prec(format, str, num, len);
	if ((format->plus || format->blank) && num >= 0)
		str = chk_plus_blank(format, str);
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

void				type_unsigned_int(t_format *format)
{
	char			*str;
	char			*str_ret;
	char			*str_width;
	unsigned int	num;
	int				len;

	num = va_arg(format->ap, unsigned int);
	str = ft_uitoa(num);
	len = ft_strlen(str);
	if (format->prec != -1)
		str = chk_prec_ui(format, str, num, len);
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
