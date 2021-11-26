/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:50:52 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/14 12:20:23 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb < 0)
		return (0);
	if (nb == 0 || (unsigned)nb == 1)
		return (0);
	while (i * i <= (unsigned)nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (i <= 2)
		return (2);
	while (!ft_is_prime(i))
		i++;
	return (i);
}
