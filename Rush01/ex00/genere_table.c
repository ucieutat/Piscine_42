/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genere_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:32:15 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/19 18:36:16 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h" 

int	check_table(int nb, int *table)
{
	int	i;
	int	mod;
	int	div;

	i = -1;
	div = nb / SIZE;
	mod = nb % SIZE;
	while (++i < nb)
		if ((table[nb] == table[i]) && (mod == i % SIZE || div == i / SIZE))
			return (0);
	return (1);
}

int	compare_inputs(int *input, int *table)
{
	int	*result;
	int	i;
	int	total_corres;

	result = (int *)malloc(sizeof(int) * SIZE * SIZE);
	i = -1;
	total_corres = 0;
	while (++i < SIZE * SIZE)
		result[i] = 0;
	result = check_tab(table);
	i = -1;
	while (i < SIZE * SIZE)
	{
		if (input[i] == result[i])
			total_corres++;
		i++;
	}
	free(result);
	if (total_corres == SIZE * SIZE)
		return (1);
	return (0);
}

int	genere_table(int nb, int *table, int *input, int *cerise)
{
	table[nb] = 1;
	while (table[nb] <= SIZE)
	{
		if (check_table(nb, table))
		{
			if (nb == (SIZE * SIZE) - 1)
			{
				if (compare_inputs(input, table))
				{
					ft_table(table);
					*cerise = 1;
					return (0);
				}
			}
			else
				genere_table(nb + 1, table, input, cerise);
		}
		table[nb]++;
	}
	return (0);
}
