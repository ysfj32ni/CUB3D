#include "../cub.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_map(t_data *img, t_map	*map, int row , int col)
{
	int x = 0;
	int y ;

    while (x < row )
	{
		y = 0;
		while (y < col)
		{
			if(map->map[x][y] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->imag,y * 50 , x * 50 );	
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->player,map->y_player * 50, map->y_player * 50);
	return (0);
}