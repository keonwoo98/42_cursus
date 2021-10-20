#include "philo.h"

int
	error_msg(char *msg)
{
	int			len;

	len = 0;
	while (msg[len])
		len++;
	write(2, "Error: ", 7);
	write(2, msg, len);
	write(2, "\n", 1);
	return (1);
}

int
	ft_atoi(const char *str)
{
	long		nbr;
	long		sign;
	size_t		i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
	}
	return (nbr * sign);
}

int
	init_philo(t_philo *philo, char **argv)
{
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	return (0);
}

int
	main(int argc, char **argv)
{
	t_philo		philo;

	if (argc != 5 && argc != 6)
		return (error_msg("Wrong amount of arguments"));
	if (init_philo(&philo, argv))
		return (error_msg("Initializing"));
}