/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 08:27:01 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/19 17:54:05 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_input_s_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i == 31)
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c < '1' || c > '4')
		return (0);
	return (1);
}

int	check_input_s(char *s)
{
	int	i;

	i = 0;
	while (i < 31)
	{
		if (!is_numeric(s[i]))
			return (0);
		if (s[i + 1] != ' ' && s[i + 1] != '\0')
			return (0);
		i += 2;
	}
	return (1);
}

int	*ft_parse_input(char *s, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 31)
	{
		tab[j] = s[i] - '0';
		i += 2;
		j++;
	}
	return (tab);
}
