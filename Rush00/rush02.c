/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:07:43 by hrode             #+#    #+#             */
/*   Updated: 2021/09/12 18:20:58 by hrode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y)
{
	int	a;
	int	b;

	b = 0;
	while (++b <= y)
	{
		a = 0;
		while (++a <= x)
		{
			if (a == 1 && b == 1)
				ft_putchar('A');
			else if (a == 1 && b == y)
				ft_putchar('C');
			else if (a == x && b == 1)
				ft_putchar('A');
			else if (a == x && b == y)
				ft_putchar('C');
			else if (a == 1 || b == 1 || a == x || b == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
