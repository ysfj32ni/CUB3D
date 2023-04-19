/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:54:41 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/13 15:31:13 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int check_edges(t_data *img,int x , int y)
{
	if(img->map->map[(int)(y + 0.5)][x] == '1' || img->map->map[(int)(y - 0.5)][x] == '1'|| img->map->map[y][(int)(x + 0.5)] == '1' || img->map->map[y][(int) (x - 0.5)] == '1')
		return 1;
	return 0;
}
void	move_player_w(t_data *img)
{
	float y = img->map->y ;
	float x = img->map->x ;
	
			img->map->y -= sin((img->map->angle - (M_PI / 6) )  ) / 5  ;
			img->map->x += cos((img->map->angle - (M_PI / 6) ) ) / 5 ;
		
	printf("y = %f \n" , img->map->y);
	if (img->map->map[(int)img->map->y][(int)img->map->x ] == '1' )
	{
		img->map->y = y ;
		img->map->x = x ;
	}
}

void	move_player_s(t_data *img)
{
	float y = img->map->y;
	float x = img->map->x;
	img->map->y += sin(img->map->angle - (M_PI / 6) ) / 5  ;
	img->map->x -= cos(img->map->angle - (M_PI / 6) ) / 5 ;
	
	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1')
	{
		img->map->y = y;
		img->map->x = x;
	}
}

void	move_player_a(t_data *img)
{
	float y = img->map->y;
	float x = img->map->x;

	img->map->y += sin(img->map->angle - ((M_PI / 2) + (M_PI / 6) )) / 5  ;
	img->map->x -= cos(img->map->angle - ((M_PI / 2) + (M_PI / 6)))  / 5 ;

	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1' )
	{
		img->map->y = y ;
		img->map->x = x ;
	}

}

void	move_player_d(t_data *img)
{
	float y = img->map->y;
	float x = img->map->x;

	img->map->y -= sin(img->map->angle - ((M_PI / 2) + (M_PI / 6) )) / 5  ;
	img->map->x += cos(img->map->angle - ((M_PI / 2) + (M_PI / 6)))  / 5 ;

	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1')
	{
		img->map->y = y;
		img->map->x = x;
	}

}

void	turn_right(t_data *img)
{
	img->map->angle -= 0.1;
	if (img->map->angle < 0)
		img->map->angle += (2 * M_PI);
}

void	turn_left(t_data *img)
{
	img->map->angle += 0.1;
	if (img->map->angle > (2 * M_PI))
		img->map->angle -= (2 * M_PI);
	
}
