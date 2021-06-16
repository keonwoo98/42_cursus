#include "ft_printf.h"

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int				ft_putstr(const char *str)
{
	int			i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

size_t			ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int				ft_strchr(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void			*ft_memset(void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t			ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	size_t		src_len;
	size_t		i;

	i = 0;
	src_len = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char			*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*str;

	len = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = 0;
	return (str);
}

char			*ft_strjoin_free(char const *s1, char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = 0;
	free(s2);
	return (str);
}

size_t			get_len(int nb)
{
	size_t		len;

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

size_t			get_ulen(unsigned int nb)
{
	size_t		len;

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

size_t			get_hexlen(unsigned int nb)
{
	int			len;

	len = 1;
	while ((nb /= 16) >= 1)
		len++;
	return (len);
}

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
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
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
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
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
