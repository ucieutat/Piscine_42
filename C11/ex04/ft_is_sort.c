/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 07:55:43 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/22 07:36:43 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	croissant;
	int	decroissant;

	i = -1;
	croissant = 1;
	decroissant = 1;
	if (length == 1 || length == 0)
		return (1);
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			croissant++;
		else if (f(tab[i], tab[i + 1]) < 0)
			decroissant++;
		else
		{
			croissant++;
			decroissant++;
		}
	}
	if (length == croissant || length == decroissant)
		return (1);
	return (0);
}
