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

void            chk_type(va_list ap, t_format *format)
{
    if (format->type == 'c')
        type_char(ap, format);
    else if (format->type == 's')
        type_str(ap, format);
}

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

void            type_str(va_list ap, t_format *format)
{
    char            *str;
    char            *str_prec;
    char            *str_width;
    char            *str_print;
    int             len;

    str = va_arg(ap, char *);
    len = ft_strlen(str);
    if (str == NULL)
        str = "(null)";
    if (format->prec > - 1)
        str_prec = ft_substr(str, 0, format->prec);
    else
        str_prec = ft_strdup(str);  // 동적할당에 실패해서 str_prec에 NULL이 저장될 경우도 가드 해줘야됌?? 응 ㅈㄹ하지마셈
    if (format->width > len)
    {
        str_width = (char *)malloc(sizeof(char) * (format->width - ft_strlen(str_prec) + 1));
        if (format->zero == 0)
            ft_memset(str_width, ' ', (format->width - ft_strlen(str_prec)));
        else
            ft_memset(str_width, '0', (format->width - ft_strlen(str_prec)));
    }
    else
        str_width = ft_strdup("");
    if (format->minus == 0)
        str_print = ft_strjoin(str_width, str_prec);
    else
        str_print = ft_strjoin(str_prec, str_width);
    ft_putstr(str_print);
    format->ret = ft_strlen(str_print);
    free(str_prec);
    free(str_width);
    free(str_print);
}

// void            type_str(va_list ap, t_format *format)
// {
//     char        *str;
//     int         len;
//     int         i;

//     i = 0;
//     str = va_arg(ap, char *);
//     len = ft_strlen(str);
//     if (str == NULL)
//         str = "(null)";
//     if (format->prec > -1)      // 만약 '.'플래그가 존재한다면
//     {
//         if (len <= format->prec)
//         {
//             if (format->width < format->prec || !format->width)
//             {
//                 // 그냥 출력
//                 ft_putstr(str);
//                 format->ret += len;
//             }
//             else if (format->width >= format->prec)
//             {
//                 // 출력 + width - len만큼 공백 출력
//                 if (format->minus == 0)
//                 {
//                     while (i++ < format->width - len)
//                         ft_putchar(' ');
//                     i = 0;
//                     while (i < format->prec)
//                         ft_putchar(str[i++]);
//                 }
//                 else
//                 {
//                     while (i < format->prec)
//                         ft_putchar(str[i++]);
//                     i = 0;
//                     while (i++ < format->width - len)
//                         ft_putchar(' ');
//                 }
//                 format->ret += format->width;
//             }
//         }
//         else if (len > format->prec)
//         {
//             if (format->width < format->prec || !format->width)
//             {
//                 // precision만큼 출력
//                 while (i < format->prec)
//                     ft_putchar(str[i++]);
//                 format->ret += format->prec;
//             }
//             else if (format->width >= format->prec)
//             {
//                 // precision만큼 출력 + width - precision만큼 공백 출력
//                 if (format->minus == 0)
//                 {
//                     while (i++ < (format->width - format->prec))
//                         ft_putchar(' ');
//                     i = 0;
//                     while (i < format->prec)
//                         ft_putchar(str[i++]);
//                 }
//                 else
//                 {
//                     ft_putstr(str);
//                     while (i < format->prec)
//                         ft_putchar(str[i++]);
//                     i = 0;
//                     while (i++ < (format->width - format->prec))
//                         ft_putchar(' ');
//                 }
//                 format->ret += (format->prec + (format->width - format->prec));
//             }
//         }
//     }
//     else        // 만약 '.'플래그가 없다면
//     {
//         if (len >= format->width)
//         {
//             ft_putstr(str);
//             format->ret += len;
//         }
//         else
//         {
//             if (format->minus == 0)
//             {
//                 while (i++ < format->width - len)
//                     ft_putchar(' ');
//                 ft_putstr(str);
//             }
//             else
//             {
//                 ft_putstr(str);
//                 while (i++ < format->width - len)
//                     ft_putchar(' ');
//             }
//             format->ret += format->width;
//         }
//     }
// }
