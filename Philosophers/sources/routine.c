#include "philo.h"

void
	take_forks(t_philo *p)
{
	p->stat = 1;
	if (pthread_mutex_lock(p->right_fork) == 0)
		print_message(p, "has taken a fork R");
	else
		pthread_mutex_unlock(&(p->arg->main_mutex));
	if (pthread_mutex_lock(p->left_fork) == 0)
		print_message(p, "has taken a fork L");
	else
		pthread_mutex_unlock(&(p->arg->main_mutex));
}

void
	p_eat(t_philo *p)
{
	p->stat = 2;
	p->die_start_time = get_time();
	print_message(p, "is eating\t");
	while (get_time() - p->die_start_time < p->arg->time_to_eat)
		usleep(100);
	(p->eat_cnt)++;
	if (p->eat_cnt == p->arg->num_of_must_eat && p->starve == 0)
	{
		p->starve = 1;
		(p->arg->num_of_full)++;
	}
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void
	p_sleep(t_philo *p)
{
	long long	slp_start_time;

	p->stat = 3;
	slp_start_time = get_time();
	print_message(p, "is p_sleeping\t");
	while (get_time() - slp_start_time < p->arg->time_to_sleep)
		usleep(100);
}

void
	p_think(t_philo *p)
{
	p->stat = 0;
	print_message(p, "is thinking\t");
}

void
	*routine(void *philo)
{
	t_philo		*p;

	p = (t_philo *)philo;
	p->die_start_time = p->arg->start_time;
	while (p->arg->end != 1)
	{
		take_forks(p);
		p_eat(p);
		p_sleep(p);
		p_think(p);
		usleep(100);
	}
	return ((void *)EXIT_SUCCESS);
}
