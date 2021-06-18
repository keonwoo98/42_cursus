#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BASE "0123456789"
#define BASEX "0123456789abcdef"

int				ret = 0;

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_strlen(char *s)
{
	int			i = 0;
	while (s[i])
		i++;
	return (i);
}

int				numlen(long long num, int base)
{
	int			i = 1;
	while ((num /= base) > 0)
		i++;
	return (i);
}

void			ft_putnbr(long long num, int base, char *s)
{
	if (num >= base)
		ft_putnbr(num / base, base, s);
	ret += write(1, &s[num % base], 1);
}

int				ft_printf(const char *str, ...)
{
    va_list		ap;
    int			i = 0;
	int			sign = 0;
    
    va_start(ap, str);
    while(str[i])
    {
		int			width = 0;
		int			prec = -1;

		if (str[i] != '%')
		{
			ret += write(1, &str[i], 1);
			i++;
		}
		else
		{
			i++;
			while (str[i] != 's' && str[i] != 'd' && str[i] != 'x' && str[i] != '\0')
			{
				if (str[i] == '.')
					prec = 0;
				if (ft_isdigit(str[i]))
				{
					if (prec == -1)
						width = (width * 10) + (str[i] - '0');
					else
						prec = (prec * 10) + (str[i] - '0');
				}
				i++;
			}
			if (str[i] == 's')
			{
				char		*s_ret;
				char		*s = va_arg(ap, char *);
				if (!s)
					s = "(null)";
				if (prec == 0)
					s = "";
				else if (prec == -1)
					prec = ft_strlen(s);
				int			len = ft_strlen(s);
				int			w_len = width - (len > prec ? prec : len);
				int			p_len = len > prec ? prec : len;
				int			idx = 0;
				while (idx < w_len)
				{
					ret += write(1, " ", 1);
					idx++;
				}
				idx = 0;
				while (idx < p_len)
				{
					ret += write(1, &s[idx], 1);
					idx++;
				}
				i++;
			}
			else if (str[i] == 'd')
			{
				long long		num = va_arg(ap, int);
				if (num < 0)
				{
					num *= -1;
					sign = 1;
				}
				if (num == 0 && prec == 0)
					width++;
				int				len = numlen(num, 10);
				int				w_len = width - sign - (prec < len ? len : prec);
				int				idx = 0;
				while (idx < w_len)
				{
					ret += write(1, " ", 1);
					idx++;
				}
				ret += write(1, "-", sign);
				idx = 0;
				while (idx < prec - len)
				{
					ret += write(1, "0", 1);
					idx++;
				}
				if (num != 0 || prec != 0 || prec != -1)
					ft_putnbr(num, 10, BASE);
				i++;
			}
			else if (str[i] == 'x')
			{
				long long		num = va_arg(ap, unsigned int);
				if (num == 0 && prec == 0)
					width++;
				int				len = numlen(num, 16);
				int				w_len = width - (prec < len ? len : prec);
				int				idx = 0;
				while (idx < len)
				{
					ret += write(1, " ", 1);
					idx++;
				}
				idx = 0;
				while (idx < prec - len)
				{
					ret += write(1, "0", 1);
					idx++;
				}
				if (num != 0 || prec != 0 || prec != -1)
					ft_putnbr(num, 16, BASEX);
				i++;
			}
		}
    }
	va_end(ap);
	return (ret);
}

int		main()
{
	int		ret = 0;
	ft_printf("ft_printf : %d %x %d %x %d %x %d %x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("printf : %d %x %d %x %d %x %d %x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
}