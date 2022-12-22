/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_meal_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:23:28 by aoner             #+#    #+#             */
/*   Updated: 2022/09/13 11:56:41 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal_counter(t_philo *ph)
{
	ph->serv_count_foreach++;
	pthread_mutex_lock(&ph->othermutex->mealmutex);
	ph->othermutex->all_serv_count++;
	pthread_mutex_unlock(&ph->othermutex->mealmutex);
}

int	meal_counter_ctrl_eachone(t_philo *ph)
{
	int	ret;

	ret = 0;
	ret = (ph->serv_count_foreach == ph->my_target_meal);
	return (ret);
}

int	meal_counter_ctrl_everyone(t_mutex *data_race)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&data_race->mealmutex);
	ret = data_race->all_serv_count == data_race->all_target_meal;
	pthread_mutex_unlock(&data_race->mealmutex);
	return (ret);
}
