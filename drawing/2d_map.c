#include "../cub.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_map(t_data *img)
{
	int row = doble_arr_len(img->map->map);
	int col = longest_line(img->map->map);
	int x = 0;
	int y ;

	int i = (img->map->x_player) + 0.5 ;
	int j = (img->map->y_player) + 0.5 ;

    while (x < row )
	{
		y = 0;
		while (y < col)
		{
			if(img->map->map[x][y] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->wall,y * 50 , x * 50 );	
			y++;
		}
		x++;
	}
	
	mlx_put_image_to_window(img->mlx, img->win, img->player,i * 50, j * 50);
	return (0);
}
