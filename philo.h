/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:22:06 by aoner             #+#    #+#             */
/*   Updated: 2022/09/14 12:18:47 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				philo_num;
	unsigned int	first_time;
	unsigned int	last_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				my_target_meal;
	int				serv_count_foreach;
	int				*died;
	pthread_t		tid;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_mutex	*othermutex;
}t_philo;

typedef struct s_died
{
	int	ph_num;
	int	died;
}t_died;

typedef struct s_mutex
{
	int				all_target_meal;
	int				all_serv_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mealmutex;
	pthread_mutex_t	diedmutex;
	pthread_mutex_t	timemutex;
	pthread_mutex_t	allatemutex;
}t_mutex;

//argv_ctrl.c
int				argv_ctrl(int argc, char **argv);
int				digit_ctrl(char **argv);

//exitlife.c
void			joinlife(t_philo **data);
void			exitfunc(t_philo **data, t_died *check, \
t_mutex *data_race, int j);
void			earlyexitfunc(t_philo **data);

//fill_with_values.c
int				create_mutex(t_philo **data, t_mutex *data_race);
int				fill_data_race(t_philo **data, \
t_died *check, t_mutex *data_race);
void			fivearguman(t_philo **data, char **argv);
int				fillcheck(t_died *check, char **argv);
int				fill_the_philo(t_philo **data, t_died *check, char **argv);

//life_of_philos
void			*life_check(void *i);
int				odd_philo_thread(t_philo **data, int first_time, int ph_num);
int				even_philo_thread(t_philo **data, int first_time, int ph_num);
int				create_philos(t_philo **data, int first_time);

//main.c
int				deaht_ctrl(t_philo **data, t_died *check, t_mutex *data_race);
int				maintwo(t_philo **data, char **argv, \
t_died *check, t_mutex *data_race);
int				main(int argc, char **argv);

//philo_death_utils.c
void			author(t_philo *ph, char *msg);
void			mortingen_strasse_philo(t_philo **data, t_died *check, \
t_mutex *data_race, int i);
int				am_i_dead(t_philo *ph);
void			update_last_meal(t_philo *ph);
int				death_value(t_philo *ph);

//philo_meal_utils.c
void			meal_counter(t_philo *ph);
int				meal_counter_ctrl_eachone(t_philo *ph);
int				meal_counter_ctrl_everyone(t_mutex *data_race);

//set_the_time.c
unsigned int	microsecnd_type(void);
unsigned int	time_counter(unsigned int first_time);
void			ft_sleepe(t_philo *ph);
void			ft_sleeps(t_philo *ph);

//others
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
#endif