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

void	initialisation(t_map *map)
{
	map->line = NULL;
	map->map = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->no_path = NULL;
	map->c_color = NULL;
	map->f_color = NULL;
}

t_map	*parsing(char *av)
{
	t_map *map;
 
	map = malloc(sizeof(t_map));
	initialisation(map);
	map->line = get_map(av);
	map_elements(map);
	check_elements(map->map);
	// print_2d(map->map);
	return (map);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac > 1)
	{
		if (!check_path(av[1]))
			exit_error("ERROR : PATH must be *.cub\n");
		map = parsing(av[1]);
		// printf("---------------------------\n");
		// print_2d(map->map);
		// printf("---------------------------\n");
	}
	else
		exit_error("ERROR : Enought args [./cub3D map.cub]\n");
}
