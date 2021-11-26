/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:14:48 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/27 14:33:05 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

t_op	which_operator(char *str)
{
	if (str[1] || !*str)
		return (autre);
	else if (*str == '+')
		return (op_addition);
	else if (*str == '-')
		return (op_soustraction);
	else if (*str == '/')
		return (op_division);
	else if (*str == '*')
		return (op_multiplication);
	else if (*str == '%')
		return (op_modulo);
	else
		return (autre);
}

int	main(int argc, char **argv)
{
	t_op	mon_operateur;
	void	(*fct[5])(int, int);

	fct[op_addition] = &addition;
	fct[op_soustraction] = &soustraction;
	fct[op_division] = &division;
	fct[op_multiplication] = &multiplication;
	fct[op_modulo] = &modulo;
	if (argc != 4)
		return (0);
	else
	{	
		mon_operateur = which_operator(argv[2]);
		if (mon_operateur == autre)
			ft_putnbr(0);
		else
			fct[mon_operateur](ft_atoi(argv[1]), ft_atoi(argv[3]));
		ft_putchar('\n');
	}
	return (0);
}
