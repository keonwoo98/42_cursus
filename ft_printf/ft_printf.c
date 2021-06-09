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


// %[플래그][폭][.정밀도][크기]서식문자
// cspduixX%

int			    ft_printf(const char *str, ...)
{
    // va_list     ap;     // 가변 인자 목록 포인터
    t_format    format;
    int         ret;

    ret = 0;
    va_start(format.ap, str);      // 가변 인자 목록 포인터 설정
    while (*str)
    {
        if (*str != '%')
        {
            ret += ft_putchar(*str);     // 그대로 출력
            str++;
        }
        else
        {
            find_format(++str, &format);
            while (*str && !ft_strchr("cspsuixX%", *str))
                str++;
            str++;
            ret += format.ret;
        }
    }
    va_end(format.ap);     // 가변 인자 목록 포인터를 NULL로 초기화
    return (ret);
}

// int main(void)
// {
//     int n = 0;
//     ft_printf("ft_printf : %c %c %c\n", 'a', 'b', 'c');
//     n = ft_printf("ft_printf : %s + %s", "abc", "xyz");
// }

// int             main()
// {
//     char a = 'a';
//     char b = 'b';
//     char c = 'c';

//     ft_printf("ft_printf : %c %c %c\n", 'a', 'b', 'c');
//     ft_printf("ft_printf : %c %c %c\n", a, b, c);
//     ft_printf("ft_printf : %5c\n", 'Z');
//     ft_printf("ft_printf : %-5c\n", 'Z');
//     ft_printf("ft_printf : %*c\n", 5, 'a');
//     ft_printf("ft_printf : %*c\n", -5, 'a');
//     printf("printf : %c %c %c\n", 'a', 'b', 'c');
//     printf("printf : %c %c %c\n", a, b, c);
//     printf("printf : %09.2f\n", 9.12);
//     printf("printf : %*c\n", 5, 'a');
// }


int main()
{
    // ft_printf("-->|%10s|<--\n", "keokim");
    // printf("-->|%10s|<--\n", "keokim");
    // ft_printf("-->|%2.8s|<--\n", "keokim");
    // printf("-->|%2.8s|<--\n", "keokim");
    // ft_printf("-->|%-8.2s|<--\n", "keokim");
    // printf("-->|%-8.2s|<--\n", "keokim");
    // ft_printf("-->|%.9s|<--\n", "keokim");
    // printf("-->|%.9s|<--\n", "keokim");
    // ft_printf("-->|%3.4s|<--\n", "keokim");
    // printf("-->|%3.4s|<--\n", "keokim");
    ft_printf("-->|%-3.4s|<--\n", "keokim");
    printf("-->|%-3.4s|<--\n", "keokim");
    ft_printf("-->|%10.3s|<--\n", "keokim");
    printf("-->|%10.3s|<--\n", "keokim");
    ft_printf("-->|%-10.3s|<--\n", "keokim");
    printf("-->|%-10.3s|<--\n", "keokim");
    ft_printf("-->|%-16.*s|<--\n", -4, "keokim");
    printf("-->|%-16.*s|<--\n", -4, "keokim");
    ft_printf("-->|%-16.16s|<--\n", "keokim");
    printf("-->|%-16.16s|<--\n", "keokim");
    ft_printf("-->|%-16.*s|<--\n", 4, "keokim");
    printf("-->|%-16.*s|<--\n", 4, "keokim");
    ft_printf("-->|%-16.4s|<--\n", "keokim");
    printf("-->|%-16.4s|<--\n", "keokim");
    ft_printf("-->|%-16.*s|<--\n", 1, "a");
    printf("-->|%-16.*s|<--\n", 1, "a");
    ft_printf("-->|%8.1s|<--\n", "a");
    printf("-->|%8.1s|<--\n", "a");
    ft_printf("-->|%16s|<--\n", "nark nark");
    printf("-->|%16s|<--\n", "nark nark");
}
