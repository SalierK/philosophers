/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:52:02 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/11 21:01:44 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_philos(pthread_t *thread, t_kontrol *kontrol, t_philo *philos_struct, pthread_mutex_t *mutex)
{
    int i;
	pthread_t kontrol_thread;
	
	i = -1;
	while (++i < philos_struct->pnbr)
	{
		pthread_create(&thread[i], NULL, work_philo, (void *)&kontrol->detail_philo[i]);
	}
	i = -1;
	pthread_create(&kontrol_thread, NULL, check_all_deths, (void *)kontrol);
	i = -1;
	while (++i < philos_struct->pnbr)
		pthread_join(thread[i], NULL);
}
void *check_all_deths(void *kontroll)
{
	int j;
	int i;
	t_kontrol *kontrol;

	kontrol = (t_kontrol *)kontroll;
	j = -1;
	i = 0;
	
	while (++j < kontrol->detail_philo->philos_strcut->pnbr)
	{
		//printf("Numara = %d\n",kontrol->detail_philo[j].philo_nbr);
		if(kontrol->detail_philo[j].death_status == 1)
		{
			printf("");
			while (i < kontrol->detail_philo->philos_strcut->pnbr)
			{
				kontrol->detail_philo[i].death_status = 1;
				i++;
			}		
		}
		i = 0;
		if(j == kontrol->detail_philo->philos_strcut->pnbr -1)
			j = -1;		
	}

	return (0);
}
