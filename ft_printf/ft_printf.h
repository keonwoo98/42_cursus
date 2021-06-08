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
    int     ret;
    int     minus;
    int     zero;
    int     width;
    int     prec;
    char    type;
}               t_format;

int		        ft_isdigit(int c);
void	        *ft_memset(void *b, int c, size_t len);
void	        *ft_memcpy(void *dst, const void *src, size_t n);
int             ft_putchar(char c);
void            ft_putstr(const char *str);
size_t		    ft_strlen(const char *s);
int             ft_strchr(const char *s, char c);
size_t		    ft_strlcpy(char *dst, char const *src, size_t dstsize);
char	        *ft_strdup(const char *s1);
char		    *ft_substr(char const *s, unsigned int start, size_t len);
char	        *ft_strjoin(char const *s1, char const *s2);

void            init_format(t_format *format);
void            find_format(const char *str, va_list ap, t_format *format);
t_format        *width_prec(va_list ap, t_format *format, char c);

void            type_char(va_list ap, t_format *format);
void            type_str(va_list ap, t_format *format);
void            chk_type(va_list ap, t_format *format);

int			    ft_printf(const char *str, ...);

#endif
