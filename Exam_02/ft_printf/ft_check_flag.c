#include "ft_printf.h"

char			*create_prec_str(t_format *format, char *str, int len)
{
	char		*str_prec;

	if (*str == '-')
	{
		if (!(str_prec = (char *)malloc(sizeof(char) * format->prec + 2)))
			return (NULL);
		ft_memset(str_prec, '0', format->prec + 1);
		str_prec[format->prec + 1] = '\0';
		str_prec[0] = '-';
		ft_memcpy(&str_prec[format->prec - len + 2], str + 1, len);
	}
	else
	{
		if (!(str_prec = (char *)malloc(sizeof(char) * format->prec + 1)))
			return (NULL);
		ft_memset(str_prec, '0', format->prec);
		str_prec[format->prec] = '\0';
		ft_memcpy(&str_prec[format->prec - len], str, len);
	}
	free(str);
	return (str_prec);
}

char			*chk_prec(t_format *format, char *str, long long num, int len)
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
