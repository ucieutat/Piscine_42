/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:53:32 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/26 20:32:09 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*display_stdin(void)
{
	int		fd;
	char	*buffer;

	fd = 1;
	buffer = malloc(sizeof(char) * 2048);
	if (!buffer)
		return (NULL);
	while (fd)
		fd = read(STDIN_FILENO, buffer, 2048);
	buffer[ft_strlen(buffer)] = '\0';
	return (buffer);
}
