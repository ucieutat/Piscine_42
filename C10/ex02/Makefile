# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 17:23:34 by ucieutat          #+#    #+#              #
#    Updated: 2021/09/27 15:10:29 by ucieutat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_tail.c size_file.c tools.c
HEADER	= ft.h
OBJS	= ${SRCS:.c=.o}
NAME 	= ft_tail

.c.o:
	gcc -c -Wall -Wextra -Werror  $< -o ${<:.c=.o} -I ${HEADER}

${NAME}:	${OBJS}
	gcc -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean
