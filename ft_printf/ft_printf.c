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
        // while(1);
    }
    va_end(format.ap);     // 가변 인자 목록 포인터를 NULL로 초기화
    return (ret);
}

// int main()
// {
//     unsigned int u = 4294967161;

//     // ft_printf("%3.7i", 3267);
//     // ft_printf("%3.7d", 3267);
//     ft_printf("-->|%-4.*u|<--\n", -4, u);
//     ft_printf("this %x number\n", 33);
// }
