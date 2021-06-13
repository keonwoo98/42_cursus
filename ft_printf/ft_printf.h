/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:29:42 by keokim            #+#    #+#             */
/*   Updated: 2021/06/07 09:31:28 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_format
{
    va_list ap;
    int     ret;
    int     minus;
    int     zero;
    int     plus;
    int     blank;
    int     sharp;
    int     width;
    int     prec;
    char    type;
}               t_format;

int		        ft_isdigit(int c);
void	        *ft_memset(void *b, int c, size_t len);
void	        *ft_memcpy(void *dst, const void *src, size_t n);
int             ft_putchar(char c);
int             ft_putstr(const char *str);
size_t	        get_len(int nb);
size_t	        get_ulen(unsigned int nb);
char	        *ft_itoa(int n);
char	        *ft_uitoa(unsigned int n);
char	        *ft_itoa_base(t_format *format, unsigned int num);
char	        *ft_lltoa_base(t_format *format, long long num);
size_t		    ft_strlen(const char *s);
int             ft_strchr(const char *s, char c);
size_t		    ft_strlcpy(char *dst, char const *src, size_t dstsize);
char	        *ft_strdup(const char *s1);
char		    *ft_substr(char const *s, unsigned int start, size_t len);
char	        *ft_strjoin(char const *s1, char const *s2);
char	        *ft_strjoin_free(char const *s1, char *s2);

void            init_format(t_format *format);
void            find_format(const char *str, t_format *format);
t_format        *width_prec(t_format *format, char c);

void            type_char(t_format *format);
char            *chk_zero(t_format *format, char *str);
char            *chk_prec(t_format *format, char *str, int num, int len);
char            *chk_prec_ui(t_format *format, char *str, unsigned int num, int len);
char            *chk_plus_blank(t_format *format, char *str);
char            *chk_sharp(t_format *format, char *str, unsigned int num);
char            *chk_sharp2(t_format *format, char *str, unsigned int num);
void            type_str(t_format *format);
void            type_int(t_format *format);
void            type_unsigned_int(t_format *format);
void            type_hexa(t_format *format);
void            type_point(t_format *format);
void            type_percent(t_format *format);
void            chk_type(t_format *format);
char            *ft_align(t_format *format, char *prec, char *width);
char            *ft_malset(t_format *format, int len);
char            *create_prec_str(t_format *format, char *str, int len);

int			    ft_printf(const char *str, ...);

#endif
