/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 08:49:03 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/20 15:36:07 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
	ft_putchar('\n');
}

void	ft_putnbr(int nb)
{
	long	cast;

	cast = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		cast = -cast;
	}
	if (cast > 9)
	{
		ft_putnbr(cast / 10);
		cast %= 10;
	}
	ft_putchar(cast + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (!par)
		return ;
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putstr(par->copy);
		par++;
	}
}
