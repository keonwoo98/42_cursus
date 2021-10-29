#include "philo.h"

void
	print_message(t_philo *p, char *str)
{
	if (p->arg->all_ate)
		return ;
	if (pthread_mutex_lock(&(p->arg->print_mutex)) == 0)
	{
		printf("%llums\t%d\t%s\t[%d]\n", \
			get_time() - p->arg->start_time, p->num, str, p->eat_cnt);
		if (p->stat != 4)
			pthread_mutex_unlock(&(p->arg->print_mutex));
	}
}

int
	start_thread(t_arg *arg, int num)
{
	pthread_t		thread_id;

	while (num < arg->num_of_philo)
	{
		if (pthread_create(&thread_id, NULL, &routine, \
			(void *)(&(arg->philo[num]))) != 0)
			return (EXIT_FAILURE);
		if (pthread_detach(thread_id) != 0)
			return (EXIT_FAILURE);
		num += 2;
	}
	if (num % 2 == 0)
		usleep(500 * arg->time_to_eat);
	return (EXIT_SUCCESS);
}

int
	dining(t_arg *arg)
{
	pthread_t		thread_id;

	arg->start_time = get_time();
	if (start_thread(arg, EVEN) || start_thread(arg, ODD))
		return (EXIT_FAILURE);
	if (pthread_create(&thread_id, NULL, &monitoring, arg) != 0)
		return (EXIT_FAILURE);
	if (pthread_detach(thread_id) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
