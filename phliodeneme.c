/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phliodeneme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:36:38 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/06 16:16:24 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int main(int argc, char **argv)
{
        
        t_philo *philos_struct;
        
        philos_struct = malloc(sizeof(t_philo));
        intitilize_philos(philos_struct, argc, argv);
        if(philos_struct->error_state == 1)
        {
                printf("error");
                return -1;
        }
        printf("%d\n",philos_struct->pnbr);
        printf("%d\n",philos_struct->ttdie);
        printf("%d\n",philos_struct->tteat);
        printf("%d\n",philos_struct->ttsleep);
        printf("%d\n",philos_struct->notepme);
        return 0;
}