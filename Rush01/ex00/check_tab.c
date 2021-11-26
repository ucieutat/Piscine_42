/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:56:32 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/19 18:01:44 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	*create_column(int indice, int *input_tab)
{
	int	j;
	int	*output_tab;

	j = -1;
	output_tab = (int *)malloc(sizeof(int) * SIZE);
	while (++j < SIZE * SIZE)
	{
		if (j % 4 == indice)
			output_tab[j / 4] = input_tab[j];
	}
	return (output_tab);
}

int	*create_row(int indice, int *input_tab)
{
	int	j;
	int	*output_tab;

	j = -1;
	output_tab = (int *)malloc(sizeof(int) * SIZE);
	while (++j < SIZE)
		output_tab[j] = input_tab[indice + j];
	return (output_tab);
}

void	visible_calculator(int *nb_visible, int *column, int *row, int i)
{
	int	k;

	k = -1;
	while (++k < SIZE)
	{
		if (is_visible(k, column))
			nb_visible[i] += 1;
		if (is_visible_rev(k, column))
			nb_visible[i + SIZE] += 1;
		if (is_visible(k, row))
			nb_visible[i + (2 * SIZE)] += 1;
		if (is_visible_rev(k, row))
			nb_visible[i + (3 * SIZE)] += 1;
	}
}

int	*check_tab(int *input_tab)
{
	int	i;
	int	*nb_visible;
	int	*column;
	int	*row;

	i = -1;
	nb_visible = (int *)malloc(sizeof(int) * SIZE * SIZE);
	column = (int *)malloc(sizeof(int) * SIZE);
	row = (int *)malloc(sizeof(int) * SIZE);
	while (++i < SIZE * SIZE)
		nb_visible[i] = 1;
	i = -1;
	while (++i < SIZE)
	{
		column = create_column(i, input_tab);
		row = create_row(i * SIZE, input_tab);
		visible_calculator(nb_visible, column, row, i);
	}
	free(column);
	free(row);
	return (nb_visible);
}
