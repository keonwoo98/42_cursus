/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:58:57 by keokim            #+#    #+#             */
/*   Updated: 2021/06/28 19:59:06 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char			**ft_malloc_free(char **tab)
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

static size_t		count_word(char const *str, char c)
{
	size_t			count;
	size_t			i;

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

static size_t		count_str(char const *str, char c)
{
	size_t			count;
	size_t			i;

	i = 0;
	count = 0;
	while (str[i] != c && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

char				**ft_split(char const *s, char c)
{
	char			**ret;
	int				j;
	int				k;

	if (!s)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1))))
		return (NULL);
	k = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (count_str(s, c) == 0)
			break ;
		if (!(ret[k] = (char *)malloc(sizeof(char) * (count_str(s, c) + 1))))
			return (ft_malloc_free(ret));
		while (*s && *s != c)
			ret[k][j++] = *s++;
		ret[k++][j] = '\0';
	}
	ret[k] = NULL;
	return (ret);
}
