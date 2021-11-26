/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:57:34 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/21 18:56:10 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

typedef enum e_op
{
	op_addition,
	op_soustraction,
	op_division,
	op_multiplication,
	op_modulo,
	autre,
}	t_op;

void	ft_putnbr(int nb);
void	ft_putchar(char c);
int		ft_atoi(char *str);
void	addition(int a, int b);
void	soustraction(int a, int b);
void	division(int a, int b);
void	multiplication(int a, int b);
void	modulo(int a, int b);
void	ft_putstr(char *s);
#endif
