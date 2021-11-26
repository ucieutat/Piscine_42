/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:52:42 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/27 20:59:48 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_load_file(int fd, unsigned int *size, char *path)
{
	char	buf[2048];
	char	*result;
	int		len;
	int		tmp;

	*size = size_file(path);
	result = malloc(sizeof(char) * (*size + 1));
	if (!result)
		return (NULL);
	tmp = 0;
	len = read(fd, buf, 2048);
	while (len > 0)
	{
		ft_strncpy(result + tmp, buf, len);
		tmp += len;
		len = read(fd, buf, 2048);
	}
	result[*size] = '\0';
	return (result);
}

char	*ft_load_stdin(unsigned int *size)
{
	char	buf[2048];
	char	*result;
	int		fd;

	fd = 1;
	*size = 0;
	result = malloc(sizeof(char) * 2048);
	if (!result)
		return (NULL);
	while (fd)
	{
		fd = read(STDIN_FILENO, buf, 2048);
		buf[fd] = '\0';
		ft_strncpy(result + *size, buf, fd);
		*size += fd;
	}
	result[*size] = '\0';
	return (result);
}

int	ft_tail(char *path, unsigned int n)
{
	char			*result;
	int				fd;
	unsigned int	size;

	fd = 0;
	if (path)
	{
		fd = open(path, O_RDONLY);
		result = ft_load_file(fd, &size, path);
		close(fd);
	}
	else
		result = ft_load_stdin(&size);
	if (!result)
		return (-1);
	if (n > size)
		n = size;
	ft_putstr(result + size - n, 1);
	free(result);
	return (0);
}
