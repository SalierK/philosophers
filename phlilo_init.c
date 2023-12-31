/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlilo_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:36:40 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/15 15:01:57 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void intitilize_philos(t_philo *philos_struct,int argc,char **argv)
{
    int i;
    
    i = 0;
    philos_struct->pnbr = -1;
    philos_struct->ttdie = -1;
    philos_struct->tteat = -1;
    philos_struct->ttsleep = -1;
    philos_struct->notepme = -1;
    philos_struct->error_state = 0;
    philos_struct->first_eat = get_current_time_ms();
    if(argv[++i])
        philos_struct->pnbr = ft_atoi(argv[i], philos_struct);
    if(argv[++i])
        philos_struct->ttdie = ft_atoi(argv[i], philos_struct);
    if(argv[++i])
        philos_struct->tteat = ft_atoi(argv[i], philos_struct);
    if(argv[++i])
        philos_struct->ttsleep = ft_atoi(argv[i], philos_struct);
    if(argv[++i])
        philos_struct->notepme = ft_atoi(argv[i], philos_struct);
    if(argc < 5)
        philos_struct->error_state = 1;
    if(argc > 6)
        philos_struct->error_state = 1;
}

void initilize_per_philo(t_detail_philo *detail_philo, t_philo *philos_struct, pthread_mutex_t *mutex)
{
	int i;

	i = -1;
    while(++i < philos_struct->pnbr + 2)
        pthread_mutex_init(&mutex[i], (void *)0);
    i = -1;
	while(++i < philos_struct->pnbr)
	{
		detail_philo[i].philo_nbr = i;
		detail_philo[i].left_fork = &mutex[i];
		detail_philo[i].right_fork = &mutex[i + 1];
        detail_philo[i].first_eat = philos_struct->first_eat;
        detail_philo[i].philos_strcut = malloc(sizeof(t_philo));
        detail_philo[i].philos_strcut = philos_struct;
        detail_philo[i].is_eat = 0;
        detail_philo[i].tour = 1;
        detail_philo[i].error_lock = &mutex[philos_struct->pnbr];
        detail_philo[i].message_lock = &mutex[philos_struct->pnbr + 1];
	}
	detail_philo[i - 1].right_fork = &mutex[0];
    i = -1;
    while(++i < philos_struct->pnbr)
        detail_philo[i].detail_philo = detail_philo;

}  
