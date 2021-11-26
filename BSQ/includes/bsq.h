/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:15:23 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/29 19:23:36 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_board
{
	char	*plateau;
	char	*charset;
	int		map_len;
	int		line_len;
}	t_board;
typedef struct s_square
{
	int	x;
	int	size;
}	t_square;
int			in_charset(char c, char *charset);
int			check_premiere_ligne(char *filename, t_board *board);
int			check_charset(char *charset);
int			parse_tableau(int fd, t_board *board, char buf);
int			taille_ligne(t_board *board, int fd, char *filename);
int			genere_biggest_sqr(int j, t_board set);
t_square	*ft_solve(t_board set);
void		print_board(t_board board);
int			find_best_sqr(t_square *tab, int board_size, t_square *best_sqr);
void		affichage(t_square *results, t_board board);
int			ft_strlen(char *str);
int			check_norminette(t_board *board, int fd, char *buf);
int			is_number(char c);
#endif
