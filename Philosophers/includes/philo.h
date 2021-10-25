#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t			thread_id;
	pthread_t			left_fork;
	pthread_t			right_fork;
	pthread_mutex_t		forks;
}t_philo;

typedef struct s_arg
{
	int					num_of_philo;		// 철학자의 수, 즉 포크의 갯수
	int					time_to_die;		// 밀리세컨 단위, 철학자가 식사하지 않은지 time_to_die가 지나면 철학자는 죽는다
	int					time_to_eat;		// 밀리세컨 단위, 철학자가 식사하는 시간, 포크 두 개 소유
	int					time_to_sleep;		// 밀리세컨 단위, 철학자가 자는 시간
	int					num_of_must_eat;	// 모든 철학자들이 이 횟수만큼 식사를 하게되면 프로그램 종료, 인자가 안들어오면 누군가 죽게되면 종료

	long long			timestamp;

	pthread_mutex_t		write_mutex;
	pthread_mutex_t		dead;
	pthread_mutex_t		time_eat;
	pthread_mutex_t		finish;
	t_philo				*philo;
}t_arg;

#endif