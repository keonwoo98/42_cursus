/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:23:36 by keokim            #+#    #+#             */
/*   Updated: 2021/06/08 10:23:40 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void            init_format(t_format *format)
{
    format->ret = 0;
    format->minus = 0;
    format->zero = 0;
    format->plus = 0;
    format->blank = 0;
    format->sharp = 0;
    format->width = 0;
    format->prec = -1;
    format->type = 0;
}

void            find_format(const char *str, t_format *format)
{
    init_format(format);
    while (*str && !ft_strchr("csdpsuixX%", *str))
    {
        if (*str == '-')
            format->minus = 1;
        else if (*str == '0' && format->width == 0 && format->prec == -1 && format->minus == 0)
            format->zero = 1;
        // '0'플래그가 존재할 경우 동시에 너비, 정밀도, 정렬 플래그 옵션이 이미 설정되어 있는지 검사해준다
        // '0'플래그의 위치가 아닌 다른 플래그에서 '0'문자가 존재할 수 있는 경우를 방지
        // minus플래그 검사 이유는 while문 수행 후 '0'플래그 무시 조건 if문에서
        // '%'타입에 대해서는 처리를 하지 않기 때문에 여기서 '%'타입 처리를 대비
        // %-05.%
        else if (*str == '+')
            format->plus = 1;
        else if (*str == ' ')
            format->blank = 1;
        else if (*str == '#')
            format->sharp = 1;
        else if (*str == '.')
            format->prec = 0;
        else if (ft_isdigit(*str) || *str == '*')
            format = width_prec(format, *str);
        str++;
    }
    format->type = *str;
    if ((format->prec >= 0 || format->minus > 0) && format->type != '%')
        format->zero = 0;
    // '.' 또는 '-'플래그가 존재하고 '%'타입이 아닐 경우 '0'플래그를 0으로 설정하여 무시
    chk_type(format);
}


t_format        *width_prec(t_format *format, char c)
{   // 너비 저장하는 함수
    if (ft_isdigit(c))      // 너비 값이 고정 인자 문자열에 존재할 경우
    {
        if (format->prec == -1)     // 정밀도가 고정 인자에 없을 경우
        {
            format->width = (format->width * 10) + (c - '0');
            // 문자를 정수형으로 변환
            return (format);
        }
        else        // 정밀도가 고정 인자 문자열에 있는 경우
        {
            format->prec = (format->prec * 10) + (c - '0');
            return (format);
        }
    }
    else if (c == '*')      // 숫자 와일드카드, 가변 인자로 값이 들어올 경우
    {
        if (format->prec == -1)
        {
            if ((format->width = va_arg(format->ap, int)) < 0)
            {
                format->minus = 1;
                // 만약 너비에 대한 가변 인자 값이 음수일 경우 '-'부호를 플래그로 인식하도록 minus 변수를 1로 설정
                format->width *= -1;     // 너비는 양수로 변경
                format->zero = 0;       // zero 변수는 0으로 설정하여 무시 ('%' 타입 대비)
            }
        }
        else
        {
            if ((format->prec = va_arg(format->ap, int)) < 0)
                format->prec = -1;
            // 가변 인자로 받아온 정밀도 너비가 음수일 경우 prec 변수를 -1로 설정하여 정밀도 처리 무시
        }
    }
    return (format);
}
