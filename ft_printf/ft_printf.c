/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:23:31 by keokim            #+#    #+#             */
/*   Updated: 2021/06/07 09:35:57 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void     init_format(t_format *format)
{
    format->minus = 0;
    format->zero = 0;
    format->width = 0;
    format->prec = -1;
    format->type = 0;
}

static void     type_char(va_list ap, t_format *format)
{
    if (format->minus == 0)
    {
        ft_putchar(' ', format->width);
        ft_putchar(va_arg(ap, int), 1);
    }
    else
    {
        ft_putchar(va_arg(ap, int), 1);
        ft_putchar(' ', format->width);
    }
}

static void      chk_type(va_list ap, t_format *format)
{
    if (format->type == 'c')
        type_char(ap, format);
    else if (format->type == 's')
    {

    }
}

/*
t_format        *width_prec(va_list ap, t_format *format, char c)
{   // 너비 저장하는 함수
    if (ft_isdigit(c))      // 너비 값이 고정 인자 문자열에 존재할 경우
    {
        if (format->prec == -1)     // 정밀도가 고정 인자에 없을 경우
        {
            format->width = format->width * 10 + c - '0';
            // 문자를 정수형으로 변환
            return (format);
        }
        else        // 정밀도가 고정 인자 문자열에 있는 경우
        {
            format->prec = format->width * 10 + c - '0';
            return (format);
        }
    }
    else if (c == '*')      // 숫자 와일드카드, 가변 인자로 값이 들어올 경우
    {
        if (format->prec == -1)
        {
            if ((format->width = va_arg(ap, int)) < 0)
            {
                format->minus = 1;
                // 만약 너비에 대한 가변 인자 값이 음수일 경우 '-'부호를 플래그로 인식하도록 minus 변수를 1로 설정
                format->width = -1;     // 너비는 양수로 변경
                format->zero = 0;       // zero 변수는 0으로 설정하여 무시 ('%' 타입 대비)
            }
        }
        else
        {
            if ((format->prec = va_arg(ap, int)) < 0)
                format->prec = -1;
            // 가변 인자로 받아온 정밀도 너비가 음수일 경우 prec 변수를 -1로 설정하여 정밀도 처리 무시
        }
    }
    return (format);
}
*/

static void      find_format(const char *str, va_list ap, t_format *format)
{
    init_format(format);
    while (*str && !ft_strchr("cspsuixX%", *str))
    {
        if (*str == '-')
            format->minus = 1;
        // else if (*str == '0' && format->width == 0 && format->prec == -1 && format->minus == 0)
        //     format->zero = 1;
        else if (*str == '.')
            format->prec = 0;
        else if (ft_isdigit(*str) || *str == '*')
        {
            // format = width_prec(ap, format, *str);
            format->width = (format->width * 10) + (*str - '0');
            printf("%d\n", format->width);
        }
        str++;
    }
    format->type = *str;
    // if ((format->prec >= 0 || format->minus > 0) && format->type != '%')
    //     format->zero = 0;
    chk_type(ap, format);
}
// %[플래그][폭][.정밀도][크기]서식문자
// cspduixX%

int			    ft_printf(const char *str, ...)
{
    va_list     ap;     // 가변 인자 목록 포인터
    t_format    format;

    va_start(ap, str);      // 가변 인자 목록 포인터 설정
    while (*str)
    {
        if (*str != '%')
        {
            ft_putchar(*str, 1);     // 그대로 출력
            str++;
        }
        else
        {
            find_format(++str, ap, &format);
            str++;
        }
    }
    va_end(ap);     // 가변 인자 목록 포인터를 NULL로 초기화
    return (0);
}

int             main()
{
    char a = 'a';
    char b = 'b';
    char c = 'c';

    ft_printf("ft_printf : %c %c %c\n", 'a', 'b', 'c');
    ft_printf("ft_printf : %c %c %c\n", a, b, c);
    // ft_printf("ft_printf : %11c\n", 'Z');
    // ft_printf("ft_printf : %-11c\n", 'Z');
    ft_putchar(' ', 11);
    ft_putchar('\n', 1);
    printf("printf : %c %c %c\n", 'a', 'b', 'c');
    printf("printf : %c %c %c\n", a, b, c);
    printf("%09.2f\n", 9.12);
}