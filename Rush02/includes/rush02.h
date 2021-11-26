/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 09:28:37 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/26 22:50:12 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define SIZEOF_OUTPUT 2048

int		ft_strlen(char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
int		ft_index(char *str);
char	*ft_overkill(char c);
void	ft_match(int ind);
void	convert(char *input);
int		gestion_centaine(char c, char suiv, char suivsuiv);
int		gestion_dizaine(char c, char suiv);
void	gestion_trio(int div);
int		size_dict(char *filename);
char	***init(char *dict, char *input);
char	*display_stdin(void);
char	*ft_check_params(char *argv);
char	*ft_malloc_end(void);
char	*ft_malloc_params(char *argv, int i, int start);
char	***fill_dict(char *file_name);
char	***ft_init_work(char *file_name, int i);
char	***init_row(char ***dico, int i);
char	***read_line(int fd, char buf_lu, char ***dico, int i);
char	***fin_read_line(int fd, char *buf, char ***dico, int i);
void	ft_free(char ***dico, char *str);

char	**g_tab_right;
char	**g_tab_left;
int		g_espace;
char	*g_output;
int		g_error;
#endif
