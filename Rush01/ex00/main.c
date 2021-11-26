/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:09:48 by jfrancai          #+#    #+#             */
/*   Updated: 2021/09/19 18:36:18 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int	*input;
	int	*output;
	int	i;
	int	cerise;

	i = -1;
	cerise = 0;
	input = (int *)malloc(sizeof(int) * SIZE * SIZE);
	output = (int *)malloc(sizeof(int) * SIZE * SIZE);
	while (++i < SIZE * SIZE)
		output[i] = 0;
	if (argc != 2)
		return (ft_error());
	if (!check_input_s_len(argv[1]))
		return (ft_error());
	if (!check_input_s(argv[1]))
		return (ft_error());
	input = ft_parse_input(argv[1], input);
	genere_table(0, output, input, &cerise);
	if (!cerise)
		return (ft_error());
	free(input);
	free(output);
	return (0);
}
