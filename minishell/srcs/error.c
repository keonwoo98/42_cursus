/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:39:33 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:39:34 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

void
	error_return(t_cmd *cmd, char *line)
{
	free_list(cmd);
	free(line);
}

void
	error_exit(char *str)
{
	if (errno == 0)
	{
		ft_putstr_fd(str, 2);
		write(2, "\n", 1);
	}
	else
		perror(str);
	exit(EXIT_FAILURE);
}

void
	syntax_error(char c)
{
	if (c == '\\')
		ft_putstr_fd("Minishell: syntax error near unexpected token `\\'\n", 2);
	else
		ft_putstr_fd("Minishell: syntax error near unexpected token `;'\n", 2);
	g_state.exit_status = 258;
}
