# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 13:03:01 by ucieutat          #+#    #+#              #
#    Updated: 2021/09/29 23:39:15 by ucieutat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix ${FOLDER}/, utils.c check.c main.c ft_solve.c affichage.c)
HEADER	= includes
OBJS	= ${SRCS:.c=.o}
NAME 	= bsq
FOLDER	= srcs

.c.o:
	gcc -c -Wall -Wextra -Werror -g3 -I  ${HEADER} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	gcc -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME} tmp.txt

re:	fclean all

.PHONY: all clean fclean re
