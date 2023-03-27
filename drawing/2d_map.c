#include "../cub.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int draw_lines(t_data *img , int row, int col)
{
	 double		square = 50;
	 int		color = 0xBEBFC5;
		while (row <= img->width )
		{
			col = 0;
			printf("col = %d\n", col);
			printf("row %d\n", row);
			while (col <= img->height )
			{
				my_mlx_pixel_put(img, col, row, color);
				col += square;
			}
			row ++;
	 	}
	// row = 0;
	// col = 0;
	// while (row < img->height)
	// {
	// 	col = 0;
	// 	while (col < img->width)
	// 	{
	// 		my_mlx_pixel_put(img, col, row, color);
	// 		col+= square;
	// 	}
	// 	row ++;
	// }

	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	draw_map(t_data *img)
{
	
	int row = doble_arr_len(img->map->map);
	int col = longest_line(img->map->map);
	int x = 0;
	int y ;
	 int		color = 0xccff33;
	double i = (img->map->x)  ;
	double j = (img->map->y)  ;

		my_mlx_pixel_put(img, i * 50 , j * 50,color);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
		
		
		//mlx_put_image_to_window(img->mlx, img->win, img->player,i * 50 , j * 50 );
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
	//mlx_put_image_to_window(img->mlx, img->win, img->player,i * 50, j * 50);
	return (0);
}
