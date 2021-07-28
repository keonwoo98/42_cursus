#include "push_swap.h"

int
	my_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

void
	validate(char **argv, t_stack **a)
{
	int			i;
	int			j;
	int			k;
	char		**split;

	i = 0;
	while (argv[++i])
	{
		if (my_strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			j = -1;
			while (split[++j])
				push(a, ft_atoi(split[j]));
			k = -1;
			while (split[++k])
				free(split[k]);
			free(split);
			split = NULL;
		}
		else
			push(a, ft_atoi(argv[i]));
	}
}