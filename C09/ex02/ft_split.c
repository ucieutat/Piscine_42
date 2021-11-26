/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:06:11 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/17 14:52:54 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_sep(char *str, char *sep)
{
	while (*sep)
		if (*str == *sep++)
			return (1);
	return (0);
}

int	len_word(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && (char_sep(str + i, sep) == 0))
		i++;
	return (i);
}

char	*cpyword(char *src, int size)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == 0)
		return (NULL);
	dest[size] = '\0';
	while (size--)
		dest[size] = src[size];
	return (dest);
}

int	nb_words(char *str, char *sep)
{
	int	j;
	int	result;

	result = 0;
	while (*str)
	{
		while (*str && char_sep(str, sep))
			str++;
		j = len_word(str, sep);
		str += j;
		if (j)
			result++;
	}
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**result;
	int		nb_mots;

	i = -1;
	j = 0;
	nb_mots = nb_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (nb_mots + 1));
	if (!result)
		return (NULL);
	while (++i < nb_mots)
	{
		while (*str && char_sep(str, charset))
			str++;
		j = len_word(str, charset);
		result[i] = cpyword(str, j);
		if (result[i] == 0)
			return (NULL);
		str += j;
	}
	result[nb_mots] = 0;
	return (result);
}
