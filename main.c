/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:17:23 by kkilitci          #+#    #+#             */
/*   Updated: 2024/07/18 14:59:08 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		write(2, "Invalid argument number!", 25);
		return (0);
	}
	if (!check_arg_is_numeric(argc, argv))
		return (0);
	if (!init_structs(&data, argc, argv))
		return (0);
	if (!create_mutexes(&data))
		return (0);
	if (!create_philo(&data))
		return (0);
	if (!create_threads(&data))
		return (0);
	return (0);
}
