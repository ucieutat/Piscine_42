# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:25:11 by ucieutat          #+#    #+#              #
#    Updated: 2021/09/27 12:57:12 by ucieutat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c ft_atoi.c operators.c ft_print.c 
HEADER	= do_op.h
OBJS	= ${SRCS:.c=.o}
NAME 	= do-op

.c.o:
	gcc -c -Wall -Wextra -Werror -I ${HEADER} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	gcc -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:
	fclean all

.PHONY: all clean fclean re
