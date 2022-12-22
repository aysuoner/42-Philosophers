/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:41:58 by aoner             #+#    #+#             */
/*   Updated: 2022/09/10 13:02:08 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	digit_ctrl(char **argv)
{
	int	i;
	int	m;

	m = 1;
	while (argv[m])
	{
		i = 0;
		while (argv[m][i])
		{
			if (i == 0 && (argv[m][i] == '-' || argv[m][i] == '+'))
				i++;
			if (argv[m][i] < 48 || argv[m][i] > 57)
				return (0);
			i++;
		}
		m++;
	}
	return (1);
}

int	argv_ctrl(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error\nNot enough arguments!\n");
		return (0);
	}
	if (!digit_ctrl(argv))
	{
		printf("Error\nArguments are not numbers!\n");
		return (0);
	}
	if (ft_atoi(argv[1]) > 250 || ft_atoi(argv[1]) < 1 || \
	ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
	{
		printf("Error\nYou cannot enter these arguments!\n");
		return (0);
	}
	if (argv[5])
	{
		if (ft_atoi(argv[5]) <= 0)
		{
			printf("Error\nTarget number of meals is wrong!\n");
			return (0);
		}
	}
	return (1);
}
