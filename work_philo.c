/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:04:35 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/09 08:07:01 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void work_eat(t_detail_philo *detail_philo)
{
	long j;

	j = get_current_time_ms() - detail_philo->first_eat;
	pthread_mutex_lock(&detail_philo->left_fork);
	printf("%ld %d has taken a right fork\n",j, detail_philo->philo_nbr + 1);
    pthread_mutex_lock(&detail_philo->right_fork);
    printf("%ld %d has taken a left fork\n",j, detail_philo->philo_nbr + 1);
    printf("%ld %d is eating\n",j, detail_philo->philo_nbr + 1);
	ft_sleep(detail_philo->philos_strcut->tteat);
    pthread_mutex_unlock(&detail_philo->right_fork);
	pthread_mutex_unlock(&detail_philo->left_fork);

}

int work_sleep(t_detail_philo *detail_philo)
{
	long j;
	
	ft_sleep(detail_philo->philos_strcut->ttsleep);
	j = get_current_time_ms() - detail_philo->first_eat;
	detail_philo->last_sleep = j;
	death_check_after_sleep(detail_philo);
	if(detail_philo->death_status == 1)
		return (0);
	printf("%ld %d is sleeping\n",j, detail_philo->philo_nbr + 1);
	return (0);
}

void work_think(t_detail_philo *detail_philo)
{
	long j;
	int a;

	a = detail_philo->philos_strcut->ttdie -detail_philo->philos_strcut->first_eat;
	a-=detail_philo->philos_strcut->ttsleep;
	ft_sleep(a);
	j = get_current_time_ms() - detail_philo->first_eat;
	printf("%ld %d is thinking.\n",j, detail_philo->philo_nbr + 1);
}

void *work_philo(void *philos_structt)
{
	t_detail_philo *detail_philo;
	
	detail_philo = (t_detail_philo *)philos_structt;
	while (1 && detail_philo->death_status == 0)
	{
		if(detail_philo->philo_nbr % 2 == 1 && detail_philo->is_eat == 0)
		{
			ft_sleep(detail_philo->philos_strcut->tteat);
			detail_philo->is_eat = 1;
		}
		work_eat(detail_philo);
		if(all_thrade_runer(detail_philo))
			break;
		death_check_after_eat(detail_philo);
		if(all_thrade_runer(detail_philo))
			break;
		death_check_after_sleep(detail_philo);
		if(all_thrade_runer(detail_philo))
			break;
		work_sleep(detail_philo);
		if(all_thrade_runer(detail_philo))
			break;
		death_check_after_sleep(detail_philo);
		if(all_thrade_runer(detail_philo))
			break;
		work_think(detail_philo);
		if(all_thrade_runer(detail_philo))
			break;
		detail_philo->tour += 1;
	}
    return 0;
}
