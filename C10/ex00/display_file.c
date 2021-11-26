/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:46:13 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/27 20:48:27 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 2048

void	display_file(char *path)
{
	char	buf[BUFF_SIZE];
	int		fd;
	int		lettre;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	lettre = 1;
	while (lettre)
	{
		lettre = read(fd, buf, BUFF_SIZE);
		buf[lettre] = '\0';
		write(1, buf, lettre);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display_file(argv[1]);
	return (0);
}
