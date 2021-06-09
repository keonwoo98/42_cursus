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

void            chk_type(t_format *format)
{
    if (format->type == 'c')
        type_char(format);
    else if (format->type == 's')
        type_str(format);
    // else if (format->type == 'd')
    //     type_int(format);
}

void            type_char(t_format *format)
{
    char            *c_width;

    if (format->width > 0)
        c_width = ft_malset(format, 1);
    else
        c_width = ft_strdup("");
    if (format->minus == 0)
    {
        format->ret += ft_putstr(c_width);
        format->ret += ft_putchar(va_arg(format->ap, int));
    }
    else
    {
        format->ret += ft_putchar(va_arg(format->ap, int));
        format->ret += ft_putstr(c_width);
    }
}

void            type_str(t_format *format)
{
    char            *str;
    char            *str_prec;
    char            *str_width;
    int             len;

    str = va_arg(format->ap, char *);
    len = ft_strlen(str);
    if (str == NULL)
        str = "(null)";
    if (format->prec > - 1)
        str_prec = ft_substr(str, 0, format->prec);
    else
        str_prec = ft_strdup(str);  // 동적할당에 실패해서 str_prec에 NULL이 저장될 경우도 가드 해줘야됌?? 응 ㅈㄹ하지마셈
    if (format->width > 0 && (size_t)format->width > ft_strlen(str_prec))
    {
        str_width = ft_malset(format, (int)ft_strlen(str_prec));
        str_prec = ft_align(format, str_prec, str_width);
        free(str_width);
    }
    format->ret += ft_putstr(str_prec);
    free(str_prec);
}

char                *ft_align(t_format *format, char *prec, char *width)
{
    char            *s;

    if (format->minus == 0)
        s = ft_strjoin(width, prec);
    else
        s = ft_strjoin(prec, width);
    return (s);
}

char                *ft_malset(t_format *format, int len)
{
    char            *s;

    s = (char *)malloc(sizeof(char) * (format->width - len + 1));
    if (format->zero == 0)
        ft_memset(s, ' ', (format->width - len));
    else
        ft_memset(s, '0', (format->width - len));
    return (s);
}

// void            type_char(va_list ap, t_format *format)
// {
//     int         i;

//     i = 0;
//     if (format->minus == 0)
//     {
//         while (++i < format->width)
//         {
//             ft_putchar(' ');
//             format->ret++;
//         }
//         ft_putchar(va_arg(ap, int));
//         format->ret++;
//     }
//     else
//     {
//         ft_putchar(va_arg(ap, int));
//         format->ret++;
//         while (++i < format->width)
//         {
//             ft_putchar(' ');
//             format->ret++;
//         }
//     }
// }

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
