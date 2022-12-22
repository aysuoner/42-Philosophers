/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_with_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:59:28 by aoner             #+#    #+#             */
/*   Updated: 2022/09/14 12:18:40 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutex(t_philo **data, t_mutex *data_race)
{
	int	i;

	i = -1;
	while (++i < data[0]->philo_num)
	{
		if (pthread_mutex_init(&data_race->forks[i], NULL))
		{
			printf("Error\nMutex init problems!\n");
			return (0);
		}
	}
	i = -1;
	while (++i < data[0]->philo_num)
	{
		data[i]->left_fork = &data_race->forks[i];
		data[i]->right_fork = NULL;
		if (data[1])
		{
			data[i]->right_fork = &data_race->forks[(i + 1) \
			% data[0]->philo_num];
		}
		data[i]->othermutex = data_race;
	}
	return (1);
}

int	fill_data_race(t_philo **data, t_died *check, t_mutex *data_race)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(data_race->mealmutex), NULL) || \
	pthread_mutex_init(&(data_race->diedmutex), NULL) || \
	pthread_mutex_init(&(data_race->timemutex), NULL) || \
	pthread_mutex_init(&(data_race->allatemutex), NULL))
	{
		printf("Error\nMutex init problems!\n");
		exitfunc(data, check, data_race, 0);
		return (0);
	}
	data_race->all_serv_count = 0;
	data_race->all_target_meal = data[0]->my_target_meal * data[0]->philo_num;
	data_race->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), \
	data[0]->philo_num);
	if (!(data_race->forks))
	{
		printf("Error\nMalloc data problems!\n");
		exitfunc(data, check, data_race, 0);
		return (0);
	}
	return (1);
}

void	fivearguman(t_philo **data, char **argv)
{
	int	ph_num;
	int	i;

	i = 0;
	ph_num = ft_atoi(argv[1]);
	while (i < ph_num)
	{
		if (argv[5])
			data[i]->my_target_meal = ft_atoi(argv[5]);
		i++;
	}
}

int	fillcheck(t_died *check, char **argv)
{
	check->died = 0;
	check->ph_num = ft_atoi(argv[1]);
	return (0);
}

int	fill_the_philo(t_philo **data, t_died *check, char **argv)
{
	int	i;

	i = 0;
	fillcheck(check, argv);
	while (i < ft_atoi(argv[1]))
	{
		data[i] = (t_philo *)ft_calloc(sizeof(t_philo), 1);
		if (!data[i])
		{
			printf("Error\nMalloc data problems!\n");
			return (0);
		}
		data[i]->id = i;
		data[i]->philo_num = ft_atoi(argv[1]);
		data[i]->time_to_die = ft_atoi(argv[2]);
		data[i]->time_to_eat = ft_atoi(argv[3]);
		data[i]->time_to_sleep = ft_atoi(argv[4]);
		data[i]->my_target_meal = -1;
		data[i]->serv_count_foreach = 0;
		data[i]->died = &check->died;
		i++;
	}
	fivearguman(data, argv);
	return (1);
}
