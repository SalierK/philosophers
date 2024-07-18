/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:17:14 by kkilitci          #+#    #+#             */
/*   Updated: 2024/07/02 17:27:48 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;
	time_t			timer;

	gettimeofday(&time, NULL);
	timer = (long int)(time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (timer);
}

int	check_eat(t_data *data)
{
	int	i;
	int	count;

	count = 0;
	if (data->num_of_eat != -1)
	{
		i = 0;
		while (i < data->philo_num)
		{
			pthread_mutex_lock(&data->meal);
			if (data->philo[i].eat_count >= data->num_of_eat)
				count++;
			pthread_mutex_unlock(&data->meal);
			i++;
		}
		if (count == data->philo_num)
			return (1);
	}
	return (0);
}

void	check_death(t_data *data)
{
	int		i;
	int		status;
	time_t	time;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->meal);
		time = (get_time() - data->philo[i].last_eat_time);
		pthread_mutex_unlock(&data->meal);
		status = time >= data->time_to_die;
		if (status || check_eat(data))
		{
			pthread_mutex_lock(&data->death);
			data->is_dead = 1;
			pthread_mutex_unlock(&data->death);
			if (status)
				printf("%lu %d %s\n", time, data->philo[i].philo_id, "died");
			break ;
		}
		i++;
	}
}

int	is_dead(t_data *data)
{
	pthread_mutex_lock(&data->death);
	if (data->is_dead)
	{
		pthread_mutex_unlock(&data->death);
		return (1);
	}
	pthread_mutex_unlock(&data->death);
	return (0);
}
