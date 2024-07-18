/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:17:17 by kkilitci          #+#    #+#             */
/*   Updated: 2024/07/18 14:59:23 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_structs(t_data *data, int argc, char **argv)
{
	pthread_mutex_t	*all_forks;
	t_philo			*philo;

	data->philo_num = ft_atoi(argv[1]);
	if (data->philo_num <= 0)
		return (0);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_eat = ft_atoi(argv[5]);
	else
		data->num_of_eat = -1;
	if (!check_atoi(data))
		return (0);
	philo = malloc(sizeof(t_philo) * (data->philo_num));
	if (!philo)
		return (0);
	all_forks = malloc(sizeof(pthread_mutex_t) * (data->philo_num));
	if (!all_forks)
		return (0);
	data->philo = philo;
	data->forks = all_forks;
	return (1);
}

int	create_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->meal, NULL))
		return (0);
	if (pthread_mutex_init(&data->death, NULL))
		return (0);
	if (pthread_mutex_init(&data->mutex, NULL))
		return (0);
	return (1);
}

int	create_philo(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(pthread_t) * (data->philo_num));
	if (!data->philos)
		return (0);
	i = 0;
	while (i < data->philo_num)
	{
		data->philo[i].eat_count = 0;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[((i + 1) % data->philo_num)];
		data->philo[i].philo_id = i + 1;
		data->philo[i].data = data;
		i++;
	}
	return (1);
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->philo_num)
	{
		data->philo[i].last_eat_time = data->start_time;
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->philos[i], NULL, thread, &(data->philo[i])))
			return (0);
		i++;
	}
	while (1)
	{
		if (is_dead(data))
			break ;
		check_death(data);
	}
	exit_threads(data);
	return (1);
}

void	*thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 && philo->data->philo_num > 1)
		ft_sleep(philo->data->time_to_eat, philo->data);
	while (1)
	{
		if (!is_dead(philo->data))
			philo_eating(philo);
		if (!is_dead(philo->data))
			philo_sleeping(philo);
		if (is_dead(philo->data))
			break ;
		philo_print(philo, "is thinking");
	}
	return (NULL);
}
