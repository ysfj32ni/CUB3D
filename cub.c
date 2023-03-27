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

int	move_player(int key, t_data *img)
{
	int black = 0x000000;
	
	// {	printf("x = %f  y = %f \n", img->map->x , img->map->y);
	if (key == 126)
	{ 
		if(img->map->map[(int )(img->map->y -1 )][(int)img->map->x ] != '1' || (img->map->y - (int)img->map->y > 0.2))
		{
			//mlx_put_image_to_window(img->mlx, img->win, img->shadow,img->map->y * 50 , img->map->x * 50 );
			my_mlx_pixel_put(img, img->map->x * 50, img->map->y * 50 , black);
			img->map->y -= 0.1;
			draw_map(img);
		}	
	}
	if (key == 125)
	{ 
		if(img->map->map[(int )(img->map->y + 1 )][(int)img->map->x ] != '1' || (img->map->y - (int)img->map->y < 0.8))
		{
			my_mlx_pixel_put(img, img->map->x * 50, img->map->y * 50 , black);
			img->map->y += 0.1;
			draw_map(img);
		}	
	}
	if (key == 123)
	{ 

		if(img->map->map[(int )(img->map->y )][(int)img->map->x - 1 ] != '1'|| (img->map->x - (int)img->map->x > 0.2) )
		{
			my_mlx_pixel_put(img, img->map->x * 50, img->map->y * 50 , black);
			img->map->x -= 0.1;
			draw_map(img);
		}	
	}
	if (key == 124)
	{ 
		if(img->map->map[(int )(img->map->y  )][(int)img->map->x + 1] != '1' || (img->map->x - (int)img->map->x < 0.8))
		{
			my_mlx_pixel_put(img, img->map->x * 50, img->map->y * 50 , black);
			img->map->x += 0.1;
			draw_map(img);
		}	
	}
	
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
		printf("len == %d && line == %d \n", img.height , img.width);
		img.map->y = img.map->y_player;
		img.map->x = img.map->x_player;

		img.mlx = mlx_init();
		img.win = mlx_new_window(img.mlx, img.width, img.height, "Hello");
		img.img = mlx_new_image(img.mlx, img.width, img.height);
		img.wall = mlx_xpm_file_to_image(img.mlx, "./images/wall1.xpm", &img.width, &img.height);
		img.player = mlx_xpm_file_to_image(img.mlx, "./images/player1.xpm", &img.width, &img.height);
		img.shadow = mlx_xpm_file_to_image(img.mlx, "./images/hide.xpm", &img.width, &img.height);
		
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		draw_map(&img);
		//player moves//
		mlx_hook(img.win, 2, 0L, move_player, &img);
		mlx_loop(img.mlx);
	}
	else
		exit_error("ERROR : Enought args [./cub3D map.cub]\n");
}
