/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:20 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:41:21 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void
	display_prompt(char **line)
{
	*line = readline("\033[32mMinishell>\033[0m ");
	if (*line == NULL)
	{
		ft_putstr_fd("\x1b[1A", 1);
		ft_putstr_fd("\033[11C", 1);
		ft_putstr_fd("exit\n", 1);
		exit(1);
	}
	else if (**line)
		add_history(*line);
}

void
	allocate_env(int argc, char **argv, char **envp)
{
	int			i;

	i = 0;
	(void)argc;
	(void)argv;
	g_state.env = (char **)malloc(sizeof(char *) * 1024);
	while (i < environ_len(envp))
	{
		g_state.env[i] = ft_strdup(envp[i]);
		i++;
	}
	g_state.env[i] = NULL;
}

int
	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_cmd		*cmd;

	rl_catch_signals = 0;
	set_signal();
	allocate_env(argc, argv, envp);
	ft_putendl_fd("\033[36m-----------Welcome to Minishell-----------\033[0m", 1);
	while (1)
	{
		display_prompt(&line);
		if (parse_line(&cmd, line) || !cmd->size || check_redir(cmd))
		{
			error_return(cmd, line);
			continue ;
		}
		assign_arg(cmd);
		expansion(&cmd);
		remove_blank(&cmd);
		execute(cmd->first);
		free_list(cmd);
		free(line);
	}
	free_str(g_state.env);
}
