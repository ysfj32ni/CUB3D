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
// int	move_player(int key, void *p)
// {
// 	t_data *tmp = (t_data *)p;

// 	if (key == 125)
// 	{
// 		if(tmp->map->map[tmp->map->y_player + 5][tmp->map->x_player] == '0')
// 		{
// 			//tmp->map->map[tmp->map->y_player][tmp->map->x_player] = '0';
// 			//tmp->map->y_player += 5;
// 			//tmp->map->map[tmp->map->y_player][tmp->map->x_player] = 'S';
// 			draw_map(tmp);
// 		}
// 	}		
// 	return (0);
// }
int	move_player(int key, t_data *img)
{
	//t_map *tmp = (t_map *)p;

	if(!(img->map->y) && !(img->map->y))
	{
		printf("im not here");
		img->map->y = img->map->y_player;
		img->map->x = img->map->x_player;
	}
	// img->map->y = img->map->y_player;	
	// img->map->x = img->map->x_player;
	
	// if ((key == 126) && (img->map->map[y -1][x ] != '1'))
	// {
	// 		mlx_put_image_to_window(img->mlx, img->win, img->background,x * 50, y * 50);
	// 		mlx_put_image_to_window(img->mlx, img->win, img->player,x * 50, (y - 1 )* 50);	
	// 		img->map->y_player -= 1;
	// }
	if ((key == 125) && (img->map->map[img->map->y_player ][img->map->x_player ] == '0'))
	{ 
		
			printf("im here \n");
			mlx_put_image_to_window(img->mlx, img->win, img->shadow,img->map->x *50  , img->map->y *50);

		img->map->y += 0.1;
			
			mlx_put_image_to_window(img->mlx, img->win, img->player,img->map->x  * 50, img->map->y  * 50);
	}
	// if ((key == 123) && (img->map->map[y][x - 1] != '1'))
	// {
	// 		mlx_put_image_to_window(img->mlx, img->win, img->background,x * 50, y * 50);
	// 		mlx_put_image_to_window(img->mlx, img->win, img->player,(x -1)* 50, y * 50);	
	// 		img->map->x_player -= 1;
	// }
	// if ((key == 124) && (img->map->map[y ][x + 1] != '1'))
	// {
	// 		mlx_put_image_to_window(img->mlx, img->win, img->background,x * 50, y * 50);
	// 		mlx_put_image_to_window(img->mlx, img->win, img->player,(x + 1)* 50, y * 50);
	// 		img->map->x_player += 1;	
	// }
	
	// if(key == 125)
	// {
	// 	img->player->y_player -= 50;
	// 	//	printf("after = %d\n",img->map->y_player);
	// }
	return (0);
}
int	main(int ac, char **av)
{
	t_map	*map;
	t_data	img;
	int		len;
	int		line;

	img.map = malloc(sizeof(t_map *));
	if (ac > 1)
	{
		if (!check_path(av[1]))
			exit_error("ERROR : PATH must be *.cub\n");
		map = parsing(av[1]);
		
		img.map = map;
		len = doble_arr_len(map->map);
		line = longest_line(map->map);
		img.height = len * 50;
		img.width = line * 50;
		
		img.map->y = img.map->y_player;
		img.map->x = img.map->x_player;

		img.mlx = mlx_init();
		img.win = mlx_new_window(img.mlx, img.width, img.height, "Hello");
		img.img = mlx_new_image(img.mlx, img.width, img.height);
		img.wall = mlx_xpm_file_to_image(img.mlx, "./images/wall.xpm", &img.width, &img.height);
		img.player = mlx_xpm_file_to_image(img.mlx, "./images/player.xpm", &img.width, &img.height);
		img.shadow = mlx_xpm_file_to_image(img.mlx, "./images/10.xpm", &img.width, &img.height);
		
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		draw_map(&img);
		mlx_key_hook(img.win, move_player, &img);

		mlx_loop(img.mlx);
	}
	else
		exit_error("ERROR : Enought args [./cub3D map.cub]\n");
}
