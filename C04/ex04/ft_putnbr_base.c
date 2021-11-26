/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 08:40:46 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/13 19:10:06 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	doublon(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = i;
		while (str[++j])
		{
			if (str[i] == str[j])
				return (1);
		}
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	cast;

	i = -1;
	cast = nbr;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || doublon(base))
			return ;
	}
	if (i < 2)
		return ;
	if (cast < 0)
	{
		ft_putchar('-');
		cast = -cast;
	}
	if (cast >= ft_strlen(base))
		ft_putnbr_base(cast / ft_strlen(base), base);
	ft_putchar(base[cast % ft_strlen(base)]);
}
