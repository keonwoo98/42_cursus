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
	is_duplicate(t_stack *a)
{
	int			i;
	int			j;
	int			num[50];

	i = 0;
	while (a->top)
	{
		num[i] = a->top->num;
		if (a->top->next == NULL)
			break ;
		a->top = a->top->next;
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
			if (num[i] == num[j++])
				print_error_msg("duplicated");
		i++;
	}
	while (a->top->prev)
		a->top = a->top->prev;
}

int
	pos_neg(int *sign, char *str)
{
	int			i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int
	validate(char *str)
{
	int			i;
	int			sign;
	long		nbr;

	sign = 1;
	nbr = 0;
	i = pos_neg(&sign, str);
	if (ft_strlen(&str[i]) > 10)
		print_error_msg("over int range");
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = (nbr * 10) + (str[i] - '0');
		else
			print_error_msg("invalid parameter");
		i++;
	}
	if (sign == 1 && nbr > 2147483647)
		print_error_msg("overflow");
	if (sign == -1 && nbr > 2147483648)
		print_error_msg("underflow");
	return ((int)nbr * sign);
}

void
	create_list(char **argv, t_stack *a)
{
	int			i;
	int			j;
	int			k;
	int			num;
	char		**split;

	i = 0;
	while (argv[++i])
	{
		if (my_strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			j = -1;
			while (split[++j])
				num = validate(split[j]);
			k = -1;
			while (split[++k])
				free(split[k]);
			free(split);
		}
		else
			num = validate(argv[i]);
		push(a, num);
	}
}
