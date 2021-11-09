#include "philo.h"

void
	taking_forks(t_philo *p, t_arg *a)
{
	p->state = TAKE_FORK;
	pthread_mutex_lock(p->right_fork);
	print_philo(p, a, "has taken a right fork");
	pthread_mutex_lock(p->left_fork);
	print_philo(p, a, "has taken a left fork");
}

void
	eating(t_philo *p, t_arg *a)
{
	// long long	start_eating;

	// pthread_mutex_lock(&a->eat_mutex);
	p->last_ate = get_time();
	p->is_dead = p->last_ate + a->time_to_die;
	p->state = EATING;
	// start_eating = get_time();
	print_philo(p, a, "is eating");
	// while (get_time() - start_eating < a->time_to_eat)
	// 	usleep(100);
	p->eat_cnt++;
	if (p->eat_cnt >= a->num_of_must_eat)
		a->num_of_end++;
	ft_usleep(a->time_to_eat * 1000);
	// pthread_mutex_unlock(&a->eat_mutex);
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

void
	sleeping(t_philo *p, t_arg *a)
{
	// long long	start_sleeping;

	p->state = SLEEPING;
	// start_sleeping = get_time();
	print_philo(p, a, "is sleeping");
	ft_usleep(a->time_to_sleep * 1000);
	// while (get_time() - start_sleeping < a->time_to_sleep)
	// 	usleep(100);
}

void
	thinking(t_philo *p, t_arg *a)
{
	p->state = THINKING;
	print_philo(p, a, "is thinking");
}

void	ft_usleep(int n)
{
	struct timeval	start;
	struct timeval	step;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&step, NULL);
		if (((step.tv_sec - start.tv_sec) * 1000000
				+ (step.tv_usec - start.tv_usec)) > n)
			break ;
	}
}

void
	*monitor(void *philo)
{
	t_arg		*a;
	t_philo		*p;

	p = (t_philo *)philo;
	a = p->arg;
	while (1)
	{
		pthread_mutex_lock(&a->eat_mutex);
		if (a->num_of_must_eat > 0 && a->num_of_end >= a->num_of_philo)
		{
			a->end = 1;
			pthread_mutex_lock(&a->print_mutex);
			printf(CYAN"All philosophers have finished their meals\n"RESET);
			pthread_mutex_unlock(&a->print_mutex);
			pthread_mutex_unlock(&a->eat_mutex);
			pthread_mutex_unlock(&a->philo_mutex);
			return ((void *)EXIT_SUCCESS);
		}
		if (get_time() > p->is_dead)
		{
			a->dead = 1;
			print_philo(p, a, "dead");
			pthread_mutex_unlock(&a->eat_mutex);
			pthread_mutex_unlock(&a->philo_mutex);
			return ((void *)EXIT_SUCCESS);
		}
		pthread_mutex_unlock(&a->eat_mutex);
		ft_usleep(1000);
	}
}

void
	*routine(void *philo)
{
	t_philo		*p;
	t_arg		*a;
	pthread_t	t_id;

	p = (t_philo *)philo;
	a = p->arg;
	if (pthread_create(&t_id, NULL, &monitor, p) != 0)
		return ((void *)EXIT_FAILURE);
	if (pthread_detach(t_id) != 0)
		return ((void *)EXIT_FAILURE);
	p->last_ate = get_time();
	// p->last_ate = a->start_time;
	p->is_dead = p->last_ate + a->time_to_die;
	while (1)
	{
		if (a->dead || a->end)
			break ;
		taking_forks(p, a);
		eating(p, a);
		sleeping(p, a);
		thinking(p, a);
		usleep(100);
	}
	return ((void *)EXIT_SUCCESS);
}
