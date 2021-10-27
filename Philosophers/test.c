#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void
	thread(void)
{
	int					i;
	pthread_t			philo;

	i = 0;
	while (i < 5)
	{
		if (pthread_create(&philo, NULL, &routine, (void *)&common) != 0)
			return (1);
		if (pthread_detach(philo) != 0)
			return (1);
		i++;
	}
}

pthread_mutex_t
	*init_forks(void)
{
	int					i;
	pthread_mutex_t		*forks;

	if (!(forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 5)))
		return (NULL);
	i = 0;
	while (i < 5)
	{
		if (pthread_mutex_init(&forks[i], NULL) < 0)
		{
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void
	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->lfork);
	pthread_mutex_lock(p->rfork);
}

void
	sleep_forks(t_philo *p)
{
	pthread_mutex_unlock(p->lfork);
	pthread_mutex_unlock(p->rfork);
}

t_philo
	*init_philo(void)
{
	int					i;
	t_philo				*philo;
	pthread_mutex_t		*forks;

	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * 5)))
		return (NULL);
	if (!(forks = init_forks()))
		return (NULL);
	i = 0;
	while (i < 5)
	{
		philo[i].rfork = &forks[(i + 1) % 5];
		philo[i].lfork = &forks[i];
		i++;
	}
	return (philo);
}

t_common_info
	*init_check_died_mutex(void)
{
	pthread_mutex_t		*check_died;

	if (!(check_died = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return (NULL);
	pthread_mutex_lock(check_died);
	return (check_died);
}

int
	start_pthread(t_philo *p)
{
	int					i;

	i = 0;
	while (i < p->info->num_philo)
	{
		if (pthread_create(&(p[i].pthread), NULL, &routine, (void *)&(p[i])) != 0)
			return (1);
		if (pthread_detach(p[i].pthread) != 0)
			return (1);
		i++;
	}
	if (pthread_create(p->info->monitor, NULL, &monitoring, (void *)p) != 0)
		return (1);
	if (pthread_detach(*p->info->monitor) != 0)
		return (1);
	pthread_mutex_lock(p->info->check_died);
	pthread_mutex_unlock(p->info->check_died);
	return (0);
}

void
	*monitoring(void *philo)
{
	t_philo				*p;
	int					i;
	long long			last_meal_ms;
	struct timeval		time_now;

	p = (t_philo *)philo;
	while (1)
	{
		i = -1;
		usleep(50);
		while (++i < 5)
		{
			last_meal_ms = change_to_ms(p[i].last_meal);
			gettimeofday(&time_now, NULL);
			if (last_meal_ms + p->info->time_to_die < change_to_ms(time_now))
			{
				print_state(&p[i], STATE_DIED);
				pthread_mutex_unlock(p->info->check_died);
				return ((void *)0);
			}
		}
	}
	return ((void *)0);
}

void
	*routine(void *philo)
{
	t_philo				*p;

	p = (t_philo *)philo;
	if (pthread_create(p->info->child_monitor, NULL, &monitoring_philo_died, (void *)p) != 0)
		return ((void *)1);
	if (pthread_detach(*p->info->child_monitor) != 0)
		return ((void *)1);
	while (1)
	{
		take_forks(p);
		eat_spaghetti(p);
		sleep_philo(p);
		think_philo(p);
	}
	return ((void *)0);
}

void
	print_state(t_philo *p, int state)
{
	long long			created_ms;
	long long			current_ms;
	long long			timestamp_ms;

	created_ms = p->created;
	current_ms = now_time();
	timestamp_ms = current_ms - created_ms;
	pthread_mutex_lock(p->info->print_m);
	if (state == STATE_FORK)
		printf("%llu %d has taken a fork\n", timestamp_ms, p->philo_num);
	else if (state == STATE_EAT)
		printf("%llu %d is eating\n", timestamp_ms, p->philo_num);
	else if (state == STATE_SLEEP)
		printf("%llu %d is sleeping\n", timestamp_ms, p->philo_num);
	else if (state == STATE_THINK)
		printf("%llu %d is thinking\n", timestamp_ms, p->philo_num);
	else if (state == STATE_DIED)
	{
		printf("%llu %d died\n", timestamp_ms, p->philo_num);
		return ;
	}
	pthread_mutex_unlock(p->info->print_m);
}
