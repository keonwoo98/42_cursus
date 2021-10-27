#include "philo.h"

void
	print_message(t_philo *p, char *str)
{
	if (p->arg->end)
		return ;
	if (pthread_mutex_lock(&(p->arg->print_mutex)) == 0)
	{
		printf("%llums\t%d\t%s\t[%d]\n", get_time() - p->arg->start_time, p->num, str, p->eat_cnt);
		if (p->stat != 4)
			pthread_mutex_unlock(&(p->arg->print_mutex));
	}
}

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
	t_philo			*p;

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

int
	monitor_cnt_eat(t_arg *arg)
{
	if (arg->num_of_full == arg->num_of_philo)
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
			arg->end = 1;
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
	int					i;
	t_arg				*a;
 
	a = (t_arg *)arg;
	i = 0;
	while (1)
	{
		if (a->end)
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

int
	start_pthread(t_arg *arg, int num)
{
	pthread_t		thread_id;

	while (num < arg->num_of_philo)
	{
		if (pthread_create(&thread_id, NULL, &routine, (void *)(&(arg->philo[num]))) != 0)
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
	if (start_pthread(arg, EVEN) || start_pthread(arg, ODD))
		return (EXIT_FAILURE);
	if (pthread_create(&thread_id, NULL, &monitoring, arg) != 0)
		return (EXIT_FAILURE);
	// if (pthread_detach(thread_id) != 0)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
