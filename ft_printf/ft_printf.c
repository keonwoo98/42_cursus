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
            while (*str && !ft_strchr("csdpsuixX%", *str))
                str++;
            str++;
            ret += format.ret;
        }
    }
    va_end(format.ap);     // 가변 인자 목록 포인터를 NULL로 초기화
    return (ret);
}

// int main()
// {
//     int d = 0;

//     printf("-->|%+0*.*d|<--\n", 2, -4, d);
// }
