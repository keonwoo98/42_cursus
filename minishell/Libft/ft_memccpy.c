/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:05:57 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/06 13:08:16 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	flag;

	flag = 0;
	while (n > 0 && !flag)
	{
		if (*(unsigned char *)src == (unsigned char)c)
			flag = 1;
		*(unsigned char *)dest++ = *(unsigned char *)src++;
		n--;
	}
	if (flag == 1)
		return (dest);
	else
		return (NULL);
}
