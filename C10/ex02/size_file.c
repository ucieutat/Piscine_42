/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:56:35 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/27 12:47:33 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	size_file(char *filename)
{
	int		count;
	int		fd;
	char	buf;

	fd = open(filename, O_RDONLY);
	count = 0;
	while (read(fd, &buf, 1))
		count++;
	close(fd);
	return (count);
}
