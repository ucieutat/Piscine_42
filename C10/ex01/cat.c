/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:48:25 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/27 20:44:22 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 2048

void	print_errors(char *str)
{
	write(2, "ft_cat: ", 8);
	while (*str)
	{
		write(2, str++, 1);
	}
	write(2, ": No such file or directory\n", 28);
}

void	display_stdout(char *file_name)
{
	int		fd;
	char	buf[BUFF_SIZE];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_errors(file_name);
	else
		while (read(fd, buf, 1))
			write(1, buf, 1);
	close(fd);
}

void	display_stdin(void)
{
	int		fd;
	char	buf[BUFF_SIZE];

	fd = 1;
	while (fd)
	{
		fd = read(STDIN_FILENO, buf, BUFF_SIZE);
		buf[fd] = '\0';
		write(1, buf, fd);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = 1;
	if (argc == 1)
		display_stdin();
	else
	{
		while (++i < argc)
		{
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				display_stdin();
			else
				display_stdout(argv[i]);
		}
	}
	return (0);
}
