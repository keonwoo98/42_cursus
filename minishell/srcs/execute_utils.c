/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:12 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:13 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

void
	connect_redirect(t_node *node)
{
	g_state.redir_in = 0;
	g_state.redir_out = 1;
	while (node->next && node->next->type != PIPE)
	{
		if (node->type == REDIROUT)
			redirect_out(node->next->contents);
		else if (node->type == REDIRIN)
			redirect_in(node->next->contents);
		else if (node->type == APPEND)
			redirect_out_append(node->next->contents);
		else if (node->type == HEREDOC)
			here_doc(node->next);
		node = node->next;
	}
}

void
	set_pipe(void)
{
	if (g_state.i != 1 && g_state.redir_in == 0 && \
		g_state.exit_status != -1)
		connect_pipe(g_state.pip[0], STDIN_FILENO);
	if (g_state.i < g_state.ac && g_state.redir_out == 1 && \
		g_state.exit_status != -1)
		connect_pipe(g_state.pip[1], STDOUT_FILENO);
	if (g_state.redir_in != 0)
	{
		dup2(g_state.redir_in, STDIN_FILENO);
		close(g_state.redir_in);
	}
	if (g_state.redir_out != 1)
	{
		dup2(g_state.redir_out, STDOUT_FILENO);
		close(g_state.redir_out);
	}
}

void
	pre_execute(t_node *node)
{
	t_node	*temp;

	temp = node;
	g_state.i = 1;
	g_state.ac = 1;
	g_state.fork = 0;
	while (temp)
	{
		if (temp->type == PIPE)
			g_state.ac++;
		temp = temp->next;
	}
}

void
	backup_execute(int *stdin, int *stdout)
{
	g_state.pip[0][0] = g_state.pip[1][0];
	g_state.pip[0][1] = g_state.pip[1][1];
	dup2(*stdin, STDIN_FILENO);
	dup2(*stdout, STDOUT_FILENO);
	close(*stdin);
	close(*stdout);
	g_state.i++;
}

void
	execute_node(t_node *node)
{
	connect_redirect(node);
	if (g_state.exit_status == 1 && g_state.redir_in == -1)
		return ;
	execute_cmd(node);
	builtin(node);
}
