/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:17:36 by keokim            #+#    #+#             */
/*   Updated: 2021/11/18 15:17:41 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define BLUE		"\x1b[34m"
# define YELLOW		"\x1b[33m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

struct	s_arg;

typedef struct s_philo
{
	int					id;
	int					eat_cnt;
	long long			last_ate;
	long long			is_dead;
	pthread_t			monitor;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_arg		*arg;
}t_philo;

typedef struct s_arg
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_must_eat;
	int					num_of_end;
	int					end;
	int					dead;
	long long			start_time;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		philo_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		monitor_mutex;
	t_philo				*philo;
}t_arg;

int			ft_atoi(const char *str);
int			is_num(char **argv);
int			error_msg(char *msg);

int			init_arg(t_arg *arg, int argc, char **argv);
int			malloc_arg(t_arg *arg);
int			init_mutex(t_arg *arg);
int			init_philo(t_arg *arg);

int			dining(t_arg *arg);

long long	get_time(void);

void		*routine(void *philo);

void		*monitor(void *philo);

void		print_philo(t_philo *philo, t_arg *arg, char *msg);

#endif
