/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:37:17 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/03 16:38:46 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac > 1)
	{
		if (!check_path(av[1]))
			exit_error("ERROR : PATH must be *.cub\n");
		map = parsing(av[1]);
	}
	else
		exit_error("ERROR : Enought args [./cub3D map.cub]\n");
}
