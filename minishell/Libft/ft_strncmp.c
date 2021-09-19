/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:21:44 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/06 16:24:19 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (*s1 && *s2 && index < n)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			break ;
		s1++;
		s2++;
		index++;
	}
	if (index == n)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
