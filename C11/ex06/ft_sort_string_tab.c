/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:03:37 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/30 17:30:39 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_string_tab(char **tab)
{
	int	swp;
	int	swp2;

	swp = -1;
	while (tab[++swp])
	{
		swp2 = swp;
		while (tab[++swp2])
		{
			if (ft_strcmp(tab[swp2], tab[swp]) < 0)
				ft_swap(&tab[swp2], &tab[swp]);
		}
	}
}
