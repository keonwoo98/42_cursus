/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:07:26 by keokim            #+#    #+#             */
/*   Updated: 2021/06/14 16:41:40 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = 0;
	return (str);
}

char			*ft_strjoin_free(char const *s1, char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = 0;
	free(s2);
	return (str);
}

size_t			get_len(int nb)
{
	size_t		len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

size_t			get_ulen(unsigned int nb)
{
	size_t		len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

size_t			get_hexlen(unsigned int nb)
{
	int			len;

	len = 1;
	while ((nb /= 16) >= 1)
		len++;
	return (len);
}
