/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:18:02 by keokim            #+#    #+#             */
/*   Updated: 2021/11/18 15:18:03 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long
	get_time(void)
{
	long long		ret;
	struct timeval	time;

	ret = 0;
	if (gettimeofday(&time, NULL) == -1)
		error_msg("gettimeofday fail");
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void
	print_philo(t_philo *philo, t_arg *arg, char *msg)
{
	pthread_mutex_lock(&arg->print_mutex);
	printf(GREEN"%lldms\t"RESET, get_time() - philo->arg->start_time);
	printf("%d\t", philo->id + 1);
	printf("%s\t", msg);
	printf("(%d)\n", philo->eat_cnt);
	pthread_mutex_unlock(&arg->print_mutex);
}

void
	end_dining(t_arg *arg)
{
	int				i;

	i = 0;
	while (i < arg->num_of_philo)
		pthread_mutex_destroy(&(arg->forks_mutex[i++]));
	pthread_mutex_destroy(&(arg->philo_mutex));
	pthread_mutex_destroy(&(arg->print_mutex));
	pthread_mutex_destroy(&(arg->monitor_mutex));
	free(arg->forks_mutex);
	free(arg->philo);
}

int
	main(int argc, char **argv)
{
	t_arg			arg;

	if (argc != 5 && argc != 6)
		return (error_msg("Wrong amount of arguments"));
	if (init_arg(&arg, argc, argv))
		return (error_msg("Invalid arguments"));
	if (malloc_arg(&arg))
		return (error_msg("Malloc error"));
	if (init_philo(&arg) || init_mutex(&arg))
		return (error_msg("Initialize error"));
	if (dining(&arg))
		return (error_msg("Thread error"));
	pthread_mutex_lock(&arg.philo_mutex);
	end_dining(&arg);
	return (0);
}
