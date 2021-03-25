# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatrina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/15 11:07:45 by pcatrina          #+#    #+#              #
#    Updated: 2020/12/15 11:07:46 by pcatrina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -pthread
MAIN_SOURCES =		\
main.c				\
ph_error.c			\
ph_utils.c			\
ph_read_instructions.c	\
ph_init.c			\
ph_destroy.c		\
ph_treads.c			\
ph_life.c			\
ph_itoa.c			\
ph_status.c			\
ph_status_write.c	\
ph_monitor.c		\
ph_putstr_buf.c		\
ph_open_main_sem.c	\
ph_open_sem.c		\

NAME = philo_two

OBJECTS = $(MAIN_SOURCES:.c=.o)
HEADER = philo_two.h

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re