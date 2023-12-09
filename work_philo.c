/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:04:35 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/09 04:20:27 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void work_eat(t_detail_philo *detail_philo, int *loop)
{
	long j;

	j = get_current_time_ms() - detail_philo->first_eat;
	ft_sleep(detail_philo->philos_strcut->tteat);
    pthread_mutex_lock(&detail_philo->right_fork);
	printf("%ld %d has taken a right fork\n",j, detail_philo->philo_nbr + 1);
	pthread_mutex_lock(&detail_philo->left_fork);
    printf("%ld %d has taken a left fork\n",j, detail_philo->philo_nbr + 1);
    printf("%ld %d is eating\n",j, detail_philo->philo_nbr + 1);
    pthread_mutex_unlock(&detail_philo->right_fork);
	pthread_mutex_unlock(&detail_philo->left_fork);
}

void work_sleep(t_detail_philo *detail_philo, int *loop)
{
	long j;
	
	ft_sleep(detail_philo->philos_strcut->ttsleep);
	j = get_current_time_ms() - detail_philo->first_eat;
	printf("%ld %d is sleeping\n",j, detail_philo->philo_nbr + 1);
}

void work_think(t_detail_philo *detail_philo, int *loop)
{
	long j;
	int a;

	a = detail_philo->philos_strcut->ttdie -detail_philo->philos_strcut->first_eat;
	a-=detail_philo->philos_strcut->ttsleep;
	ft_sleep(a);
	j = get_current_time_ms() - detail_philo->first_eat;
	printf("%ld %d is thinking.\n",j, detail_philo->philo_nbr + 1);
}
void death_check(t_detail_philo *detail_philo, int *loop)
{
	
}

void *work_philo(void *philos_structt)
{
	int loop;
	
	loop = 1;
	t_detail_philo *detail_philo;

	detail_philo = (t_detail_philo *)philos_structt;
	// printf("philo : %d\n",detail_philo->philo_nbr + 1);
	//work_eat(detail_philo, &loop, time);
	while (loop++ < 4)
	{
		if(detail_philo->philo_nbr % 2 == 0 && detail_philo->is_eat == 0)
		{
			ft_sleep(detail_philo->philos_strcut->tteat);
			detail_philo->is_eat = 1;
		}
		work_eat(detail_philo, &loop);
		death_check(detail_philo, &loop);
		work_sleep(detail_philo, &loop);
		death_check(detail_philo, &loop);
		work_think(detail_philo, &loop);
	}
    return 0;
}