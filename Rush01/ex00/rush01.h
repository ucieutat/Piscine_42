/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:28:03 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/19 18:36:13 by jfrancai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>
# include <stdlib.h>
# define SIZE 4

int		*ft_parse_input(char *s, int *tab);
int		ft_error(void);
void	ft_print_tab(int *tab);
int		*check_tab(int *input_tab);
int		check_table(int nb, int *table);
int		genere_table(int nb, int *table, int *input, int *cerise);
void	ft_table(int *tab);
int		is_visible(int input, int *row_column);
int		is_visible_rev(int input, int *row_column);
int		compare_inputs(int *input, int *table);
int		*create_column(int indice, int *input_tab);
int		*create_row(int indice, int *input_tab);
void	ft_table(int *tab);
void	ft_putchar(char c);
int		check_input_s_len(char *s);
int		check_input_s(char *s);
#endif
