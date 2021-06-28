/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:40:21 by keokim            #+#    #+#             */
/*   Updated: 2021/06/28 19:40:26 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int					main(int argc, char **argv, char **envp)
{
	pid_t			pid;
	int				fd[2];

	if (argc != 5)
	{
		ft_putendl_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (0);
	}
	if (pipe(fd) == -1)
	{
		ft_putendl_fd("pipe fail", 2);
		return (0);
	}
	if ((pid = fork()) < 0)
	{
		ft_putendl_fd("fork fail", 2);
		return (0);
	}
	if (pid == 0)
		child_process(fd, argv, envp);
	else
		parent_process(fd, argv, envp);
	return (0);
}
