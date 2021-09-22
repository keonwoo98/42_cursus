/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:06 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:06 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

static void
	fork_builtin(t_node *node)
{
	pid_t	pid;

	g_state.fork = 1;
	pid = fork();
	if (pid == 0)
	{
		set_pipe();
		exec_builtin(node);
		exit(g_state.exit_status);
	}
	else
	{
		if (g_state.i != 1)
		{
			close(g_state.pip[0][0]);
			close(g_state.pip[0][1]);
		}
	}
}

void
	builtin(t_node *node)
{
	while (node->next && node->type != BUILTIN)
		node = node->next;
	if (node->prev && node->prev->type == CMD)
		return ;
	if (!ft_strcmp(node->contents, "pwd") || \
		!ft_strcmp(node->contents, "echo") || \
		!ft_strcmp(node->contents, "env"))
		fork_builtin(node);
	else if (!ft_strcmp(node->contents, "exit"))
		exec_builtin(node);
	else if (node->next && !ft_strcmp(node->contents, "export") \
			&& node->next->type == PIPE)
		fork_builtin(node);
	else if (!ft_strcmp(node->contents, "cd") || \
			!ft_strcmp(node->contents, "export") || \
			(!ft_strcmp(node->contents, "unset") && g_state.ac == 1))
	{
		set_pipe();
		exec_builtin(node);
	}
}

static void
	cmd_child(t_node *node)
{
	if (g_state.exit_status == 1 && g_state.ac == 1 \
		&& g_state.redir_in == -1)
		exit(1);
	while (node->next && node->type != CMD)
	{
		if (node->next->type == PIPE)
			exit(EXIT_SUCCESS);
		node = node->next;
	}
	set_pipe();
	if (node->type == CMD)
		exec_cmd(node);
	else
		exit(EXIT_SUCCESS);
}

void
	execute_cmd(t_node *node)
{
	pid_t	pid;

	g_state.fork = 1;
	pid = fork();
	if (pid == 0)
	{
		if (node->type == DOLLAR)
		{
			exec_cmd(node);
			return ;
		}
		cmd_child(node);
	}
	else
	{
		if (g_state.i != 1)
		{
			close(g_state.pip[0][0]);
			close(g_state.pip[0][1]);
		}
	}
}

void
	execute(t_node *node)
{
	int		status;
	int		stdin;
	int		stdout;

	pre_execute(node);
	while (node)
	{
		stdin = dup(STDIN_FILENO);
		stdout = dup(STDOUT_FILENO);
		if (g_state.ac > 1)
			pipe(g_state.pip[1]);
		execute_node(node);
		backup_execute(&stdin, &stdout);
		while (node->next && node->next->type != PIPE)
			node = node->next;
		node = node->next;
	}
	if (g_state.fork)
	{
		while (waitpid(-1, &status, 0) > 0)
		{
			if (WIFEXITED(status))
				g_state.exit_status = WEXITSTATUS(status);
		}
	}
}
