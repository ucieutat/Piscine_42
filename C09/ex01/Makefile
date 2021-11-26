# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 12:25:06 by ucieutat          #+#    #+#              #
#    Updated: 2021/09/20 13:55:24 by ucieutat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(addprefix ${FOLDER}/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
HEADER	= includes
OBJS	= ${SRCS:.c=.o}
NAME 	= libft.a
FOLDER	= srcs

.c.o:
	gcc -c -Wall -Wextra -Werror -o $@ $< -I ${HEADER}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:
	fclean all

.PHONY: all clean fclean re
