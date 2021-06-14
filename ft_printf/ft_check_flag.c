/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:07:59 by keokim            #+#    #+#             */
/*   Updated: 2021/06/14 14:11:18 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*chk_prec(t_format *format, char *str, int num, int len)
{
	if (format->prec > -1 && format->prec >= len)
		str = create_prec_str(format, str, len);
	else if (format->prec == 0 && num == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	return (str);
}

char			*chk_prec_ui(t_format *format, char *s, unsigned int n, int l)
{
	if (format->prec > -1 && format->prec >= l)
		s = create_prec_str(format, s, l);
	else if (format->prec == 0 && n == 0)
	{
		free(s);
		s = ft_strdup("");
	}
	return (s);
}

char			*chk_plus_blank(t_format *format, char *str)
{
	if (format->plus)
		str = ft_strjoin_free("+", str);
	else if (format->blank)
		str = ft_strjoin_free(" ", str);
	return (str);
}

char			*chk_zero(t_format *format, char *str)
{
	int			i;
	char		tmp;

	if (format->zero)
	{
		i = 1;
		while (str[i] && !ft_strchr("+ -", str[i]))
			i++;
		if (ft_strchr("+ -", str[i]))
		{
			tmp = str[0];
			str[0] = str[i];
			str[i] = tmp;
		}
		return (str);
	}
	else
		return (str);
}
