NAME = philo
SRCS = argv_ctrl.c \
		exitlife.c \
		fill_with_values.c \
		ft_atoi.c \
		ft_calloc.c \
		life_of_philos.c \
		main.c \
		philo_death_utils.c \
		philo_meal_utils.c \
		set_the_time.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	gcc $(CFLAGS) $< -c -o $@

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f philo

re: fclean all

.PHONY: clean fclean re all