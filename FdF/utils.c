/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:27:33 by keokim            #+#    #+#             */
/*   Updated: 2021/07/07 12:27:35 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
    is_in_base(char to_find)
{
    int     i;
    char    *base;

    i = 0;
    base = "0123456789abcdef";
    while (ft_tolower(base[i]))
    {
        if (to_find == ft_tolower(base[i]))
            return (i);
        i++;
    }
    return (-1);
}
unsigned int
    ft_atoi_base(char *nbr)
{
    unsigned int    num;

    num = 0;
    while (*nbr && is_in_base(*nbr) != -1)
    {
        num *= 16;
        num += is_in_base(*nbr);
        nbr++;
    }
    return (num);
}
