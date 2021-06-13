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
            while (*str && !ft_strchr("csdpuixXnfgo%", *str))
                str++;
            str++;
            ret += format.ret;
        }
    }
    va_end(format.ap);     // 가변 인자 목록 포인터를 NULL로 초기화
    return (ret);
}

int main()
{
    unsigned int u = 4294967161;

    ft_printf("%3.7i\n", 3267);
    ft_printf("%3.7d\n", 3267);
    ft_printf("%3.7d\n", 3267);
    ft_printf("-->|%-4.*u|<--\n", -4, u);
    ft_printf("-->|%#-4.3x|<--\n", 1);
    ft_printf("%.3d\n", 10);
    ft_printf("%.3d\n", 10000);
    ft_printf("%.0d\n", 0);
    ft_printf("%.5s\n", "Hello 42!!");
    ft_printf("%.5s\n", "abc");

    ft_printf("%1s\n", "abc");

    ft_printf("%#x\n", 10);
    ft_printf("%#X\n", 16);
    ft_printf("%#o\n", 8);
    
    ft_printf("%+d\n", 10);
    ft_printf( "%-d\n", 15);

    ft_printf("%%\n");
    ft_printf("%#+09.5lf\n", 1.7E+3);
    ft_printf("%-10.10s\n","truncateiftoolong");
    ft_printf("%8.5f\n", 1.234 );

    ft_printf("%8.5d\n", 1234 );
    ft_printf("%5s\n", "abc");
    ft_printf("%05d\n", 10);
    ft_printf("%#012x\n", 0xff);

    ft_printf("ft_printf : %*p%-135.109d\n" ,-15,(void*)15603137398285451084lu,1482420587);
    ft_printf("ft_printf : %*p\n" ,-15,(void*)15603137398285451);
    // ft_printf("%21747483648.2147483648d", 125);
    ft_printf("%120p\n" ,(void*)9377650025287837451lu);

    while(1);
}
