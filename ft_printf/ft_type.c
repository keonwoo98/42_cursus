/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:23:50 by keokim            #+#    #+#             */
/*   Updated: 2021/06/08 10:23:52 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void            type_char(va_list ap, t_format *format)
{
    int         i;

    i = 0;
    if (format->minus == 0)
    {
        while (++i < format->width)
        {
            ft_putchar(' ');
            format->ret++;
        }
        ft_putchar(va_arg(ap, int));
        format->ret++;
    }
    else
    {
        ft_putchar(va_arg(ap, int));
        format->ret++;
        while (++i < format->width)
        {
            ft_putchar(' ');
            format->ret++;
        }
    }
}
#include <stdio.h>
void            type_str(va_list ap, t_format *format)
{
    char        *str;
    int         len;
    int         i;

    i = 0;
    str = va_arg(ap, char *);
    len = ft_strlen(str);
    if (str == NULL)
        str = "(null)";
    if (format->prec > -1)      // 만약 '.'플래그가 존재한다면
    {
        if (len <= format->prec)
        {
            if (format->width < format->prec || !format->width)
            {
                // 그냥 출력
                ft_putstr(str);
                format->ret += len;
            }
            else if (format->width >= format->prec)
            {
                // 출력 + width - len만큼 공백 출력
                if (format->minus == 0)
                {
                    while (i++ < format->width - len)
                        ft_putchar(' ');
                    i = 0;
                    while (i < format->prec)
                        ft_putchar(str[i++]);
                }
                else
                {
                    while (i < format->prec)
                        ft_putchar(str[i++]);
                    i = 0;
                    while (i++ < format->width - len)
                        ft_putchar(' ');
                }
                format->ret += format->width;
            }
        }
        else if (len > format->prec)
        {
            if (format->width < format->prec || !format->width)
            {
                // precision만큼 출력
                while (i < format->prec)
                    ft_putchar(str[i++]);
                format->ret += format->prec;
            }
            else if (format->width >= format->prec)
            {
                // precision만큼 출력 + width - precision만큼 공백 출력
                if (format->minus == 0)
                {
                    while (i++ < (format->width - format->prec))
                        ft_putchar(' ');
                    i = 0;
                    while (i < format->prec)
                        ft_putchar(str[i++]);
                }
                else
                {
                    ft_putstr(str);
                    while (i < format->prec)
                        ft_putchar(str[i++]);
                    i = 0;
                    while (i++ < (format->width - format->prec))
                        ft_putchar(' ');
                }
                format->ret += (format->prec + (format->width - format->prec));
            }
        }
    }
    else        // 만약 '.'플래그가 없다면
    {
        if (len >= format->width)
        {
            ft_putstr(str);
            format->ret += len;
        }
        else
        {
            if (format->minus == 0)
            {
                while (i++ < format->width - len)
                    ft_putchar(' ');
                ft_putstr(str);
            }
            else
            {
                ft_putstr(str);
                while (i++ < format->width - len)
                    ft_putchar(' ');
            }
            format->ret += format->width;
        }
    }
}

void            chk_type(va_list ap, t_format *format)
{
    if (format->type == 'c')
        type_char(ap, format);
    else if (format->type == 's')
        type_str(ap, format);
}
