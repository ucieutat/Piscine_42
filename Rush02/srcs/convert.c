/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:35:11 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/26 22:50:18 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_index(char *str)
{
	int	i;

	i = -1;
	while (g_tab_left[++i])
		if (ft_strcmp(g_tab_left[i], str) == 0)
			return (i);
	return (-1);
}

void	ft_match(int ind)
{
	if (ind == -1)
	{
		g_output = "Dict Error\n";
		g_error = 1;
	}
	if (!g_error)
	{
		if (g_espace)
			ft_strcat(g_output, " ");
		ft_strcat(g_output, g_tab_right[ind]);
		g_espace = 1;
	}
}

char	*ft_overkill(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	init_diz(int *diz, int *cent)
{
	*diz = 1;
	*cent = 2;
}

void	convert(char *input)
{
	int		i;
	int		len;
	int		diz;
	int		cent;
	char	*str;

	i = -1;
	init_diz(&diz, &cent);
	len = ft_strlen(input) - 1;
	while (input[++i])
	{
		str = ft_overkill(input[i]);
		if ((len - i) % 3 == 2)
			cent = gestion_centaine(input[i], input[i + 1], input[i + 2]);
		else if (cent > 1 && (len - i) % 3 == 1)
			diz = gestion_dizaine(input[i], input[i + 1]);
		else if (cent >= 1 && diz && (len - i) % 3 == 0)
			ft_match(ft_index(str));
		if (cent >= 0 && (len - i) / 3 != (len - (i + 1)) / 3)
		{
			gestion_trio((len - i) / 3);
			init_diz(&diz, &cent);
		}
	}
	free(str);
}
