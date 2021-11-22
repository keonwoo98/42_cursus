/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:18:07 by keokim            #+#    #+#             */
/*   Updated: 2021/11/18 15:18:08 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	taking_forks(t_philo *p, t_arg *a)
{
	pthread_mutex_lock(p->right_fork);
	print_philo(p, a, "has taken a right fork");
	pthread_mutex_lock(p->left_fork);
	print_philo(p, a, "has taken a left fork");
}

void
	eating(t_philo *p, t_arg *a)
{
	long long	start_eating;

	p->last_ate = get_time();
	p->is_dead = p->last_ate + a->time_to_die;
	start_eating = get_time();
	print_philo(p, a, "is eating");
	while (get_time() - start_eating < a->time_to_eat)
		usleep(100);
	p->eat_cnt++;
	if (p->eat_cnt >= a->num_of_must_eat)
		a->num_of_end++;
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

void
	sleeping(t_philo *p, t_arg *a)
{
	long long	start_sleeping;

	start_sleeping = get_time();
	print_philo(p, a, "is sleeping");
	while (get_time() - start_sleeping < a->time_to_sleep)
		usleep(100);
}

void
	thinking(t_philo *p, t_arg *a)
{
	print_philo(p, a, "is thinking");
}

void
	*routine(void *philo)
{
	t_philo		*p;
	t_arg		*a;
	pthread_t	t_id;

	p = (t_philo *)philo;
	a = p->arg;
	if (p->id % 2 == 0)
		usleep(500 * a->time_to_eat);
	if (pthread_create(&t_id, NULL, &monitor, p) != 0)
		return ((void *)EXIT_FAILURE);
	if (pthread_detach(t_id) != 0)
		return ((void *)EXIT_FAILURE);
	p->last_ate = get_time();
	p->is_dead = p->last_ate + a->time_to_die;
	while (1)
	{
		if (a->dead || a->end)
			break ;
		taking_forks(p, a);
		eating(p, a);
		sleeping(p, a);
		thinking(p, a);
		// usleep(1000);
	}
	return ((void *)EXIT_SUCCESS);
}
