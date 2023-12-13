/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phlilo_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkilitci <kkilitci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:55:23 by kkilitci          #+#    #+#             */
/*   Updated: 2023/12/13 15:57:52 by kkilitci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str, t_input_philo *philo_struct)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			philo_struct->error_state = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (np * num);
}

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, (void *)0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
void	ft_sleep(long time)
{
	long	current_time;

	current_time = get_current_time_ms();
	while (1)
	{
		if ((get_current_time_ms() - current_time) >= time)
			break ;
		usleep(10);
	}
}