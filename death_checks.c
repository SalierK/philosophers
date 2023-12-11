/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 04:46:05 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/11 21:06:32 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void all_dead(t_detail_philo *detail_philo)
{
    
    int i;

    pthread_mutex_lock(&detail_philo->sleep_lock);
    pthread_mutex_lock(&detail_philo->eat_lock);
    i = -1;
    while (++i < detail_philo->philos_strcut->pnbr)
        detail_philo[i].death_status = 1;
    pthread_mutex_unlock(&detail_philo->eat_lock);
    pthread_mutex_unlock(&detail_philo->sleep_lock);
}
int death_check_after_eat(t_detail_philo *detail_philo)
{
    int dead;
    int i;

    i = -1;
    // printf("---------------\n");
    // while (++i < detail_philo->philos_strcut->pnbr)
    // {
    //     printf("PHİLO NO : %d VE STATU %d \n" ,detail_philo->philo_nbr , detail_philo[i].death_status);
    // }
    pthread_mutex_lock(&detail_philo->eat_lock);
    dead = detail_philo->philos_strcut->ttdie *detail_philo->tour;
   //printf("Thred No : %d Olum Durumu : %d\n",detail_philo->philo_nbr,detail_philo->death_status);
    if (dead <= detail_philo->last_meal && detail_philo->death_status == 0)
    {
        while (++i < detail_philo->philos_strcut->pnbr)
        {
            if(detail_philo[i].death_status == 1)
            {
                pthread_mutex_unlock(&detail_philo->eat_lock);
                return (0);
            }
		        
        }
	    printf("%d %d is dead sleep\n",dead, detail_philo->philo_nbr + 1);
        all_dead(detail_philo);
    }
    pthread_mutex_unlock(&detail_philo->eat_lock);
    return (0);
}

int death_check_after_sleep(t_detail_philo *detail_philo)
{
    int dead;
    int i;

    i = -1;
    pthread_mutex_lock(&detail_philo->sleep_lock);
    dead = detail_philo->philos_strcut->ttdie *detail_philo->tour;
    if (dead <= detail_philo->last_sleep && detail_philo->death_status == 0)
    {
        while (++i < detail_philo->philos_strcut->pnbr)
        {
            if(detail_philo[i].death_status == 1)
            {
                pthread_mutex_unlock(&detail_philo->sleep_lock);
                return (0);
            } 
        }
	    printf("%d %d is dead sleep\n",dead, detail_philo->philo_nbr + 1);
        all_dead(detail_philo);
    }
    pthread_mutex_unlock(&detail_philo->sleep_lock);
    return (0);
}

int all_thrade_runer(t_detail_philo *detail_philo)
{
    int i;

    i = -1;
    pthread_mutex_lock(&detail_philo->sleep_lock);
    pthread_mutex_lock(&detail_philo->eat_lock);
    while (++i < detail_philo->philos_strcut->pnbr)
    {
        if(detail_philo[i].death_status == 1)
            return (1);
    }
    pthread_mutex_unlock(&detail_philo->eat_lock);
    pthread_mutex_unlock(&detail_philo->sleep_lock);
    return (0);
}

