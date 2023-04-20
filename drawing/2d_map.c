/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:10:10 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 02:49:42 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	if ((x >= 0 && x < 1050 ) && (y >= 0 && y <  1050))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void dala(t_data *img , double ray, int side, double r)
{
	ray = ray * cos(img->map->angle - (img->map->view + (M_PI / 6)));
	double distance = (1050 / 2 ) * tan(M_PI / 6);
	double wall = distance / ((ray ) ) ;
	wall *= 2;
	int color = 0xFFFFFF;
	double y = (1050  / 2 ) - (wall / 2) ;
	while(y < (1050 / 2) + (wall / 2 )  )
	{
		double j = (y - (1050  / 2 ) + (wall / 2)) * (img->ea.h / wall);
		if(!img->ea.w)
			exit_error("ERROR : MLX");
		
		if(side == 1)
			color = no_texture(img, j, r);
		if(side == 2)
			color = ea_texture(img, j, r);
		if(side == 3)
			color = we_texture(img, j, r);
		if(side == 4)
			color = so_texture(img, j, r);	
		my_mlx_pixel_put(img,img->map->index,y, color);
		y += 1;
		j++;
	}
}

void	draw_world(t_data *img)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	color = img->map->c_color;
	while (i < 1050 )
	{
		if (i > 1050 / 2)
			color = img->map->f_color;
		j = 0;
		while (j < 1050)
		{
			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}
