/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_dizaine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:19:30 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/26 21:41:21 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/* Fonction pour gerer les groupes dizaines : on teste les deux entrees,
 * et on cree la bonne string correspondante (12, 23, 40...) */
int	gestion_dizaine(char c, char suiv)
{
	char	*str;

	str = malloc(sizeof(char) * 4);
	str[0] = c;
	str[2] = '\0';
	if (c == '1')
	{
		str[1] = suiv;
		ft_match(ft_index(str));
		free(str);
		return (0);
	}
	else
	{
		str[1] = '0';
		ft_match(ft_index(str));
		if (suiv == '0')
		{
			free(str);
			return (0);
		}
	}
	free(str);
	return (1);
}

/* Affichage des centaines et test si la centaine est vide */
int	gestion_centaine(char c, char suiv, char suivsuiv)
{
	if (c == '0' && suiv == '0' && suivsuiv == '0')
		return (-1);
	else if (c == '0' && suiv == '0')
		return (1);
	else
	{
		if (c != '0')
		{
			ft_match(ft_index(ft_overkill(c)));
			ft_match(ft_index("100"));
		}
		if (suiv == '0' && suivsuiv == '0')
			return (0);
		else if (suiv == '0')
			return (1);
		else
			 return (2);
	}
}

/* A la fin d'une triplette, affichage ou non du mot
 * (thousand, million...) */
void	gestion_trio(int div)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char) * (3 * div + 2));
	if (!str)
	{
		g_output = "Error\n";
		g_error = 1;
		return ;
	}
	str[0] = '1';
	str[1] = '\0';
	while (++i < 3 * div)
		str = ft_strcat(str, "0");
	ft_match(ft_index(str));
	free(str);
}
