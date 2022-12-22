/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:25:22 by aoner             #+#    #+#             */
/*   Updated: 2022/09/12 15:02:04 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	deaht_ctrl(t_philo **data, t_died *check, t_mutex *data_race)
{
	int	i;
	int	ph_num;
	int	c;

	c = 0;
	ph_num = check->ph_num;
	while (!meal_counter_ctrl_everyone(data_race))
	{
		i = 0;
		while (i < ph_num)
		{
			if (meal_counter_ctrl_everyone(data_race) || death_value(data[i]))
				return (0);
			if (am_i_dead(data[i]))
				mortingen_strasse_philo(data, check, data_race, i);
			i++;
			usleep(100);
		}
	}
	return (0);
}

int	maintwo(t_philo **data, char **argv, t_died *check, t_mutex *data_race)
{
	if (!fill_the_philo(data, check, argv))
	{
		earlyexitfunc(data);
		return (0);
	}
	if (!fill_data_race(data, check, data_race))
		return (0);
	if (!create_mutex(data, data_race))
	{
		exitfunc(data, check, data_race, 1);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	**data;
	t_died	check;
	t_mutex	data_race;
	int		first_time;

	if (!argv_ctrl(argc, argv))
		return (1);
	data = (t_philo **)ft_calloc(sizeof(t_philo *), (ft_atoi(argv[1]) + 1));
	if (!data)
	{
		printf("Error\nMalloc data problems!");
		return (1);
	}
	if (!maintwo(data, argv, &check, &data_race))
		return (1);
	first_time = microsecnd_type();
	if (!create_philos(data, first_time))
	{
		exitfunc(data, &check, &data_race, 1);
		return (1);
	}
	deaht_ctrl(data, &check, &data_race);
	joinlife(data);
	exitfunc(data, &check, &data_race, 1);
	return (0);
}
