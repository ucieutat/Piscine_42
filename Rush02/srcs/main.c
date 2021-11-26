/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucieutat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 09:20:30 by ucieutat          #+#    #+#             */
/*   Updated: 2021/09/26 22:51:12 by ucieutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_malloc_params(char *argv, int i, int start)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)malloc(sizeof(char) * ((i - start) + 1));
	if (!str)
		return (NULL);
	while ((argv[start] >= '0' && argv[start] <= '9') && argv[start] != '\0')
		str[j++] = argv[start++];
	str[j] = '\0';
	return (str);
}

char	*ft_malloc_end(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int	count_zero(char *argv, int end)
{
	while (!(argv[end] >= '1' && argv[end] <= '9'))
		end--;
	return (end);
}

char	*ft_check_params(char *argv)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	end = ft_strlen(argv) - 1;
	while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == ' ')
		i++;
	if (argv[i] == '-' || !(argv[i] >= '0' && argv[i] <= '9'))
		return ("Error\n");
	if ((count_zero(argv, end)) < 0)
	{
		str = ft_malloc_end();
		return (str);
	}
	while (argv[i] == '0')
		i++;
	start = i;
	while (argv[i] >= '0' && argv[i] <= '9')
		i++;
	if (argv[i] != '\0')
		return ("Error\n");
	str = ft_malloc_params(argv, i, start);
	return (str);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	***check;

	str = 0;
	check = 0;
	if (argc == 1 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (argc == 2)
	{
		str = ft_check_params(argv[1]);
		check = init("numbers.dict.txt", str);
	}
	else if (argc == 3)
	{
		str = ft_check_params(argv[2]);
		check = init(argv[1], str);
	}
	if (check)
		convert(str);
	ft_free(check, str);
	return (0);
}
