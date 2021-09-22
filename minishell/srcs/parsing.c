/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:25 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:41:26 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static void
	split_metacharater(int *i, char *line, t_cmd **cmd)
{
	if (line[*i] == '<' && line[*i + 1] == '<')
	{
		(*i)++;
		add_list(*cmd, ft_strdup("<<"), HEREDOC);
	}
	else if (line[*i] == '>' && line[*i + 1] == '>')
	{
		(*i)++;
		add_list(*cmd, ft_strdup(">>"), APPEND);
	}
	else if (line[*i] == '<')
		add_list(*cmd, ft_strdup("<"), REDIRIN);
	else if (line[*i] == '>')
		add_list(*cmd, ft_strdup(">"), REDIROUT);
	else if (line[*i] == '|')
		add_list(*cmd, ft_strdup("|"), PIPE);
}

static int
	check_quotes(char *line, char quote, int *i)
{
	int			index;

	index = *i;
	while (line[index])
	{
		if (line[index] == quote)
			return (0);
		index++;
	}
	print_errmsg(NULL, "Syntax Error");
	return (1);
}

static int
	split_quotes(int *i, char *line, t_cmd **cmd)
{
	char		*str;
	char		quote;
	int			tmp;

	quote = line[(*i)++];
	if (check_quotes(line, quote, i))
		return (EXIT_FAILURE);
	tmp = *i;
	while (line[*i] != quote && line[*i])
		(*i)++;
	if (*i - tmp)
	{
		str = ft_substr(line, tmp, *i - tmp);
		if (quote == '\'')
			add_list(*cmd, str, SQUOTE);
		else
			add_list(*cmd, str, DQUOTE);
	}
	return (EXIT_SUCCESS);
}

static void
	split_arguments(int *i, char *line, t_cmd **cmd)
{
	char		*str;
	int			tmp;

	tmp = *i;
	while (line[*i] && line[*i] != '<' && line[*i] != '>' && \
		line[*i] != '|' && line[*i] != ' ' && line[*i] != '"' && \
		line[*i] != '\'' && line[*i] != ';' && line[*i] != '\\')
		(*i)++;
	if (*i - tmp)
	{
		str = ft_substr(line, tmp, *i - tmp);
		add_list(*cmd, str, ARG);
	}
	(*i)--;
}

int
	parse_line(t_cmd **cmd, char *line)
{
	int		i;

	*cmd = init_cmd_list();
	i = -1;
	while (line[++i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '"' || line[i] == '\'')
		{
			if (split_quotes(&i, line, cmd))
				return (EXIT_FAILURE);
		}
		else if (line[i] == '\\' || line[i] == ';')
		{
			syntax_error(line[i]);
			return (EXIT_FAILURE);
		}
		else if (line[i] == '<' || line[i] == '>' || line[i] == '|')
			split_metacharater(&i, line, cmd);
		else
			split_arguments(&i, line, cmd);
	}
	return (EXIT_SUCCESS);
}
