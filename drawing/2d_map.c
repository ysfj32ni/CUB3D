#include "../cub.h"
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int draw_lines(t_data *img )
{
	double x = 0 ;
	double y = 0 ;
<<<<<<< HEAD

	int color = 0xdee2e6;
	//draw_lines(img,row, col);
		while(x < img->width )
		{
			y = 0;
			while(y < img->height)
			{
				mlx_pixel_put(img->mlx,img->win, x  , y ,color);
		 		
=======
	int color = 0xdee2e6;
		
	while(x < img->width )
	{
		y = 0;
		while(y < img->height)
		{
			my_mlx_pixel_put(img, x, y, color);	
>>>>>>> 6677398a42e7b4afa98a9f1a3add9bbd7dfa16d1
				y++;
			}
			x += 50;
		}
<<<<<<< HEAD
		y = 0;
		x = 0;
		while(y < img->height)
		{
			x = 0;
			while(x < img->width)
			{
				mlx_pixel_put(img->mlx,img->win, x  , y ,color);		 		
				x++;
			}
			y += 50;
		}
		//mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
		return 0;
=======
	y = 0;
	x = 0;
	while(y < img->height)
	{
		x = 0;
		while(x < img->width)
		{
			my_mlx_pixel_put(img, x   , y ,color);	
			x++;
		}
		y += 50;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return 0;
>>>>>>> 6677398a42e7b4afa98a9f1a3add9bbd7dfa16d1
}

int	draw_map(t_data *img)
{
	
	int row = doble_arr_len(img->map->map);
	int col = longest_line(img->map->map) - 1;
	int x = 0;
	int y ;
<<<<<<< HEAD
	// int		color = 0xccff33;
	//  double i = (img->map->x)  ;
	//  double j = (img->map->y)  ;

	//draw_lines(img,row, col);
	//printf("i = %f && j = %f && row = %d && col= %d\n ", i,j,row,col);
		
		// while(img->map->map[(int )j][(int)i] != '1' )
		// {
		// 	my_mlx_pixel_put(img, (i * 50)  , (j * 50) + 10,color);
		//  	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
		// 	j+= 0.01;
		// }
		//mlx_put_image_to_window(img->mlx, img->win, img->player,(j ) * 50 , (i - 0.5 ) * 50 );
		
		// while(j < col - 1)
		// 	j++;
	
=======
	draw_lines(img );
	mlx_put_image_to_window(img->mlx, img->win, img->player,(img->map->x * 50) - 5  , (img->map->y * 50) - 5 );
>>>>>>> 6677398a42e7b4afa98a9f1a3add9bbd7dfa16d1
	while (x < row )
	{
		y = 0;
		while (y < col)
		{
			if(img->map->map[x][y] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->wall,y * 50 , x * 50 );	
			else
				mlx_put_image_to_window(img->mlx, img->win, img->background,y * 50 , x * 50 );	
			y++;
		}
		x++;
	}
<<<<<<< HEAD
	mlx_put_image_to_window(img->mlx, img->win, img->player,(img->map->x * 50) - 5  , (img->map->y * 50) - 5 );
	draw_lines(img );
	//mlx_put_image_to_window(img->mlx, img->win, img->player,i * 50, j * 50);
=======
>>>>>>> 6677398a42e7b4afa98a9f1a3add9bbd7dfa16d1
	return (0);
}
