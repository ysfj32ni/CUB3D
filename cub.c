/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:37:17 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/03 16:38:46 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_bool	check_map(char *av)
{
	int		i;
	char	*test;

	i = 0;
	test = ft_strnstr(av, ".cub", ft_strlen(av));
	if (test && ft_strlen(test) == 4)
		return (TRUE);
	else
		return (FALSE);
}

char	**get_map(char *av)
{
	char	*buf;
	char	*current;
	char	**line;
	int		fd;

	fd = open(av, O_RDWR);
	if (fd < 0)
	{
		ft_putstr_fd("ERROR : PATH of map\n", 2);
		exit(EXIT_FAILURE);
	}
	buf = 0;
	current = get_next_line(fd);
	while (current)
	{
		buf = ft_strjoin(buf, current);
		current = get_next_line(fd);
	}
	line = ft_split(buf, '\n');
	return (line);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	if (ac > 1)
	{
		if (!check_map(av[1]))
		{
			ft_putstr_fd("ERROR : PATH of map\n", 2);
			exit(EXIT_FAILURE);
		}
		data = malloc(sizeof(t_data));
		data->line = get_map(av[1]);
		i = 0;
		while (data->line[i] != NULL)
		{
			printf("[%s]\n", data->line[i]);
			i++;
		}
	}
	else
		ft_putstr_fd("ERROR : PATH of map\n", 2);
}
