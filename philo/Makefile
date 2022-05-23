
CC = cc
CFLAGS = -Werror -Wextra -Wall 
FILES = lib/ft_atoi.c lib/ft_behaviours.c lib/ft_controller.c lib/ft_determinative.c lib/ft_error_handler.c lib/ft_isdigit.c lib/ft_isspace.c philo.c 
OBJECTS = $(FILES:.c=.o)
NAME = philo
XFLAGS = -lpthread
HEADER = philo.h 
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(XFLAGS)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re


