# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:34:39 by fsandel           #+#    #+#              #
#    Updated: 2022/11/01 16:14:20 by fsandel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AFLAGS		= ar -rcs
BFLAGS		= -D BUFFER_SIZE=1
NAME		= ft_printf.out
MAIN		= main.c

SRCS		= 	get_next_line.c \
				get_next_line_utils.c


all:		
			@$(CC) -o $(NAME) $(SRCS) $(MAIN) $(BFLAGS) $(CFLAGS)
			@./$(NAME)

clean:		
			rm -f *.o *.out

git:
			git add $(SRCS) get_next_line.h Makefile
			git commit -m "Makefile patch"
			git push
