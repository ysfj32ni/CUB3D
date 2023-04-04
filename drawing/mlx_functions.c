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
int comp(float z,  float y)
{
	float eps = 0.000000000001;
	return ( fabs(z - y) <= eps);
}

void cast_rays(t_data *img)
{	
	float	x  ;
	float	y ;
	//int		i;
	//float square  = 50;
	float	ry = 0;
	float 	rx = 0; ;
	int line;
	y = img->map->y * 50;
	x = img->map->x * 50;
	

	// 	// horizontal
	
	
	line = floor(img->map->y) ;
	ry = img->map->y - (float)line; 
	printf("==============================>ry = %f  y = %f line == %d  line1 = %d \n", ry ,img->map->y, line, (int)(img->map->y) );	
	
	//float temp = 1.0;
	//if(ry == 0.0)
	
	printf("RY == %.10lf\n", ry);
	// if (comp(ry, 0.0))
	
	//if(img->map->y == (float)line )
	//	ry = 1.0 ;
	 if (ry == 0.000000)
	{
		write(1, "help\n", 5);
		rx = 1.0 / tan(img->map->angle)  ;
	}
	else
		rx = ry / tan(img->map->angle)  ;
	//vertical
	// line = (int)img->map->x;
	// if((int)x == line)
	// 	rx = (x / 50) - (line - 1);		
	// else
	// 	rx = (x / 50) - line ;
	printf(" ==============================> rx == %f  \n", rx );
	 int	i = img->width;
	 	while(i--)
	 	{
	 		mlx_pixel_put(img->mlx,img->win, x, y, 0xfee440);
			y -= sin(img->map->angle);
			x += cos(img->map->angle);
	 	}


 }

t_data	init_func(t_data img)
{
	img.height = (img.map->len - 1) * 50;
	img.width = (img.map->long_line - 1) * 50;
	img.map->y = img.map->y_player;
	img.map->x = img.map->x_player;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, (int)img.width, (int)img.height, "Hello");
	img.img = mlx_new_image(img.mlx, (int)img.width, (int)img.height);
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
