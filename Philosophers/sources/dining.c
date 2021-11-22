/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:17:50 by keokim            #+#    #+#             */
/*   Updated: 2021/11/18 15:17:52 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	philo_fin(t_arg *a)
{
	a->end++;
	usleep(100);
	pthread_mutex_unlock(&a->monitor_mutex);
	pthread_mutex_unlock(&a->philo_mutex);
	pthread_mutex_lock(&a->print_mutex);
	printf(CYAN"All philosophers have finished their meals\n"RESET);
	pthread_mutex_unlock(&a->print_mutex);
}

void
	philo_dead(t_arg *a, t_philo *p)
{
	a->dead++;
	usleep(100);
	pthread_mutex_unlock(&a->monitor_mutex);
	pthread_mutex_unlock(&a->philo_mutex);
	pthread_mutex_lock(&a->print_mutex);
	printf(GREEN"%lldms\t"RESET, get_time() - p->arg->start_time);
	printf("%d\t%s\t(%d)\n", p->id + 1, "dead", p->eat_cnt);
	pthread_mutex_unlock(&a->print_mutex);
}

void
	*monitor(void *philo)
{
	t_arg		*a;
	t_philo		*p;

	p = (t_philo *)philo;
	a = p->arg;
	while (!(a->dead || a->end))
	{
		pthread_mutex_lock(&a->monitor_mutex);
		if (a->num_of_must_eat > 0 && a->num_of_end >= a->num_of_philo)
		{
			philo_fin(a);
			return ((void *)EXIT_SUCCESS);
		}
		if (get_time() > p->is_dead)
		{
			philo_dead(a, p);
			return ((void *)EXIT_SUCCESS);
		}
		pthread_mutex_unlock(&a->monitor_mutex);
	}
	return ((void *)EXIT_SUCCESS);
}

int
	dining(t_arg *arg)
{
	int			i;
	pthread_t	t_id;

	i = 0;
	pthread_mutex_lock(&arg->philo_mutex);
	arg->start_time = get_time();
	while (i < arg->num_of_philo)
	{
		if (pthread_create(&t_id, NULL, &routine, &arg->philo[i]) != 0)
			return (EXIT_FAILURE);
		if (pthread_detach(t_id) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
