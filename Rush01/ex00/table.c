/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruault <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:39:58 by gruault           #+#    #+#             */
/*   Updated: 2021/09/19 18:14:44 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h" 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_table(int *tab)
{
	int	col;
	int	line;
	int	i;

	col = 1;
	line = 1;
	i = 0;
	while (col <= SIZE && line <= SIZE)
	{
		ft_putchar(tab[i] + '0');
		i++;
		if (col == SIZE)
		{
			ft_putchar('\n');
			col = 0;
			line++;
		}
		else
			write(1, " ", 1);
		col++;
	}
}
