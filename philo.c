/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:49:22 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/13 20:11:37 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_input_philo   *input_philo;
    t_detail_philo *detail_philo;
    t_all           *phlio_all;
    pthread_mutex_t *mutex;

    input_philo = malloc(sizeof(t_input_philo));
    intitilize_philos(input_philo, argc, argv);
    if(input_philo->error_state == 1)
        return -1;
    detail_philo = malloc(sizeof(t_detail_philo) * input_philo->pnbr);
    mutex = malloc(sizeof(pthread_mutex_t) * (input_philo->pnbr + 2));
    phlio_all = malloc(sizeof(pthread_mutex_t) * input_philo->pnbr);
    initilize_per_philo(detail_philo, input_philo, mutex);
    create_philos(thread,);
    return 0;
}