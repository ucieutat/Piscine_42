/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:02:04 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/27 17:57:56 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

int		ft_strlen(char *s);
void	ft_putstr(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_atoi(char *str);
int		ft_tail(char *path, unsigned int n);
int		size_file(char *filename);
char	*ft_load_file(int fd, unsigned int *size, char *path);
char	*ft_load_stdin(unsigned int *size);
#endif
