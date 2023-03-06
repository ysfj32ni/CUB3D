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

void	print_2d(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
	{
		printf("==> i : %i\n" , i);
		printf("[%s]\n", str[i]);
	}
}

void	exit_error(char	*str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

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
		exit_error("ERROR : PATH of map\n");
	buf = 0;
	current = get_next_line(fd);
	while (current)
	{
		buf = ft_strjoin(buf, current);
		current = get_next_line(fd);
	}
	line = ft_split(buf, '\n');
	if (!line)
		exit_error("ERROR : Empty file\n");
	return (line);
}

int	skip_spaces_begin(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != SPACE && str[i] != TAB)
			return (i);
		else
			i++;
	}
	return (i);
}

void	map_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		j = skip_spaces_begin(map->line[i]);
		if (!ft_strncmp((map->line[i] + j), "WE ", 3))
			map->we_path = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "NO ", 3))
			map->no_path = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "SO ", 3))
			map->so_path = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "EA ", 3))
			map->ea_path = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "F ", 2))
			map->f_color = ft_strdup(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "C ", 2))
			map->c_color = ft_strdup(map->line[i] + j);
		else
			exit_error("ERROR : wrong elements in map\n");
		i++;
	}
	j = 0;
	map->map = malloc(sizeof(char *));
	while (map->line[i] != NULL)
	{
		map->map[j] = ft_strdup(map->line[i]);
		i++;
		j++;
	}
}

int	main(int ac, char **av)
{
	t_map	*map;
	int	i = 0;

	if (ac > 1)
	{
		if (!check_map(av[1]))
			exit_error("ERROR : PATH of map\n");
		map = malloc(sizeof(t_map));
		map->line = get_map(av[1]);
		map_elements(map);
		print_2d(map->map);
	}
	else
		exit_error("ERROR : Enought args [./cub3D map.cub]\n");
}
