/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:08:43 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/10 10:10:41 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	length;
	unsigned int	index;

	if (!s || !f)
		return (0);
	length = ft_strlen(s);
	index = 0;
	ret = (char *)malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	while (index < length)
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
