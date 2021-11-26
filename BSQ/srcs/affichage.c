/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:06:42 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/29 17:09:51 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_board(t_board board)
{
	int	i;

	i = 0;
	while (i < board.line_len * board.map_len)
	{
		write(1, &board.plateau[i++], 1);
		if (i % board.line_len == 0)
			write(1, "\n", 1);
	}
}

int	find_best_sqr(t_square *tab, int board_size, t_square *best_sqr)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	best_sqr->size = -1;
	best_sqr->x = -1;
	while (++i < board_size)
	{
		if (tab[i].size > best_sqr->size)
		{
			*best_sqr = tab[i];
			result = i;
		}
	}
	return (result);
}

void	affichage(t_square *results, t_board board)
{
	int			i;
	int			j;
	int			start;
	t_square	best_sqr;

	start = find_best_sqr(results, board.map_len, &best_sqr) * board.line_len;
	start += best_sqr.x;
	i = -1;
	j = 0;
	while (++i < best_sqr.size * best_sqr.size)
	{
		if (j == best_sqr.size)
		{
			start += board.line_len;
			j = 0;
		}
		board.plateau[start + j] = board.charset[2];
		j++;
	}
	print_board(board);
}
