#include "philo.h"

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

void
	print_state(long long timestamp, int id, char *state)
{
	long long	time;

	time = -1;
	time = get_time() - timestamp;
	if (time >= 0 && time <= 2147483647)
		printf("%lld %d %s\n", time, id, state);
}

void
	destroy_mutex(t_arg *arg)
{
	int			i;

	pthread_mutex_unlock(&(arg->dead_mutex));
	i = 0;
	while (i < arg->num_of_philo)
		pthread_mutex_destroy(&(arg->forks_mutex[i++]));
	pthread_mutex_destroy(&(arg->main_mutex));
	pthread_mutex_destroy(&(arg->dead_mutex));
	pthread_mutex_destroy(&(arg->print_mutex));
	free(arg->forks_mutex);
	free(arg->philo);
}

int
	main(int argc, char **argv)
{
	t_arg		arg;

	if (argc != 5 && argc != 6)
		return (error_msg("Wrong amount of arguments"));
	if (init_arg(&arg, argc, argv))
		return (error_msg("Invalid arguments"));
	if (malloc_arg(&arg))
		return (error_msg("Malloc error"));
	if (init_philo(&arg) || init_mutex(&arg))
		return (error_msg("Initialize error"));
	if (dining(&arg))
		return (error_msg("Thread error"));
	if (pthread_mutex_lock(&(arg.main_mutex)) == 0)
		if (pthread_mutex_unlock(&(arg.main_mutex)) == 0)
			destroy_mutex(&arg);
	return (0);
}
