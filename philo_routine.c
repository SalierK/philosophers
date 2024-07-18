/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:17:27 by kkilitci          #+#    #+#             */
/*   Updated: 2024/07/02 15:32:32 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(time_t time, t_data *data)
{
	time_t	current_time;
	int		sleep;

	sleep = 5;
	current_time = get_time();
	while (1)
	{
		if ((get_time() - current_time) >= time)
			break ;
		if (data->philo_num <= 40)
			sleep = 10;
		else if (data->philo_num > 40 && data->philo_num <= 100)
			sleep = 100;
		else
			sleep = 500;
		usleep(sleep);
	}
}

void	philo_print(t_philo *philo, char *msg)
{
	time_t	time;

	pthread_mutex_lock(&philo->data->mutex);
	if (!is_dead(philo->data))
	{
		time = get_time() - philo->data->start_time;
		printf("%ld %d %s\n", time, philo->philo_id, msg);
	}
	pthread_mutex_unlock(&philo->data->mutex);
}

void	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	philo_print(philo, "has taken a fork");
	philo_print(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal);
	philo->last_eat_time = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->meal);
	ft_sleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_sleeping(t_philo *philo)
{
	philo_print(philo, "is sleeping");
	ft_sleep(philo->data->time_to_sleep, philo->data);
}

int	exit_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo_num == 1)
		pthread_detach(data->philos[0]);
	while (i < data->philo_num)
	{
		pthread_join(data->philos[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->mutex);
	free(data->philo);
	free(data->forks);
	free(data->philos);
	return (1);
}
