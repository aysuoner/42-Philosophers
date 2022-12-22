/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_the_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:54:48 by aoner             #+#    #+#             */
/*   Updated: 2022/09/14 14:26:55 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	microsecnd_type(void)
{
	struct timeval	tv;
	unsigned long	mic_sec;

	gettimeofday(&tv, NULL);
	mic_sec = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (mic_sec);
}

unsigned int	time_counter(unsigned int first_time)
{
	return (microsecnd_type() - first_time);
}

void	ft_sleepe(t_philo *ph)
{
	unsigned long	start;

	start = microsecnd_type();
	if (!(death_value(ph)))
	{
		while (microsecnd_type() < start + ph->time_to_eat)
			usleep(50);
	}
}

void	ft_sleeps(t_philo *ph)
{
	unsigned long	start;

	start = microsecnd_type();
	if (!(death_value(ph)))
	{
		while (microsecnd_type() < start + ph->time_to_sleep)
			usleep(50);
	}
}
