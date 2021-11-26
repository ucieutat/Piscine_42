/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_visible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:09:17 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/19 18:09:25 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_visible(int input, int *row_column)
{
	int	i;

	i = -1;
	while (++i < SIZE)
	{
		if (row_column[i] == input)
			return (1);
		else if (row_column[i] > input)
			return (0);
	}
	return (0);
}

int	is_visible_rev(int input, int *row_column)
{
	int	i;

	i = SIZE;
	while (--i >= 0)
	{
		if (row_column[i] == input)
			return (1);
		else if (row_column[i] > input)
			return (0);
	}
	return (0);
}
