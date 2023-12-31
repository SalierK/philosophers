/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phliodeneme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:36:38 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/15 16:27:07 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_philo *philos_struct;
    t_detail_philo *detail_philo;
    pthread_mutex_t *mutex;
    pthread_t *thread;
    t_kontrol *kontrol;
    

    philos_struct = malloc(sizeof(t_philo));
    intitilize_philos(philos_struct, argc, argv);
    mutex = malloc(sizeof(pthread_mutex_t) * (philos_struct->pnbr + 2)); // Moved this line
    kontrol = malloc(sizeof(t_kontrol));
    if(philos_struct->error_state == 1)
        return -1;
    thread = malloc(sizeof(pthread_t) * philos_struct->pnbr);
    detail_philo = malloc(sizeof(t_detail_philo) * philos_struct->pnbr);
    initilize_per_philo(detail_philo, philos_struct, mutex);
    create_philos(thread, detail_philo, philos_struct);
    pthread_mutex_destroy(mutex);
    return 0;
}  
