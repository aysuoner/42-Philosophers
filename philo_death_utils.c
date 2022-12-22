/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:53:19 by aoner             #+#    #+#             */
/*   Updated: 2022/09/14 12:35:34 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	author(t_philo *ph, char *msg)
{
	pthread_mutex_lock(&ph->othermutex->diedmutex);
	if (!(*ph->died))
		printf("%u %d %s\n", time_counter(ph->first_time), ph->id + 1, msg);
	pthread_mutex_unlock(&ph->othermutex->diedmutex);
}

void	mortingen_strasse_philo(t_philo **data, t_died *check, \
t_mutex *data_race, int i)
{
	int	ph_num;

	ph_num = check->ph_num;
	pthread_mutex_lock(&data_race->diedmutex);
	check->died = 1;
	pthread_mutex_unlock(&data_race->diedmutex);
	printf("%u %d died\n", time_counter(data[i]->first_time), \
	(data[i]->id % ph_num) + 1);
}

int	am_i_dead(t_philo *ph)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&ph->othermutex->timemutex);
	ret = (unsigned int)ph->time_to_die < microsecnd_type() - ph->last_meal;
	pthread_mutex_unlock(&ph->othermutex->timemutex);
	return (ret);
}

void	update_last_meal(t_philo *ph)
{
	pthread_mutex_lock(&ph->othermutex->timemutex);
	ph->last_meal = microsecnd_type();
	pthread_mutex_unlock(&ph->othermutex->timemutex);
}

int	death_value(t_philo *ph)
{
	int	ret;

	pthread_mutex_lock(&ph->othermutex->diedmutex);
	ret = *ph->died;
	pthread_mutex_unlock(&ph->othermutex->diedmutex);
	return (ret);
}
