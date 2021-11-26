/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:27:38 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/19 20:34:12 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base_len(char *str);

int	malloc_base(unsigned int n, unsigned int base_size)
{
	if (n < base_size)
		return (1);
	return (1 + malloc_base(n / base_size, base_size));
}

char	*fill_dest(int len_base_to, long signed_nb, int sign, char *base_to)
{
	int		j;
	char	*dest;

	j = malloc_base(signed_nb, len_base_to) + sign;
	dest = malloc(sizeof(char) * (j + 1));
	if (!dest)
		return (NULL);
	dest[j] = '\0';
	while (j--)
	{
		dest[j] = base_to[signed_nb % len_base_to];
		signed_nb /= len_base_to;
	}
	if (sign)
		dest[0] = '-';
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long		i;
	int			len_base_to;
	int			sign;
	long		signed_nb;

	len_base_to = check_base_len(base_to);
	if (!(len_base_to && check_base_len(base_from)))
		return (NULL);
	i = ft_atoi_base(nbr, base_from);
	signed_nb = i;
	if (i < 0)
	{
		signed_nb = -i;
		sign = 1;
	}
	else
		sign = 0;
	return (fill_dest(len_base_to, signed_nb, sign, base_to));
}
