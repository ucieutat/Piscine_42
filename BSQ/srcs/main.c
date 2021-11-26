/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:14:58 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/29 23:19:16 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	in_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

char	*read_stdin(void)
{
	char	buf;
	int		fd;

	fd = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC);
	while (read(STDIN_FILENO, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
	return ("tmp.txt");
}

void	init(char *filename)
{
	t_board		*board;
	int			check;
	int			check2;
	t_square	*test;

	board = malloc(sizeof(t_board));
	board->charset = malloc(sizeof(char) * 4);
	check = check_premiere_ligne(filename, board);
	check2 = check_charset(board->charset);
	if (!check || !check2)
	{
		write(2, "map error\n", 10);
		return ;
	}
	test = ft_solve(*board);
	affichage(test, *board);
	free(board->plateau);
	free(board->charset);
	free(board);
}

int	main(int argc, char **argv)
{
	int			i;
	char		*tmp;

	i = 0;
	if (argc == 1)
	{
		tmp = read_stdin();
		init(tmp);
	}
	else
		while (++i < argc)
			init(argv[i]);
	return (0);
}
