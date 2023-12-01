/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlilo_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:36:40 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/01 14:58:37 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void intitilize_philos(t_philo *philos_struct,int argc,char **argv)
{
    int i;
    
    i = 0;
    if(argv[++i])
        philos_struct->pnbr = ft_itoa(argv[i -1]);
    if(argv[++i])
        philos_struct->ttdie = ft_itoa(argv[i -1]);
    if(argv[++i])
        philos_struct->tteat = ft_itoa(argv[i -1]);
    if(argv[++i])
        philos_struct->ttsleep = ft_itoa(argv[i -1]);
    if(argv[++i])
        philos_struct->notepme = ft_itoa(argv[i -1]);
    
    
}