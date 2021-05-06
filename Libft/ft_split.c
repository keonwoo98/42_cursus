/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:04:56 by keokim            #+#    #+#             */
/*   Updated: 2021/05/06 19:51:06 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

size_t			count_word(char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

size_t			count_str(char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i] != c && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	int		j;
	int		k;

	ret = (char **)malloc(sizeof(char *) * (count_word(s) + 1));
	if (!ret)
		return (NULL);
	k = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (!(ret[k] = (char *)malloc(sizeof(char) * (count_str(s) + 1))))
			return (ft_malloc_error(ret));
		while (*s && *s != c)
		{
			ret[k][j] = *s;
			s++;
			j++;
		}
		while (*s && *s == c)
			s++;
		ret[k][j] = '\0';
		k++;
	}
	ret[k] = NULL;
	return (ret);
}
