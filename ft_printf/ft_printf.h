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
    int     minus;
    int     zero;
    int     width;
    int     prec;
    char    type;
}               t_format;

int		        ft_isdigit(int c);
void            ft_putchar(char c, int width);
void            ft_putstr(const char *str);
size_t		    ft_strlen(const char *s);
int             ft_strchr(const char *s, char c);

#endif
