/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:39:06 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/01 17:00:21 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	move_player(int keycode, t_data *img)
{
	if (keycode == W_KEY)
		move_player_w(img);
	if (keycode == A_KEY)
		move_player_a(img);
	if (keycode == D_KEY)
		move_player_d(img);
	if (keycode == S_KEY)
		move_player_s(img);
	if (keycode == ESC_KEY)
		close_window(img);
	if (keycode == 124)
	{ 
		img->map->angle -= 0.1;
		draw_map(img);
		cast_rays(img);
	}
	if (keycode == 123)
	{ 
		img->map->angle += 0.1;
		draw_map(img);
		cast_rays(img);
	}
	return (0);
}

void cast_rays(t_data *img)
{	
	double	x  ;
	double	y ;

	double pi = M_PI;
	double angle = img->map->angle - (M_ / 6);
	while(angle < img->map->angle + (pi / 6))
	{
	 	y = img->map->y * 50;
	 	x = img->map->x * 50;
		i = img->width;
	 	while(i--)
	 	{
	 		mlx_pixel_put(img->mlx,img->win, x , y   , 0x14fff7);
	 		y +=  (cos(angle )) ;
			x += (sin(angle));
	 	}
		angle += 0.005;
	}	
 }

t_data	init_func(t_data img)
{
	img.height = (img.map->len - 1) * 50;
	img.width = (img.map->long_line - 1) * 50;
	img.map->y = img.map->y_player;
	img.map->x = img.map->x_player;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.width, img.height, "Hello");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	return (img);
}

void	ft_images(t_data *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx, "./images/wall.xpm",
		&img->width, &img->height);
	img->player = mlx_xpm_file_to_image(img->mlx, "./images/player.xpm",
		&img->width, &img->height);
	img->shadow = mlx_xpm_file_to_image(img->mlx, "./images/background.xpm",
		&img->width, &img->height);
}

void raycasting(t_data img)
{
	img = init_func(img);
	ft_images(&img);
	img.height = (img.map->len - 1) * 50;
	img.width = (img.map->long_line - 1) * 50;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_map(&img);
	//player moves//
	//cast_rays(&img);
	destroy_window(img);
	mlx_hook(img.win, 2, 0L, move_player, &img);
	mlx_loop(img.mlx);
}
