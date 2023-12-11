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
	pthread_mutex_t eat_lock;
	pthread_mutex_t sleep_lock;
	int				eat_time;
	long			first_eat;
	int 			is_eat;
	t_philo			*philos_strcut;
	int				death_status;
	long			last_meal;
	long			last_sleep;
	long			last_think;
	long			tour;
} t_detail_philo;

typedef struct s_kontrol
{
	int stop;
	t_detail_philo *detail_philo;
}t_kontrol;

void *check_all_deths(void *kontroll);
int death_check_after_eat(t_detail_philo *detail_philo);
int death_check_after_sleep(t_detail_philo *detail_philo);
void intitilize_philos(t_philo *philos_struct,int argc,char **argv);
void initilize_per_philo(t_detail_philo *detail_philo, t_philo *philos_struct, pthread_mutex_t *mutex);
void *work_philo(void *philos_structt);
void create_philos(pthread_t *thread, t_kontrol *kontrol, t_philo *philos_struct, pthread_mutex_t *mutex);
void work_eat(t_detail_philo *detail_philo);
long get_current_time_ms(void);
void	ft_sleep(long time);
int all_thrade_runer(t_detail_philo *detail_philo);
int	ft_atoi(const char *str, t_philo *philo_struct);
void all_dead(t_detail_philo *detail_philo);

#endif
