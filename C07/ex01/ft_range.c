/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:14:50 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/16 20:26:59 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*a;
	int	i;

	if (min >= max)
		return (NULL);
	else
	{
		i = -1;
		a = malloc((max - min) * sizeof(int));
		while (++i < (max - min))
			a[i] = min + i;
	}
	return (a);
}
