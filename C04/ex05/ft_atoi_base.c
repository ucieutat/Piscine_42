/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:01:54 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/13 19:09:27 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base_len(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ')
			return (0);
		j = i;
		while (str[++j])
			if (str[i] == str[j])
				return (0);
	}
	if (i < 2)
		return (0);
	return (i);
}

int	position_base(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (c == str[i])
			return (i);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	sign;
	int	base_len;

	nb = 0;
	i = 0;
	sign = 1;
	base_len = check_base_len(base);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (base_len && position_base(str[i], base) >= 0)
	{
		nb = nb * base_len + position_base(str[i], base);
		i++;
	}
	return (sign * nb);
}
