/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlilo_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:36:40 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/06 16:10:10 by kkilitci         ###   ########.fr       */
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
    if(argv[++i])
        philos_struct->pnbr = ft_atoi(argv[i]);
    if(argv[++i])
        philos_struct->ttdie = ft_atoi(argv[i]);
    if(argv[++i])
        philos_struct->tteat = ft_atoi(argv[i]);
    if(argv[++i])
        philos_struct->ttsleep = ft_atoi(argv[i]);
    if(argv[++i])
        philos_struct->notepme = ft_atoi(argv[i]);
    if(argc < 4)
        philos_struct->error_state = 1;
    if(argc > 5)
        philos_struct->error_state = 1;
}
