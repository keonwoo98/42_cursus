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

#include "pipex_bonus.h"

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

void			redirect_in(const char *file)
{
	int			infile;

	infile = open(file, O_RDONLY);
	if (infile < 0)
	{
		perror("open fail");
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
}

void			redirect_out(const char *file)
{
	int			outfile;

	outfile = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("open fail");
		exit(1);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

void			connect_pipe(int fd[2], int io)
{
	dup2(fd[io], io);
	close(fd[0]);
	close(fd[1]);
}

void			exe_cmd(int ac, char **argv, char **envp)
{
	char		**path;
	char		**cmd;
	char		*cmd_path;

	path = split_path(envp);
	cmd = ft_split(argv[ac], ' ');
	if ((cmd_path = get_path(path, cmd[0])) == NULL)
	{
		free_all(path, cmd, cmd_path);
		perror("command not found");
		exit(1);
	}
	if ((execve(cmd_path, cmd, envp)) == -1)
	{
		free_all(path, cmd, cmd_path);
		perror("exevc fail");
		exit(1);
	}
	free_all(path, cmd, cmd_path);
}

int				main(int argc, char **argv, char **envp)
{
	pid_t		pid;
	int			fd[2];

	if (argc < 5)
	{
		perror("incorrect parameter");
		return (0);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe fail");
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork fail");
		return (0);
	}
	if (pid == 0)
	{
		heredoc(argv[1]);
		// redirect_in(argv[1]);
		connect_pipe(fd, STDOUT_FILENO);
		exe_cmd(3, argv, envp);
	}
	else
	{
		wait(0);
		redirect_out(argv[argc - 1]);
		connect_pipe(fd, STDIN_FILENO);
		exe_cmd(argc - 2, argv, envp);
	}
	return (0);
}
