#include "../cub.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_map(t_data *img, t_map	*map)
{
	double	row = 0;
	double	col = 0;
	(void) map;
    int		color = 0xBEBFC5;
	
    while (col < img->width)
	{
		row = 0;
		while (row < img->height)
		{
			my_mlx_pixel_put(img, col, row, color);
			row++;
		}
		col += 50;
	}
	row = 0;
	col = 0;
	while (row < img->height)
	{
		col = 0;
		while (col < img->width)
		{
			my_mlx_pixel_put(img, col, row, color);
			col++;
		}
		row += 50;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}