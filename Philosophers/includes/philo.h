#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

/**
** Colors
**/

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET "\033[0;37m"

# define EVEN 0
# define ODD 1

struct s_arg;

typedef struct s_philo
{
	int					num;
	int					stat;
	int					starve;
	int					eat_cnt;
	long long			die_start_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_arg		*arg;
}t_philo;

typedef struct s_arg
{
	int					num_of_philo;		// 철학자의 수, 즉 포크의 갯수
	int					time_to_die;		// 밀리세컨 단위, 철학자가 식사하지 않은지 time_to_die가 지나면 철학자는 죽는다
	int					time_to_eat;		// 밀리세컨 단위, 철학자가 식사하는 시간, 포크 두 개 소유
	int					time_to_sleep;		// 밀리세컨 단위, 철학자가 자는 시간
	int					num_of_must_eat;	// 모든 철학자들이 이 횟수만큼 식사를 하게되면 프로그램 종료, 인자가 안들어오면 누군가 죽게되면 종료
	int					num_of_ate;
	int					all_ate;
	long long			start_time;
	pthread_mutex_t		main_mutex;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*forks_mutex;
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

void		*monitoring(void *arg);

void		print_message(t_philo *p, char *str);

#endif
