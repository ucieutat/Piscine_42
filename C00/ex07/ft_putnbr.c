/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:48:50 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/08 18:34:26 by ucieutat         ###   ########.fr       */
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
