/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 08:37:52 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/20 09:14:35 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	if (*src == '\0')
	{
		*dest = *src;
		return (dest);
	}
	else
	{
		*dest = *src;
		ft_strcpy(dest + 1, src + 1);
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (dest);
	return (ft_strcpy(dest, src));
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			i;

	i = -1;
	if (ac <= 0)
		ac = 0;
	result = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (NULL);
	while (++i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup(av[i]);
	}
	result[i].str = 0;
	return (result);
}
