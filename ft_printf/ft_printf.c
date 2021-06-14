/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:23:31 by keokim            #+#    #+#             */
/*   Updated: 2021/06/14 16:31:08 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_format(t_format *format)
{
	format->ret = 0;
	format->minus = 0;
	format->zero = 0;
	format->plus = 0;
	format->blank = 0;
	format->sharp = 0;
	format->width = 0;
	format->prec = -1;
	format->type = 0;
}

void			find_format(const char *str, t_format *format)
{
	init_format(format);
	while (*str && !ft_strchr("csdpuixXnfgo%", *str))
	{
		if (*str == '-')
			format->minus = 1;
		else if (*str == '0' && format->width == 0 &&
				format->prec == -1 && format->minus == 0)
			format->zero = 1;
		else if (*str == '+')
			format->plus = 1;
		else if (*str == ' ')
			format->blank = 1;
		else if (*str == '#')
			format->sharp = 1;
		else if (*str == '.')
			format->prec = 0;
		else if (ft_isdigit(*str) || *str == '*')
			width_prec(format, *str);
		str++;
	}
	format->type = *str;
	if ((format->prec >= 0 || format->minus > 0) && format->type != '%')
		format->zero = 0;
	chk_type(format);
}

void			width_prec(t_format *format, char c)
{
	if (ft_isdigit(c))
	{
		if (format->prec == -1)
			format->width = (format->width * 10) + (c - '0');
		else
			format->prec = (format->prec * 10) + (c - '0');
	}
	else if (c == '*')
	{
		if (format->prec == -1)
		{
			if ((format->width = va_arg(format->ap, int)) < 0)
			{
				format->minus = 1;
				format->width *= -1;
				format->zero = 0;
			}
		}
		else
		{
			if ((format->prec = va_arg(format->ap, int)) < 0)
				format->prec = -1;
		}
	}
}

int				ft_printf(const char *str, ...)
{
	t_format	format;
	int			ret;

	ret = 0;
	va_start(format.ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			ret += ft_putchar(*str);
			str++;
		}
		else
		{
			find_format(++str, &format);
			while (*str && !ft_strchr("csdpuixXnfgo%", *str))
				str++;
			if (ft_strchr("cspdiuxX%", *str))
				str++;
			ret += format.ret;
		}
	}
	va_end(format.ap);
	return (ret);
}
