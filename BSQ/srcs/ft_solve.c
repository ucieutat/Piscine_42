/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 07:18:27 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/29 17:13:19 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	genere_biggest_sqr(int j, t_board set)
{
	int	k;
	int	i;

	k = 0;
	while (++k <= set.line_len - j % set.line_len
		&& k <= set.map_len - j / set.map_len)
	{
		i = -1;
		while (++i < k)
		{
			if (set.plateau[k - 1 + j + i * set.line_len] == set.charset[1])
				return (k - 1);
			if (set.plateau[(k - 1) * set.line_len + j + i] == set.charset[1])
				return (k - 1);
		}
	}
	return (k - 1);
}

t_square	*ft_solve(t_board set)
{
	int			i;
	int			j;
	int			biggest;
	t_square	*tab;

	i = 0;
	j = -1;
	tab = malloc(sizeof(t_square) * set.map_len);
	tab[0].size = -1;
	while (++j < set.line_len * set.map_len)
	{
		if (tab[i].size > (set.line_len - j % set.line_len))
		{
			j += tab[i++].size - 1;
			tab[i].x = -1;
			tab[i].size = -1;
		}
		biggest = genere_biggest_sqr(j, set);
		if (biggest > tab[i].size)
		{
			tab[i].size = biggest;
			tab[i].x = j % set.line_len;
		}
	}
	return (tab);
}
