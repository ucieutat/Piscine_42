/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:16:14 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/22 19:26:28 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SIZE 10

int	g_tab[10];
int	g_count;

void	print_board(void)
{
	int		i;
	char	c;

	i = -1;
	while (++i < SIZE)
	{
		c = g_tab[i] + 48;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	g_count++;
}

int	check_board(int queen)
{
	int	i;

	i = -1;
	while (++i < queen)
		if (g_tab[queen] == g_tab[i]
			|| (g_tab[queen] - g_tab[i]) == (queen - i)
			|| (g_tab[queen] - g_tab[i]) == (i - queen))
			return (0);
	return (1);
}

void	add_queen(int queen)
{
	g_tab[queen] = -1;
	while (++g_tab[queen] < SIZE)
	{
		if (check_board(queen))
		{
			if (queen == SIZE - 1)
				print_board();
			else
				add_queen(queen + 1);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	add_queen(0);
	return (g_count);
}
