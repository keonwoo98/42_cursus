/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:51 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:41:51 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <readline/readline.h>

static void
	is_sigint(int pid, int status)
{
	if (pid == -1 && !WEXITSTATUS(status))
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		if (!WIFEXITED(status))
			ft_putstr_fd("\n", 1);
	}
}

static void
	is_sigquit(int pid, int status)
{
	if (pid == -1 && !WEXITSTATUS(status))
		return ;
	else
	{
		if (!WIFEXITED(status))
			ft_putstr_fd("Quit: 3\n", 1);
	}
}

static void
	handle_signal(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, 0);
	if (signo == SIGINT)
		is_sigint(pid, status);
	else if (signo == SIGQUIT)
		is_sigquit(pid, status);
}

void
	set_signal(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}
