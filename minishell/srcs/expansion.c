/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:20 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:21 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int
	is_meta(char c)
{
	if (c != '>' && c != '<' && c != '+'
		&& c != '|' && c != ' ' && c != '$')
		return (1);
	else
		return (0);
}

static char
	*do_expansion(char *str, char *last)
{
	char	*temp;

	if (get_env(str))
		temp = ft_strjoin_free(get_env_str(str), last);
	else if (ft_isdigit(str[0]))
		temp = ft_substr(str, 1, ft_strlen(str));
	else if (str[0] == '?')
	{
		if (ft_strlen(str) > 1)
		{
			free(last);
			last = ft_substr(str, 1, ft_strlen(str));
		}
		temp = ft_strjoin_free(ft_itoa(g_state.exit_status), last);
	}
	else
		temp = ft_strjoin("", last);
	return (temp);
}

static char
	*substr_expansion(char *contents, int *start)
{
	char	*str;
	char	*last;
	char	*temp;
	int		i;

	i = *start;
	while (contents[i] && is_meta(contents[i]))
		i++;
	str = ft_substr(contents, *start, i - *start);
	last = ft_substr(contents, i, ft_strlen(contents));
	temp = do_expansion(str, last);
	free(str);
	free(last);
	*start = i;
	return (temp);
}

static void
	parse_expansion(char **contents)
{
	char	*temp;
	char	*str;
	int		i;

	i = 0;
	while ((*contents)[i])
	{
		if ((*contents)[i] == '$')
		{
			str = ft_substr(*contents, 0, i);
			i++;
			temp = substr_expansion(*contents, &i);
			free(*contents);
			*contents = ft_strjoin(str, temp);
			free(str);
			free(temp);
		}
		else
			i++;
	}
}

void
	expansion(t_cmd **cmd)
{
	t_node	*node;

	node = (*cmd)->first;
	while (node)
	{
		if (ft_strchr(node->contents, '$') \
			&& node->type >= DQUOTE && node->type != SQUOTE)
		{
			parse_expansion(&node->contents);
			node->type = DOLLAR;
		}
		if (node)
			node = node->next;
	}
}
