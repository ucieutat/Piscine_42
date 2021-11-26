/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autre_fill_dict.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmbede <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:03:14 by jmbede            #+#    #+#             */
/*   Updated: 2021/09/26 22:51:08 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	***fill_dict(char *file_name)
{
	int		i;
	char	buf;
	char	***dico;
	int		fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	dico = ft_init_work(file_name, i);
	if (!dico)
		return (NULL);
	if (!init_row(dico, i))
		return (NULL);
	while (read(fd, &buf, 1))
	{
		dico = read_line(fd, buf, dico, i);
		if (!dico)
			return (NULL);
		i++;
		if (!init_row(dico, i))
			return (NULL);
	}
	close(fd);
	return (dico);
}

char	***ft_init_work(char *file_name, int i)
{
	char	***dico;

	dico = 0;
	if (i == 0)
	{
		dico = malloc(sizeof(char ***) * 3);
		if (!dico)
			return (NULL);
		dico[0] = malloc(sizeof(char **) * size_dict(file_name) + 1);
		dico[1] = malloc(sizeof(char **) * size_dict(file_name) + 1);
		if (!dico[0] || !dico[1])
			return (NULL);
	}
	return (dico);
}

char	***init_row(char ***dico, int i)
{
	dico[0][i] = malloc(sizeof(char *) * 255);
	dico[1][i] = malloc(sizeof(char *) * 255);
	if (!dico[0][i] || !dico[1][i])
		return (NULL);
	return (dico);
}

char	***read_line(int fd, char buf, char ***dico, int i)
{
	int	j0;
	int	j1;

	j0 = 0;
	j1 = 0;
	while (buf != '\n')
	{
		while ((j0 == 0) && !(buf >= '0' && buf <= '9'))
			read(fd, &buf, 1);
		while (buf >= '0' && buf <= '9')
		{
			dico[0][i][j0++] = buf;
			read(fd, &buf, 1);
		}
		while (j0 > 0 && buf == ' ')
			read(fd, &buf, 1);
		read(fd, &buf, 1);
		dico = fin_read_line(fd, &buf, dico, i);
	}
	return (dico);
}

char	***fin_read_line(int fd, char *buf, char ***dico, int i)
{
	int		j1;

	j1 = 0;
	while (*buf == ' ')
		read(fd, buf, 1);
	while (*buf != '\n')
	{
		dico[1][i][j1++] = *buf;
		read(fd, buf, 1);
	}
	return (dico);
}
