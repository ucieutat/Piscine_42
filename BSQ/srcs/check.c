/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:59:37 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/29 23:22:36 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int	check_norminette(t_board *board, int fd, char *buf)
{
	int	i;
	int	ct;

	i = -1;
	ct = 0;
	while (*buf >= 32 && *buf <= 126)
	{
		while (board->charset[++i] == '\0' && i < 3)
		{
			board->charset[i] = *buf;
			read(fd, buf, 1);
			if (*buf == '\n')
				return (0);
		}
		if (is_number(board->charset[0]) && *buf != '\n')
		{
			board->map_len = board->map_len * 10 + (board->charset[0] - 48);
			board->charset[0] = board->charset[1];
			board->charset[1] = board->charset[2];
		}
		board->charset[2] = *buf;
		if (!read(fd, buf, 1))
			return (0);
	}
	return (1);
}

int	check_premiere_ligne(char *filename, t_board *board)
{
	int		fd;
	int		i;
	int		check;
	char	buf;

	fd = open(filename, O_RDONLY);
	i = -1;
	board->map_len = 0;
	while (++i < 3)
		board->charset[i] = '\0';
	read(fd, &buf, 1);
	check = check_norminette(board, fd, &buf);
	if (!check)
		return (0);
	if (board->map_len == 0)
		return (0);
	if (buf != '\n')
		return (0);
	if (!taille_ligne(board, fd, filename))
		return (0);
	return (1);
}

int	check_charset(char *charset)
{
	int	i;
	int	j;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] < 32 || charset[i] > 126)
			return (0);
		j = i;
		while (charset[++j])
			if (charset[i] == charset[j])
				return (0);
	}
	return (1);
}

int	parse_tableau(int fd, t_board *board, char buf)
{
	int		ct;
	int		i;

	i = 0;
	ct = 0;
	while (read(fd, &buf, 1))
	{
		if (buf != '\n')
		{
			if (!in_charset(buf, board->charset))
				return (0);
			board->plateau[i++] = buf;
			ct++;
		}
		else
		{
			if (ct != board->line_len)
				return (0);
			ct = 0;
		}
	}
	if (i > board->line_len * board->map_len)
		return (0);
	return (1);
}

int	taille_ligne(t_board *board, int fd, char *filename)
{
	char	buf;

	read(fd, &buf, 1);
	board->line_len = 0;
	while (buf != '\n')
	{
		if (!in_charset(buf, board->charset))
			return (0);
		board->line_len++;
		read(fd, &buf, 1);
	}
	board->plateau = malloc(sizeof(char) * board->map_len * board->line_len);
	close(fd);
	fd = open(filename, O_RDONLY);
	read(fd, &buf, 1);
	while (buf != '\n')
		read(fd, &buf, 1);
	if (!parse_tableau(fd, board, buf))
		return (0);
	close(fd);
	return (1);
}
