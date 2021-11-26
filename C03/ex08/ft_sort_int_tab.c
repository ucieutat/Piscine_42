/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:41:27 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/09 13:35:48 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	swp;
	int	swp2;

	swp = -1;
	while (++swp < size)
	{
		swp2 = -1;
		while (++swp2 < size - swp - 1)
		{
			if (tab[swp2] > tab[swp2 + 1])
				ft_swap(&tab[swp2], &tab[swp2 + 1]);
		}
	}
}
