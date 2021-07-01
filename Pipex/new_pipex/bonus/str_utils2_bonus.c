/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:41:23 by keokim            #+#    #+#             */
/*   Updated: 2021/07/01 14:41:26 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	size_t 		cnt;

	cnt = 0;
	while (s1[cnt] || s2[cnt])
	{
		if (s1[cnt] != s2[cnt])
			return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
		if (!s1[cnt] || !s2[cnt])
			return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
		++cnt;
	}
	return (0);
}

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t			ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	size_t		src_len;
	size_t		i;

	i = 0;
	src_len = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

char			*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*str;

	len = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
