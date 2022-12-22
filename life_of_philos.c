/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:12:05 by aoner             #+#    #+#             */
/*   Updated: 2022/09/12 15:01:07 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_check(void *i)
{
	t_philo	*ph;

	ph = (t_philo *)i;
	while (!(death_value(ph)) && !meal_counter_ctrl_eachone(ph))
	{
		pthread_mutex_lock(ph->left_fork);
		author(ph, "has taken a fork");
		if (ph->right_fork == NULL)
			break ;
		pthread_mutex_lock(ph->right_fork);
		author(ph, "has taken a fork");
		author(ph, "is eating");
		update_last_meal(ph);
		ft_sleepe(ph);
		meal_counter(ph);
		pthread_mutex_unlock(ph->left_fork);
		pthread_mutex_unlock(ph->right_fork);
		author(ph, "is sleeping");
		ft_sleeps(ph);
		author(ph, "is thinking");
	}
	return (0);
}

int	odd_philo_thread(t_philo **data, int first_time, int ph_num)
{
	int	i;

	i = 1;
	while (i < ph_num)
	{
		data[i]->first_time = first_time;
		data[i]->last_meal = first_time;
		if (pthread_create(&data[i]->tid, NULL, life_check, data[i]))
		{
			printf("Error\nThere was an error creating the threads!\n");
			return (0);
		}
		i = i + 2;
	}
	return (1);
}

int	even_philo_thread(t_philo **data, int first_time, int ph_num)
{
	int	i;

	i = 0;
	while (i < ph_num)
	{
		data[i]->first_time = first_time;
		data[i]->last_meal = first_time;
		if (pthread_create(&data[i]->tid, NULL, life_check, data[i]))
		{
			printf("Error\nThere was an error creating the threads!\n");
			return (0);
		}
		i = i + 2;
	}
	return (1);
}

int	create_philos(t_philo **data, int first_time)
{
	int	ph_num;

	ph_num = data[0]->philo_num;
	if (!even_philo_thread(data, first_time, ph_num))
		return (0);
	usleep(100);
	if (!odd_philo_thread(data, first_time, ph_num))
		return (0);
	return (1);
}
