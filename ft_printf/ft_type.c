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
    else if (format->type == 'd' || format->type == 'i')
        type_int(format);
    else if (format->type == 'u')
        type_unsigned_int(format);
    else if (format->type == 'x' || format->type == 'X')
        type_hexa(format);
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
    free(c_width);
}

void            type_str(t_format *format)
{
    char            *str;
    char            *str_prec;
    char            *str_width;
    int             len;

    str = va_arg(format->ap, char *);
    if (!str)
        str = "(null)";
    len = ft_strlen(str);
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

void            type_int(t_format *format)
{
    char            *str;
    char            *str_ret;
    char            *str_width;
    int             num;
    int             len;
    
    num = va_arg(format->ap, int);
    str = ft_itoa(num);
    len = ft_strlen(str);
    if (format->prec != -1)
        str = chk_prec(format, str, num, len);
    if ((format->plus || format->blank) && num >= 0)
        str = chk_plus_blank(format, str);
    if (format->width > 0 && (size_t)format->width > ft_strlen(str))
    {
        str_width = ft_malset(format, (int)ft_strlen(str));
        str = ft_align(format, str, str_width);
        free(str_width);
    }
    str_ret = chk_zero(format, str);
    free(str);
    format->ret += ft_putstr(str_ret);
}

void            type_unsigned_int(t_format *format)
{
    char            *str;
    char            *str_ret;
    char            *str_width;
    unsigned int    num;
    int             len;
    
    num = va_arg(format->ap, int);
    str = ft_uitoa(num);
    len = ft_strlen(str);
    if (format->prec != -1)
        str = chk_prec_ui(format, str, num, len);
    // if (format->plus || format->blank)
    //     str = chk_plus_blank(format, str);
    if (format->width > 0 && (size_t)format->width > ft_strlen(str))
    {
        str_width = ft_malset(format, (int)ft_strlen(str));
        str = ft_align(format, str, str_width);
        free(str_width);
    }
    str_ret = chk_zero(format, str);
    free(str);
    format->ret += ft_putstr(str_ret);
}

void            type_hexa(t_format *format)
{
    char            *str;
    char            *str_ret;
    char            *str_width;
    unsigned int    num;
    int             len;
    
    num = va_arg(format->ap, int);
    str = ft_itoa_base(format, num);
    len = ft_strlen(str);
    if (format->prec != -1)
        str = chk_prec_ui(format, str, num, len);
    // if (format->plus || format->blank)
    //     str = chk_plus_blank(format, str);
    if (format->width > 0 && (size_t)format->width > ft_strlen(str))
    {
        str_width = ft_malset(format, (int)ft_strlen(str));
        str = ft_align(format, str, str_width);
        free(str_width);
    }
    str_ret = chk_zero(format, str);
    free(str);
    format->ret += ft_putstr(str_ret);
}

char            *chk_prec(t_format *format, char *str, int num, int len)
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

char            *chk_prec_ui(t_format *format, char *str, unsigned int num, int len)
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

char            *chk_plus_blank(t_format *format, char *str)
{
    // if (format->plus == 1 && num >= 0)
    //     str = ft_strjoin_free("+", str);
    // else if (format->blank == 1 && num >= 0)
    //     str = ft_strjoin_free(" ", str);
    // return (str);
    if (format->plus)
        str = ft_strjoin_free("+", str);
    else if (format->blank)
        str = ft_strjoin_free(" ", str);
    return (str);
}

char            *chk_zero(t_format *format, char *str)
{
    int         i;
    char        tmp;

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

char            *create_prec_str(t_format *format, char *str, int len)
{
    char            *str_prec;

    if (*str == '-')
    {
        str_prec = (char *)malloc(sizeof(char) * format->prec + 2);
        ft_memset(str_prec, '0', format->prec + 1);
        str_prec[format->prec + 2] = '\0';
        str_prec[0] = '-';
        ft_memcpy(&str_prec[format->prec - len + 2], str + 1, len);
    }
    else
    {
        str_prec = (char *)malloc(sizeof(char) * format->prec + 1);
        ft_memset(str_prec, '0', format->prec);
        str_prec[format->prec + 1] = '\0';
        ft_memcpy(&str_prec[format->prec - len], str, len);
    }
    free(str);
    return (str_prec);
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
        ft_memset(s, ' ', (format->width - len ));
    else
        ft_memset(s, '0', (format->width - len));
    s[format->width - len] = '\0';
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
