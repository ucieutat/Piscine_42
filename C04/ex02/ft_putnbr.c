/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:36:01 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/12 20:36:07 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
