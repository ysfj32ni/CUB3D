/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:11:15 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/08 15:30:52 by yjaadoun         ###   ########.fr       */
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
	t_alloc_lst	**alloc_list;
}	t_map;

// ----------> PARSING <---------- //
t_bool	check_path(char *av);
t_bool	check_border(char *line);
t_bool	check_elements(char **map);
void	map_elements(t_map *map);
void	print_2d(char **str);
void	exit_error(char	*str);
char	**get_map(char *av);
int		skip_spaces_begin(char *str);
int	doble_arr_len(char **str);
void	check_colors(char *str);

#endif