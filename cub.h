/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:11:15 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/09 22:19:38 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# define TRUE 1
# define FALSE 0
# define SPACE 32
# define TAB  9

typedef int	t_bool;

typedef struct s_alloc_lst
{
	void				*content;
	struct s_alloc_lst	*next;
}	t_alloc_lst;

typedef struct s_map
{
	char		**line;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_color;
	char		*c_color;
	char		**map;
	int			x_player;
	int			y_player;
	char		start_pos;
	t_alloc_lst	**alloc_list;
}	t_map;

// ----------> PARSING <---------- //
t_bool	check_path(char *av);
t_bool	check_border(t_map *map);
t_bool	check_elements(char **map);
// t_bool	check_errors(t_map *map);
t_bool	is_map_valid(t_map *map);
t_map	*parsing(char *av);
void	map_elements(t_map *map);
void	print_2d(char **str);
void	exit_error(char	*str);
void	check_colors(char *str);
void	initialisation(t_map *map);
void	player_position(t_map *map);
char	**get_map(char *av);
int		skip_spaces_begin(char *str);
int		doble_arr_len(char **str);
#endif