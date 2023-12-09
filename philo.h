#if !defined(PHILO_H)
#define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_philo
{
	int 	pnbr;
	int 	ttdie;
	int 	tteat;
	int 	ttsleep;
	int 	notepme;
	long	first_eat;
	int 	error_state;
} t_philo;

typedef struct s_detail_philo
{
	int             philo_nbr;
	pthread_mutex_t left_fork;
	pthread_mutex_t right_fork;
	int				eat_time;
	long			first_eat;
	t_philo			*philos_strcut;
} t_detail_philo;




void intitilize_philos(t_philo *philos_struct,int argc,char **argv);
void initilize_per_philo(t_detail_philo *detail_philo, t_philo *philos_struct, pthread_mutex_t *mutex);
void *work_philo(void *philos_structt);
void create_philos(pthread_t *thread, t_detail_philo *detail_philo, t_philo *philos_struct, pthread_mutex_t *mutex);
void work_eat(t_detail_philo *detail_philo, int *loop);
long get_current_time_ms(void);

int	ft_atoi(const char *str, t_philo *philo_struct);
#endif
