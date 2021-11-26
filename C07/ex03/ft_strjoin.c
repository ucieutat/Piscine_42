/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:11:28 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/20 20:24:50 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*cpyword(int size, char **strs, char *sep, char *a)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (++j < size)
	{
		i = -1;
		while (strs[j][++i])
			a[k++] = strs[j][i];
		if (j < size - 1)
		{
			i = -1;
			while (sep[++i])
				a[k++] = sep[i];
		}
	}
	a[k] = '\0';
	return (a);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*a;
	int		i;
	int		len_chaine;

	i = 0;
	len_chaine = 0;
	while (i < size)
	{
		len_chaine += ft_strlen(strs[i]) + ft_strlen(sep) + 1;
		i++;
	}
	a = (char *)malloc(sizeof(char) * len_chaine);
	if (!a)
		return (NULL);
	if (size == 0)
		return (a);
	a = cpyword(size, strs, sep, a);
	return (a);
}
