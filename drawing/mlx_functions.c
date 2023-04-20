/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:39:06 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 02:21:07 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	comp(float z, float y)
{
	float	eps;

	eps = 0.000000000001;
	return (fabs(z - y) <= eps);
}

double	cast_rays1(t_data *img , float view , double *r)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = floor(img->map->y) ;
	ry = img->map->y - line; 
	rx = (ry / tan(view))  ;
	//printf("rx === %f\n", rx);
	ray = (sqrt((pow(ry, 2) + pow(rx, 2))));
	
	next_y = floor(img->map->y - ry);
	next_x = floor(img->map->x + rx);

	//double r = rx;

	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width  / 50 ) && next_x >= 0))
	{	
		if(img->map->map[next_y - 1  ][next_x ] == '1')
		{
			*r = (( img->map->x  + rx) - (int ) ( img->map->x  + rx)  )    ;
			return (ray);
		}
	
	}

	while (TRUE)
	{	
		ry += 1; 
		rx = fabs((fabs(ry) / tan(view)));
		next_x = floor(img->map->x + rx );
		
		next_y = floor(img->map->y - ry);
		ray =  sqrt((pow(ry,2) + pow(rx,2)));
		if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
		{
			if(img->map->map[next_y - 1][next_x] == '1')
			{

					*r = (( img->map->x  + rx) - (int ) ( img->map->x  + rx)  )    ;
				break;
			}
		}
		else
			break;
	}
	
	return (ray);
}

double	cast_rays2(t_data *img , float view , double *r)
{
	float	ry = 0;
	float 	rx = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;	
	
	rx =   ceil(img->map->x) - img->map->x  ;
	ry = rx * tan( view); 
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x + rx ) ;

if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
{	
	if(img->map->map[next_y ][next_x ] == '1')
		{
			*r = ((img->map->y - ry) - (int) (img->map->y - ry))  ;
				return (ray);
		
		}
}
	 	while(TRUE)
		{	
	 			rx +=  1;
				ry = rx * tan( view); 
				if(ry > img->map->y)
					ry = img->map->y;
				ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
				next_y = floor(img->map->y - ry );
				next_x = floor(img->map->x + rx ) ;
				if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
				{
					if(img->map->map[next_y ][next_x ] == '1')	
					{
						*r = ((img->map->y - ry) - (int) (img->map->y - ry))  ;
						break;		
					}

				}
				else
					break;
		} 		
	return (ray);
}

double cast_rays3(t_data *img, float view , double *r)
{
	float	ry = 0;
	float 	rx = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;	
	
	rx =  img->map->x - floor(img->map->x);
	ry = rx * tan(M_PI -  view);
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x - rx ) ;

	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
	{
	 	if(img->map->map[next_y ][next_x - 1 ] == '1')
	 	{
			*r = ((img->map->y - ry) - (int) (img->map->y - ry));
				return (ray);
		
		}
	}
	 	while(TRUE)
		{	
	 			rx +=  1;
				ry = rx * tan( M_PI  - view); 
				ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
				next_y = floor(img->map->y - ry );
				next_x = floor(img->map->x - rx ) ;
				if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
				{
					if(img->map->map[next_y ][next_x -  1] == '1')
						{
							*r = ((img->map->y - ry) - (int) (img->map->y - ry)); 
							break;
						}			
				}
				else
					break;
		}	
	return (ray);
}

double cast_rays4(t_data *img, float view ,double *r)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = floor(img->map->y) ;
	ry = img->map->y - (float)line; 
	rx = (ry / tan(M_PI - view))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
	{
		if(img->map->map[next_y - 1  ][next_x ] == '1')
		{
				*r = ( img->map->x  - rx) - (int ) ( img->map->x  - rx);
			return ray;
		}
	}	

			while (TRUE)
			 {	
					ry += 1; 
					rx = fabs((fabs(ry) / tan(M_PI - view)));
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y - ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y - 1  ][next_x ] == '1')	
						{
								*r = ( img->map->x  - rx) - (int ) ( img->map->x  - rx);
								break;
						}		
					}
					else
						break;	
			 }
	return (ray);
}

double cast_rays5(t_data *img, float view ,double *r)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = ceil(img->map->y) ;
	ry = (float)line -  img->map->y  ; 
	rx = (ry / tan(view - M_PI))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y + ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
	{	
		if(img->map->map[next_y   ][next_x ] == '1')
		{
			*r = (( img->map->x  - rx) - (int ) ( img->map->x  - rx)  );
			return ray;
		}	
	}
			while (TRUE)
			 {				
					ry += 1; 
					rx = fabs((fabs(ry) / tan(M_PI - view)));
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y + ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y   ][next_x ] == '1')
						{
							*r = (( img->map->x  - rx) - (int ) ( img->map->x  - rx)  );
							break;
						}		
					}
					else
						break;
			 }
	return (ray);
}

double cast_rays6(t_data *img, float view ,double *r)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = ceil(img->map->y) ;
	ry = (float)line -  img->map->y  ; 
	rx = ry * tan( ((3 * M_PI) / 2) - view )  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y + ry );
	next_x = floor(img->map->x - rx );
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width / 50 ) && next_x >= 0))
	{
			if(img->map->map[next_y ][next_x ] == '1')
			{	
				*r = (( img->map->x  - rx) - (int ) ( img->map->x  - rx)  );
				return ray;
			}
	}
			while (TRUE)
			 {	
					ry += 1; 
					rx = (ry * tan( ((3 * M_PI) / 2) - view )) ;
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y + ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x < (img->width  / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y   ][next_x  ] == '1')
						{
							*r = (( img->map->x  - rx) - (int ) ( img->map->x  - rx)  );
								break;		
						}
					}
					else
						break;
			 }
	return (ray);
}

void	draw_rays(t_data *img, float ray,int color)
{
	double	x;
	double	y;
	int		i;

	y = img->map->y * 50;
	x = img->map->x * 50;
	i = (( ray ) * 50);
	while(i--) 
	{
		mlx_pixel_put(img->mlx,img->win, x, y, color);
		y -= sin(img->map->view);
		x += cos(img->map->view);
 	}
}

t_data	*init_func(t_data *img)
{
	img->height = (img->map->len - 1) * 50;
	img->width = (img->map->long_line ) * 50;
	img->map->y = img->map->y_player;
	img->map->x = img->map->x_player;
	//img->map->last_ray = 0;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1050, 1050, "Hello");
	img->img = mlx_new_image(img->mlx, 1050, 1050);
	
	return (img);
}

void	ft_images(t_data *img)
{
	img->no.img = mlx_xpm_file_to_image(img->mlx, img->map->no_path,
		&img->no.w, &img->no.h);
	img->ea.img = mlx_xpm_file_to_image(img->mlx, img->map->ea_path,
		&img->ea.w, &img->ea.h);
	img->we.img = mlx_xpm_file_to_image(img->mlx, img->map->we_path,
		&img->we.w, &img->we.h);
	img->so.img = mlx_xpm_file_to_image(img->mlx, img->map->so_path,
		&img->so.w, &img->so.h);
	if (!img->no.img || !img->ea.img || !img->we.img || ! img->so.img)
		exit_error("ERROR : MLX");
	// img->wall = mlx_xpm_file_to_image(img->mlx, "./images/wall.xpm",
	// 	&img->width, &img->height);
	// img->player = mlx_xpm_file_to_image(img->mlx, "./images/player.xpm",
	// 	&img->width, &img->height);
	// img->shadow = mlx_xpm_file_to_image(img->mlx, "./images/background.xpm",
	// 	&img->width, &img->height);
}

void	raycasting(t_data *img)
{
	img = init_func(img);
	ft_images(img);
	img->height = (img->map->len - 1) * 50;
	img->width = (img->map->long_line) * 50;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	draw_world(img);
	cast_rays(img);
	destroy_window(img);
	mlx_hook(img->win, 2, 0L, move_player, img);
	mlx_loop(img->mlx);
}
