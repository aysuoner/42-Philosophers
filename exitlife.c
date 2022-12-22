/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitlife.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:54:20 by aoner             #+#    #+#             */
/*   Updated: 2022/09/12 15:00:05 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	joinlife(t_philo **data)
{
	int	ph_num;
	int	i;

	i = 0;
	ph_num = data[i]->philo_num;
	while (i < ph_num)
	{
		pthread_join(data[i]->tid, NULL);
		i++;
	}
}

void	exitfunc(t_philo **data, t_died *check, t_mutex *data_race, int j)
{
	int	i;

	i = -1;
	if (j == 1)
	{
		while (++i < check->ph_num)
			pthread_mutex_destroy(&data_race->forks[i]);
	}
	pthread_mutex_destroy(&data_race->mealmutex);
	pthread_mutex_destroy(&data_race->diedmutex);
	pthread_mutex_destroy(&data_race->timemutex);
	pthread_mutex_destroy(&data_race->allatemutex);
	if (data_race->forks)
		free(data_race->forks);
	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}

void	earlyexitfunc(t_philo **data)
{
	int	i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}
