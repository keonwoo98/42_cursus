#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_format
{
	va_list		ap;
	int			ret;
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		type;
}				t_format;

int				ft_isdigit(int c);
int				ft_putchar(char c);
int				ft_putstr(const char *str);
size_t			ft_strlen(const char *s);
int				ft_strchr(const char *s, char c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, char const *src, size_t dstsize);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char const *s1, char *s2);
size_t			get_len(long long nb);
char			*ft_itoa(long long n);
char			*ft_itoa_base(t_format *format, long long n);
char			*ft_ultoa_base(t_format *format, unsigned long num);

char			*create_prec_str(t_format *format, char *str, int len);
char			*chk_prec(t_format *format, char *str, long long num, int len);
char			*chk_zero(t_format *format, char *str);
char			*ft_align(t_format *format, char *prec, char *width);
char			*ft_malset(t_format *format, int len);

void			chk_type(t_format *format);
void			type_char(t_format *format);
void			type_str(t_format *format);
void			type_int(t_format *format);
void			type_unsigned_int(t_format *format);
void			type_hexa(t_format *format);
void			type_point(t_format *format);
void			type_percent(t_format *format);

void			init_format(t_format *format);
void			find_format(const char *str, t_format *format);
void			width_prec(t_format *format, char c);
int				ft_printf(const char *str, ...);

#endif
