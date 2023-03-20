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
int	move_player(int key, void *p)
{
	t_map *tmp = (t_map *)p;

	if (key == 53)
		tmp->x_player += 3;		
	return (0);
}
int	main(int ac, char **av)
{
	t_map	*map;
	t_data	img;
	int		len;
	int		line;

	if (ac > 1)
	{
		if (!check_path(av[1]))
			exit_error("ERROR : PATH must be *.cub\n");
		map = parsing(av[1]);
		len = doble_arr_len(map->map);
		line = longest_line(map->map);
		img.height = len * 50 ;
		img.width = line * 50;
		img.mlx = mlx_init();
		img.win = mlx_new_window(img.mlx, img.width, img.height, "Hello");
		img.img = mlx_new_image(img.mlx, img.width, img.height);
		img.imag = mlx_xpm_file_to_image(img.mlx, "./images/1.xpm", &img.width, &img.height);
		img.player = mlx_xpm_file_to_image(img.mlx, "./images/player.xpm", &img.width, &img.height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		draw_map(&img , map, len ,line);
		mlx_loop(img.mlx);
	}
	else
		exit_error("ERROR : Enought args [./cub3D map.cub]\n");
}
