/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 20:31:49 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/26 22:51:13 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	size_dict(char *filename)
{
	int		fd;
	char	buf;
	int		count;

	fd = open(filename, O_RDONLY);
	count = 0;
	while (read(fd, &buf, 1))
		if (buf == '\n')
			count++;
	close(fd);
	return (count + 1);
}

char	***init(char *dict, char *input)
{
	char	***dico;

	if (*input == 'E')
	{
		write(2, "Error\n", 6);
		return (0);
	}
	g_output = malloc(sizeof(char) * SIZEOF_OUTPUT);
	if (!g_output)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	g_espace = 0;
	g_error = 0;
	dico = fill_dict(dict);
	g_tab_left = dico[0];
	g_tab_right = dico[1];
	if (!g_tab_left || !g_tab_right)
	{
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	return (dico);
}

void	ft_free(char ***dico, char *str)
{
	int	i;
	int	j;

	i = -1;
	ft_putstr(g_output);
	free(g_output);
	free(str);
	while (++i < 2)
	{
		j = -1;
		while (dico[i][++j])
			free(dico[i][j]);
	}
}
