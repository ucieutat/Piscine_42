/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:58:32 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/10 11:25:20 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	afficher(int *nombre, int n)
{
	int	i;
	int	bin;

	bin = 1;
	i = 0;
	while (++i < n)
		if (nombre[i - 1] >= nombre[i])
			bin = 0;
	if (!bin)
		return ;
	i = -1;
	while (++i < n)
		ft_putchar(nombre[i] + '0');
	if (nombre[0] < (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	nombre[10];

	if (n > 10 || n < 0)
		return ;
	i = -1;
	while (++i < n)
		nombre[i] = i;
	while (nombre[0] <= (10 - n) && n >= 1)
	{
		afficher(nombre, n);
		if (n == 10)
			break ;
		nombre[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (nombre[i] > 9)
			{
				nombre[i - 1]++;
				nombre[i] = 0;
			}
		}
	}
}
