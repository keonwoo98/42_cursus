#include "minishell.h"

int
	main(int argc, char **argv, char **envp)
{
	char		*line;

	while (1)
	{
		line = readline("\033[32mMinishell>\033[0m ");
		// rl_replace_line("", 0);
		add_history(line);
		free(line);
	}
	return (EXIT_SUCCESS);
}
