/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:20:08 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/30 17:32:35 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	swp;
	int	swp2;

	swp = 0;
	while (tab[swp])
	{
		swp2 = 0;
		while (tab[swp2])
		{
			if (tab[swp2 + 1] && cmp(tab[swp2], tab[swp2 + 1]) > 0)
				ft_swap(&tab[swp2], &tab[swp2 + 1]);
			swp2++;
		}
		swp++;
	}
}
