#include <unistd.h>

void			solve(char *s1, char *s2)
{
	int			i;
	int			ascii[256] = { 0 };

	i = 0;
	while (s2[i])
	{
		if (ascii[(int)s2[i]] == 0)
			ascii[(int)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (ascii[(int)s1[i]] == 1)
		{
			ascii[(int)s1[i]] = 2;
			write(1, &s1[i], 1);
		}
		i++;
	}
}

int				main(int ac, char **av)
{
	if (ac == 3)
		solve(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}