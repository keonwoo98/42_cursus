#include "pipex_bonus.h"

static void		remove_file(void)
{
	char		**argv;

	argv = malloc(sizeof(char *) * 3);
	argv[0] = "-f";
	argv[1] = "./file";
	argv[2] = NULL;
	if (fork() == 0)
		execve("/bin/rm", (char *const)argv, NULL);
}

void			heredoc(const char *file)
{
	int			fd;
	char		*buf;

	buf = NULL;
	fd = open("./file", O_CREAT | O_RDWR | O_TRUNC, 0644);
	write(STDOUT_FILENO, "heredoc> ", 9);
	while (get_next_line(STDIN_FILENO, &buf) != 0)
	{
		if (ft_strcmp(buf, file) == 0)
			break;
		write(STDOUT_FILENO, "heredoc> ", 9);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
	}
	close(fd);
	redirect_in("./file");
	remove_file();
}