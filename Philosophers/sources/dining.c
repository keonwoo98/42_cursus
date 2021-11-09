#include "philo.h"

int
	start_thread(t_arg *arg, int num)
{
	pthread_t		t_id;

	while (num < arg->num_of_philo)
	{
		if (pthread_create(&t_id, NULL, &routine, &arg->philo[num]) != 0)
			return (EXIT_FAILURE);
		if (pthread_detach(t_id) != 0)
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
	pthread_mutex_lock(&arg->philo_mutex);
	arg->start_time = get_time();
	if (start_thread(arg, EVEN) || start_thread(arg, ODD))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
