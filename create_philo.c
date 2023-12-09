/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:52:02 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/09 07:57:02 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_philos(pthread_t *thread, t_detail_philo *detail_philo, t_philo *philos_struct, pthread_mutex_t *mutex)
{
    int i;
	
	i = -1;
	while (++i < philos_struct->pnbr)
	{
		pthread_create(&thread[i], NULL, work_philo, (void *)&detail_philo[i]);
	}
	i = -1;
	while (++i < philos_struct->pnbr)
		pthread_join(thread[i], NULL);
}