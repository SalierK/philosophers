/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:30:35 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/13 21:00:20 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void create_philos(pthread_t *thread, t_all *philo_all)
{
    int i;
	
	i = -1;
	while (++i < philo_all->philos_strcut->pnbr)
	{
		pthread_create(&thread[i], NULL, work_philo, (void *)&philo_all[i]);
	}
	i = -1;
	while (++i <  philo_all->philos_strcut->pnbr)
		pthread_join(thread[i], NULL);
}

void *work_philo(void *x)
{
	t_all *all_philo;
    
    all_philo = (t_all *)x;
    while (1 && all_philo->philos_detail->death_status == 0)
	{
		if(all_philo->philos_detail->philo_nbr % 2 == 1 && all_philo->philos_detail->is_eat == 0)
		{
			ft_sleep(all_philo->philos_strcut[all_philo->pid].tteat);
			all_philo->philos_detail->is_eat = 1;
		}
        philo_eat(all_philo->philos_strcut[all_philo->pid]);
        philo_death_check(all_philo->philos_strcut[all_philo->pid]);
        philo_sleep(all_philo->philos_strcut[all_philo->pid]);
        philo_death_check(all_philo->philos_strcut[all_philo->pid]);
        philo_think(all_philo->philos_strcut[all_philo->pid]);
    }
    return (0);
}