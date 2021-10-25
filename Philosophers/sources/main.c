#include "philo.h"

int
	ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int
	error_msg(char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
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
	is_num(char **argv)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int
	init_arg(t_arg *arg, int argc, char **argv)
{
	if (!is_num(argv))
		return (1);
	arg->num_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		arg->num_of_must_eat = ft_atoi(argv[5]);
		if (arg->num_of_must_eat <= 0)
			return (1);
	}
	else
		arg->num_of_must_eat = -1;
	if (arg->num_of_philo <= 0 || arg->time_to_die <= 0 ||\
		arg->time_to_eat <= 0 || arg->time_to_sleep <= 0)
		return (1);
	return (0);
}

long long
	get_time(void)
{
	long long		ret;
	struct timeval	time;

	ret = 0;
	if (gettimeofday(&time, NULL) == -1)
		error_msg("gettimeofday fail");
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

int
	init_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->forks, NULL))
		return (1);
}

int
	init_philo(t_arg *arg)
{
	int			i;

	i = 0;
	arg->timestamp = get_time();
	pthread_mutex_init(&arg->write_mutex, NULL);
	pthread_mutex_init(&arg->dead, NULL);
	pthread_mutex_init(&arg->time_eat, NULL);
	pthread_mutex_init(&arg->finish, NULL);
	while (i < arg->num_of_philo)
	{
		if (init_mutex(&arg->philo[i]))
			return (1);
		i++;
	}
	return (0);
}

int
	main(int argc, char **argv)
{
	t_arg		arg;

	if (argc != 5 && argc != 6)
		return (error_msg("Wrong amount of arguments"));
	if (init_arg(&arg, argc, argv))
		return (error_msg("Invalid arguments"));
	arg.philo = (t_philo *)malloc(sizeof(t_philo) * arg.num_of_philo);
	if (!arg.philo)
		return (error_msg("Malloc fail"));
	if (init_philo(&arg))
		return (error_msg("Initialize fail"));
	return (0);
}