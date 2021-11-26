/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:20:37 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/20 20:19:02 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = -1;
	*range = malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	while (++i < (max - min))
	{
		(*range)[i] = min + i;
	}
	return (max - min);
}
