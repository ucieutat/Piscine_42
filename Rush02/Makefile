# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 12:25:06 by ucieutat          #+#    #+#              #
#    Updated: 2021/09/26 21:16:39 by jmbede           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix ${FOLDER}/, display_stdin.c tools.c main.c gestion_nombres.c autre_fill_dict.c convert.c init.c)
HEADER	= includes
OBJS	= ${SRCS:.c=.o}
NAME 	= rush-02
FOLDER	= srcs

.c.o:
	gcc -c -Wall -Wextra -Werror -g3 -I  ${HEADER} $< -o ${<:.c=.o}

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
