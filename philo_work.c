/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:10:42 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/13 20:58:04 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_eat()
{
    long j;

	j = get_current_time_ms() - all_philo->philos_detail->first_eat;
	pthread_mutex_lock(&all_philo->philos_detail->left_fork);
    pthread_mutex_lock(&all_philo->philos_detail->message_lock);
	printf("%ld %d has taken a fork\n",j, all_philo->philos_detail->philo_nbr + 1);
    pthread_mutex_lock(&all_philo->philos_detail->right_fork);
    printf("%ld %d has taken a fork\n",j, all_philo->philos_detail->philo_nbr + 1);
    printf("%ld %d is eating\n",j, all_philo->philos_detail->philo_nbr + 1);
    pthread_mutex_unlock(&all_philo->philos_detail->message_lock);
	ft_sleep(all_philo->philos_strcut->tteat);
    pthread_mutex_unlock(&all_philo->philos_detail->right_fork);
	pthread_mutex_unlock(&all_philo->philos_detail->left_fork);
}

void philo_eat(t_all *all_philo)
{
    long j;

	j = get_current_time_ms() - all_philo->philos_detail->first_eat;
    all_philo->philos_detail->last_sleep = j;
    
    
}
