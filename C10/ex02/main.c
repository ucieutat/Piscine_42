/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:13:21 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/27 20:59:49 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_errors(char *str, char *base, char *error)
{
	ft_putstr(base, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(str, STDERR_FILENO);
	ft_putstr(": ", STDERR_FILENO);
	ft_putstr(error, STDERR_FILENO);
	ft_putstr("\n", STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	int				i;
	unsigned int	j;

	if (argc < 3 || ft_strcmp(argv[1], "-c"))
		return (0);
	if (ft_atoi(argv[2]) < 0)
		j = -ft_atoi(argv[2]);
	else
		j = ft_atoi(argv[2]);
	if (argc == 3 && ft_tail(NULL, j) < 0)
		print_errors(NULL, basename(argv[0]), strerror(errno));
	i = 2;
	while (++i < argc)
		if (ft_tail(argv[i], j) < 0)
			print_errors(argv[i], basename(argv[0]), strerror(errno));
	return (0);
}
