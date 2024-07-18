/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:18:55 by kkilitci          #+#    #+#             */
/*   Updated: 2024/07/02 17:28:04 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	time_t			last_eat_time;
	int				philo_id;
	int				eat_count;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_t		*philos;
	pthread_mutex_t	meal;
	pthread_mutex_t	death;
	pthread_mutex_t	mutex;
	time_t			start_time;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_eat;
	int				is_dead;
	t_philo			*philo;
}	t_data;

long			ft_atoi(const char *str);
int				is_numeric(char c);
int				check_arg_is_numeric(int argc, char **argv);
int				init_structs(t_data *data, int argc, char **argv);
int				create_mutexes(t_data *data);
int				create_philo(t_data *data);
int				create_threads(t_data *data);
void			*thread(void *arg);
long long		get_time(void);
void			philo_eating(t_philo *philo);
void			ft_sleep(time_t time, t_data *data);
void			philo_sleeping(t_philo *philo);
void			philo_print(t_philo *philo, char *msg);
int				exit_threads(t_data *data);
int				check_eat(t_data *data);
int				is_dead(t_data *data);
void			check_death(t_data *data);
int				check_atoi(t_data *data);
#endif