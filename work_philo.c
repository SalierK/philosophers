/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:04:35 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/15 19:43:27 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int work_eat(t_detail_philo *detail_philo)
{
	long j;
	pthread_mutex_lock(detail_philo->error_lock);
	if(detail_philo->death_status == 1)
		return (0);
	pthread_mutex_unlock(detail_philo->error_lock);
	j = get_current_time_ms() - detail_philo->first_eat;
	pthread_mutex_lock(detail_philo->left_fork);
	printf("%ld %d has taken a right fork\n",j, detail_philo->philo_nbr + 1);
    pthread_mutex_lock(detail_philo->right_fork);
    printf("%ld %d has taken a left fork\n",j, detail_philo->philo_nbr + 1);
    printf("%ld %d is eating\n",j, detail_philo->philo_nbr + 1);
	ft_sleep(detail_philo->philos_strcut->tteat, detail_philo);
	pthread_mutex_unlock(detail_philo->right_fork);
    pthread_mutex_unlock(detail_philo->left_fork);
	return (0);
}

int work_sleep(t_detail_philo *detail_philo)
{
	long j;

	if(detail_philo->death_status == 1)
	{
		//pthread_mutex_unlock(detail_philo->message_lock);
		return (0);
	}
	j = get_current_time_ms() - detail_philo->first_eat;
	detail_philo->last_sleep = j;
	//pthread_mutex_lock(detail_philo->message_lock);

	printf("%ld %d is sleeping\n",j, detail_philo->philo_nbr + 1);
	//pthread_mutex_unlock(detail_philo->message_lock);
	ft_sleep(detail_philo->philos_strcut->ttsleep, detail_philo);
	return (0);
}

int work_think(t_detail_philo *detail_philo)
{
	long j;
	long a;

	if(detail_philo->death_status == 1)
		return (1);
	a = detail_philo->philos_strcut->ttdie -detail_philo->philos_strcut->first_eat;
	a -= detail_philo->philos_strcut->ttsleep;
	j = get_current_time_ms() - detail_philo->first_eat;
	detail_philo->last_think = j;
	//pthread_mutex_lock(detail_philo->message_lock);
	ft_sleep(a, detail_philo);
	printf("%ld %d is thinking.\n",j, detail_philo->philo_nbr + 1);
	//pthread_mutex_unlock(detail_philo->message_lock);

	return 0;
}

void *work_philo(void *philos_structt)
{
	t_detail_philo *detail_philo;
	int a;
	
	detail_philo = (t_detail_philo *)philos_structt;
	usleep(2 * (detail_philo->philo_nbr + 1));
	a = -1;
	if(detail_philo->philo_nbr%2 == 0)
		ft_sleep(detail_philo->philos_strcut->tteat, detail_philo);
	while (1)
	{	
		work_eat(detail_philo);
		death_check_after_sleep(detail_philo);
		work_sleep(detail_philo);
		death_check_after_sleep(detail_philo);
		work_think(detail_philo);
		death_check_after_sleep(detail_philo);
		if(all_thrade_runer(detail_philo))
			break;
		detail_philo->tour += 1;
	}
    return 0;
}
