/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 04:46:05 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/15 17:32:35 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void all_dead(t_detail_philo *detail_philo)
{
    
    int i;
    //pthread_mutex_unlock(detail_philo->error_lock);
    i = -1;
    while (++i < detail_philo->philos_strcut->pnbr)
        detail_philo->detail_philo[i].death_status = 1;
    detail_philo->detail_philo[0].death_status = 1;
}
// int death_check_after_eat(t_detail_philo *detail_philo)
// {
//     int dead;
//     int i;

//     i = -1;
//     pthread_mutex_lock(detail_philo->error_lock);
//     dead = detail_philo->philos_strcut->ttdie *detail_philo->tour;
//     if (dead <= detail_philo->last_meal && detail_philo->death_status == 0)
//     {
//         while (++i < detail_philo->philos_strcut->pnbr)
//         {
//             if(detail_philo[i].death_status == 1)
//             {
//                 all_dead(detail_philo);
//                 pthread_mutex_unlock(detail_philo->error_lock);
//                 return (0);
//             }
//         }
//         all_dead(detail_philo);
// 	    printf("%d %d is dead sleep\n",dead, detail_philo->philo_nbr + 1);
//     }
//     pthread_mutex_unlock(detail_philo->error_lock);
//     return (0);
// }

int death_check_after_sleep(t_detail_philo *detail_philo)
{
    long dead;
    long sleep;
    long eat;
    int i;

    i = -1;
    pthread_mutex_lock(detail_philo->error_lock);
    dead = detail_philo->philos_strcut->ttdie * detail_philo->tour;
    eat = detail_philo->last_meal;
    sleep = detail_philo->last_sleep;
    if ((dead <= eat || dead <= sleep ))
    {
        while (++i < detail_philo->philos_strcut->pnbr)
        {
            if(detail_philo->death_status == 1)
            {
                all_dead(detail_philo);
                pthread_mutex_unlock(detail_philo->error_lock);
                return (0);
            } 
        }
	    printf("%ld %d is dead\n",dead, detail_philo->philo_nbr + 1);
        printf("tour = %d\n",detail_philo->tour);
        all_dead(detail_philo);
    }
    pthread_mutex_unlock(detail_philo->error_lock);
    usleep(100);
    return (0);
}

int all_thrade_runer(t_detail_philo *detail_philo)
{
    int i;
    pthread_mutex_lock(detail_philo->error_lock);
    i = -1;
    while (++i < detail_philo->philos_strcut->pnbr)
    {
        if(detail_philo->detail_philo[i].death_status == 1) 
        {
            pthread_mutex_unlock(detail_philo->error_lock);
            return (1);
        }
    }
    pthread_mutex_unlock(detail_philo->error_lock);
    return (0);
}

void print_all_dead(t_detail_philo *detail_philo)
{
    int i;

    i = -1;
    while (++i < detail_philo->philos_strcut->pnbr)
    {
        printf("PHİLO NO : %d VE STATU %d \n" ,detail_philo->detail_philo[i].philo_nbr , detail_philo->detail_philo[i].death_status);
    }
}
