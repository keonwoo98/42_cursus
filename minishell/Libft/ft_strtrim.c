/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:15:01 by minjkim2          #+#    #+#             */
/*   Updated: 2021/05/10 10:15:21 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]) && end >= start && s1[end])
		end--;
	if (start >= end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + start, end - start + 2);
	return (ret);
}
