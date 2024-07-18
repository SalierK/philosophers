/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:17:06 by kkilitci          #+#    #+#             */
/*   Updated: 2024/07/02 17:29:20 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	check_arg_is_numeric(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_numeric(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_atoi(t_data *data)
{
	if (data->philo_num == -2)
		return (0);
	else if (data->time_to_die == -2)
		return (0);
	else if (data->time_to_eat == -2)
		return (0);
	else if (data->time_to_sleep == -2)
		return (0);
	return (1);
}
