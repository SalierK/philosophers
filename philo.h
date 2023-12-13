/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:49:30 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/13 20:54:58 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_input_philo
{
    int 	pnbr;
	int 	ttdie;
	int 	tteat;
	int 	ttsleep;
	int 	notepme;
	long	first_eat;
	int 	error_state;
}t_input_philo;

typedef struct s_detail_philo
{
	int             philo_nbr;
    int             error_state;
	int				is_eat;
	int				tour;
	int				death_status;
	long			first_eat;
	long			first_sleep;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *deth_check_lock;
    pthread_mutex_t *message_lock;
}t_detail_philo;

typedef struct s_all
{
	int				pid;
	t_input_philo	*philos_strcut;
	t_detail_philo	*philos_detail;
}t_all;

void	ft_sleep(long time);
long	get_current_time_ms(void);
int	ft_atoi(const char *str, t_input_philo *philo_struct);
void intitilize_philos(t_input_philo *philos_struct,int argc,char **argv);
void initilize_per_philo(t_detail_philo *detail_philo, t_input_philo *philos_struct, pthread_mutex_t *mutex, t_all *philo_all);
void create_philos(pthread_t *thread, t_all *philo_all);
void *work_philo(void *x);
