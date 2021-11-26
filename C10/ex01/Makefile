# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 17:23:34 by ucieutat          #+#    #+#              #
#    Updated: 2021/09/27 20:49:16 by ucieutat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= cat.c 
OBJS	= ${SRCS:.c=.o}
NAME 	= ft_cat

.c.o:
	gcc -c -Wall -Wextra -Werror $< -o ${OBJS}

${NAME}:	${OBJS}
	gcc -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean
