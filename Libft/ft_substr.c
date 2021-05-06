/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:53:02 by keokim            #+#    #+#             */
/*   Updated: 2021/05/06 12:56:57 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*sub_s;

	if (s == NULL)
		return (NULL);
	if (!(sub_s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	while (i < len && i + start < len_s)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
