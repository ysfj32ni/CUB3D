/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:10:10 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/19 03:11:39 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	if ((x >= 0 && x < 1050  ) && (y >= 0 && y <  1050))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	draw_lines(t_data *img)
{
	float	x;
	float	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
			mlx_pixel_put(img->mlx, img->win, x, y++, 0xdee2e6);
		x += 50;
	}
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
			mlx_pixel_put(img->mlx, img->win, x++, y, 0xdee2e6);
		y += 50;
	}
	return (0);
}

int	draw_map(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < img->map->len - 1)
	{
		y = 0;
		while (y < img->map->long_line)
		{
			if (img->map->map[x][y] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->wall,
					y * 50, x * 50);
			else
				mlx_put_image_to_window(img->mlx, img->win, img->shadow,
					y * 50, x * 50);
			y++;
		}
		x++;
	}
	draw_lines(img);
	mlx_put_image_to_window(img->mlx, img->win, img->player,
		(img->map->x * 50 - 5), (img->map->y * 50) - 5);
	return (0);
}

void dala(t_data *img , double ray, double *x, int color, double r)
{
	double distance = (1050 / 2 ) * tan(M_PI / 6);
	double wall = distance / ((ray ) ) ;
		wall *= 2;

	if (wall >= 1050)
		wall = 1050 * 2;

	double y = (1050  / 2 ) - (wall / 2) ;
	(void)r;
	double i = (r) * (img->t.w);
	
	
	while(y < (1050 / 2) + (wall / 2 )  )
	{
		double j = (y - (1050  / 2 ) + (wall / 2)) * (img->t.h / wall);
		img->t.addr = mlx_get_data_addr(img->t.img, &img->t.bits_per_pixel, &img->t.line_length, &img->t.endian);
		char *dst = img->t.addr + (int)j * img->t.line_length + (int)(i ) * (img->t.bits_per_pixel / 8)  ;
		color = *(unsigned int*)dst;
		my_mlx_pixel_put(img,*x,y, color);
		y += 1;
		j++;
	}
}

void draw_world(t_data *img)
{
	int i = 0;
	int j;
	int color = 0xade8f4;


		while(i < 1050 )
		{	
			if(i > 1050 / 2)
				color = 0x454545;

			j = 0;
			while(j < (1050 ) )
			{
				my_mlx_pixel_put(img,j, i, color);
				j++;
			}	
			i++;
		}

}
