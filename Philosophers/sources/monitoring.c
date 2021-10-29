#include "philo.h"

int
	monitor_cnt_eat(t_arg *arg)
{
	if (arg->num_of_ate == arg->num_of_philo)
	{
		if (pthread_mutex_lock(&(arg->print_mutex)) == 0)
		{
			printf("All philosophers have finished their meals\n");
			usleep(100);
			pthread_mutex_unlock(&(arg->main_mutex));
			return (EXIT_SUCCESS);
		}
		return (EXIT_FAILURE);
	}
	return (-1);
}

int
	monitor_health(t_arg *arg, int i)
{
	if (get_time() - arg->philo[i].die_start_time > arg->time_to_die)
	{
		if (pthread_mutex_lock(&(arg->dead_mutex)) == 0)
		{
			arg->philo[i].stat = 4;
			print_message(&(arg->philo[i]), "dead\t\t");
			arg->all_ate = 1;
			usleep(100);
			pthread_mutex_unlock(&(arg->main_mutex));
			return (EXIT_SUCCESS);
		}
		return (EXIT_SUCCESS);
	}
	return (-1);
}

void
	*monitoring(void *arg)
{
	int			i;
	t_arg		*a;

	a = (t_arg *)arg;
	i = 0;
	while (1)
	{
		if (a->all_ate)
			return (EXIT_SUCCESS);
		if (i == a->num_of_philo)
			i = 0;
		if (monitor_cnt_eat(a) == EXIT_FAILURE)
			return ((void *)EXIT_FAILURE);
		if (monitor_health(a, i) == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		i++;
		usleep(100);
	}
}
