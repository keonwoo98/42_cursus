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
	if (a->num_of_philo == 1)
	{
		pthread_mutex_lock(&a->forks_mutex[p->right_fork]);
		print_philo(p, a, "has taken a right fork");
	}
	else
	{
		pthread_mutex_lock(&a->forks_mutex[p->right_fork]);
		print_philo(p, a, "has taken a right fork");
		pthread_mutex_lock(&a->forks_mutex[p->left_fork]);
		print_philo(p, a, "has taken a left fork");
	}
}

void
	eating(t_philo *p, t_arg *a)
{
	if (a->num_of_philo == 1)
	{
		while (!a->end)
			usleep(1000);
		pthread_mutex_unlock(&a->forks_mutex[p->right_fork]);
	}
	else
	{
		pthread_mutex_lock(&p->philo_mutex);
		print_philo(p, a, "is eating");
		p->last_ate = get_time();
		pthread_mutex_unlock(&p->philo_mutex);
		while (get_time() - p->last_ate <= a->time_to_eat)
			usleep(1000);
		p->eat_cnt++;
		if (p->eat_cnt >= a->num_of_must_eat)
			a->num_of_end++;
		pthread_mutex_unlock(&a->forks_mutex[p->right_fork]);
		pthread_mutex_unlock(&a->forks_mutex[p->left_fork]);
	}
}

void
	sleeping(t_philo *p, t_arg *a)
{
	long long	start_sleeping;

	start_sleeping = get_time();
	print_philo(p, a, "is sleeping");
	while (get_time() - start_sleeping <= a->time_to_sleep)
		usleep(1000);
}

void
	thinking(t_philo *p, t_arg *a)
{
	print_philo(p, a, "is thinking");
}
