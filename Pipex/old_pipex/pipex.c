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

static void		free_all(char **path, char **cmd, char *cmd_path)
{
	int			i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	free(cmd_path);
}

static void		child_process(int *fd, char **argv, char **envp)
{
	int			infile;
	char		**path;
	char		**cmd;
	char		*cmd_path;

	if ((infile = open(argv[1], O_RDONLY)) == -1)
		return (ft_putendl_fd("open fail", 2));
	close(fd[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	path = split_path(envp);
	cmd = ft_split(argv[2], ' ');
	if ((cmd_path = get_path(path, cmd[0])) == NULL)
	{
		free_all(path, cmd, cmd_path);
		return (ft_putendl_fd("command not found", 2));
	}
	if ((execve(cmd_path, cmd, envp)) == -1)
	{
		free_all(path, cmd, cmd_path);
		return (ft_putendl_fd("exevc fail", 2));
	}
	free_all(path, cmd, cmd_path);
}

static void		parent_process(int *fd, char **argv, char **envp)
{
	int			outfile;
	char		**path;
	char		**cmd;
	char		*cmd_path;

	if ((outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
		return (ft_putendl_fd("open fail", 2));
	wait(0);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[0]);
	path = split_path(envp);
	cmd = ft_split(argv[3], ' ');
	if ((cmd_path = get_path(path, cmd[0])) == NULL)
	{
		free_all(path, cmd, cmd_path);
		return (ft_putendl_fd("command not found", 2));
	}
	if ((execve(cmd_path, cmd, envp)) == -1)
	{
		free_all(path, cmd, cmd_path);
		return (ft_putendl_fd("exevc fail", 2));
	}
	free_all(path, cmd, cmd_path);
}

int				main(int argc, char **argv, char **envp)
{
	pid_t		pid;
	int			fd[2];

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
	pid = fork();
	if (pid == -1)
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
