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
	if (key == 13)
	{ 
		if(img->map->map[(int )(img->map->y -1 )][(int)img->map->x ] != '1'  || (img->map->y - (int)img->map->y > 0.2))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
			img->map->y -= 0.1;
			draw_map(img);
			cast_rays(img);
		}	
	}
	if (key == 1)
	{ 
		if(img->map->map[(int )(img->map->y + 1 )][(int)img->map->x ] != '1' || (img->map->y - (int)img->map->y < 0.8))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
			img->map->y += 0.1;
			draw_map(img);
			cast_rays(img);
		}	
	}
	if (key == 0)
	{ 

		if(img->map->map[(int )(img->map->y )][(int)img->map->x - 1 ] != '1' ||  (img->map->x - (int)img->map->x > 0.2) )
		{
			mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
			img->map->x -= 0.1;
			draw_map(img);
			cast_rays(img);
		}	
	}
	if (key == 2)
	{ 
		if(img->map->map[(int )(img->map->y  )][(int)img->map->x + 1] != '1' || (img->map->x - (int)img->map->x < 0.8))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
			img->map->x += 0.1;
			draw_map(img);
			cast_rays(img);
		}	
	}
	
	return (0);
}
void cast_rays(t_data *img )
{	
	int i = 41;
	double r = 1;
	int		color = 0x14fff7;
	double	x ;
	double	y ;
	while(i > 0)
	{
		y = img->map->y * 50;
		x = img->map->x * 50;
		while(y < img->height)
		{
			mlx_pixel_put(img->mlx,img->win, x  , y ,color);
			y += 1;
			x += r;
		}
		r = r -  0.025;
		i --;
	}
	i = 41;
	while(i > 0)
	{
		y = img->map->y * 50;
		x = img->map->x * 50;
		while(y < img->height)
		{
			mlx_pixel_put(img->mlx,img->win, x  , y ,color);
			y += 1;
			x -= r;
		}
		r = r + 0.025;
		i --;
	}
	i = 41;
	while(i > 0)
	{
		y = img->map->y * 50;
		x = img->map->x * 50;
		while(y > 0)
		{
			mlx_pixel_put(img->mlx,img->win, x  , y ,color);
			y -= 1;
			x += r;
		}
		r = r - 0.025;
		i --;
	}
	i = 41;
	while(i > 0)
	{
		y = img->map->y * 50;
		x = img->map->x * 50;
		while(y > 0)
		{
			mlx_pixel_put(img->mlx,img->win, x  , y ,color);
			y -= 1;
			x -= r;
		}
		r = r + 0.025;
		i --;
	}
	
 }
int	main(int ac, char **av)
{
	t_data	img;
	int		len;
	int		line;

	img.map = malloc(sizeof(t_map *));
	if (ac > 1)
	{
		if (!check_path(av[1]))
			exit_error("ERROR : PATH must be *.cub\n");
		img.map = parsing(av[1]);
		printf("start : %f\n", img.map->start_pos);
		// raycasting(img);
		// img.map = map;
		len = doble_arr_len(img.map->map);
		line = longest_line(img.map->map) - 1;
		img.height = len * 50;
		img.width = line * 50;
		img.map->y = img.map->y_player;
		img.map->x = img.map->x_player;

		img.mlx = mlx_init();
		img.win = mlx_new_window(img.mlx, img.width, img.height, "Hello");
		img.img = mlx_new_image(img.mlx, img.width, img.height);
		
		img.wall = mlx_xpm_file_to_image(img.mlx, "./images/wall.xpm", &img.width, &img.height);
		img.player = mlx_xpm_file_to_image(img.mlx, "./images/player.xpm", &img.width, &img.height);
		img.shadow = mlx_xpm_file_to_image(img.mlx, "./images/background.xpm", &img.width, &img.height);
		
		img.height = len * 50;
		img.width = line * 50;
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		draw_map(&img);
		//player moves//
		//cast_rays(&img);
		mlx_hook(img.win, 2, 0L, move_player, &img);
		mlx_loop(img.mlx);
	}
	else
		exit_error("ERROR : Enought args [./cub3D map.cub]\n");
}

