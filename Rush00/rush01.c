/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrode <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:06:52 by hrode             #+#    #+#             */
/*   Updated: 2021/09/12 18:20:31 by hrode            ###   ########.fr       */
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
				ft_putchar('/');
			else if (a == 1 && b == y)
				ft_putchar('\\');
			else if (a == x && b == 1)
				ft_putchar('\\');
			else if (a == x && b == y)
				ft_putchar('/');
			else if (a == 1 || b == 1 || a == x || b == y)
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		ft_putchar("\n");
	}
}
