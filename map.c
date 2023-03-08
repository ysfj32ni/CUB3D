/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:22:31 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/08 14:54:16 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// TO DO : check square border if 1
t_bool	check_border(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
			exit_error("ERROR : border map \n");
		i++;
	}
	return (TRUE);
}

t_bool	check_elements(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strchr("01NSEW \t", map[i][j]))
				exit_error("ERROR : wrong element\n");
			else if (ft_strchr("NSEW", map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		exit_error("ERROR : wrong element\n");
	return (TRUE);
}

// TO DO : space between | is_alpha | 
void	check_colors(char *str)
{
	char	**div;
	int		i;

	i = 0;
	div = ft_split(str + 1, ',');
	while (div[i] != NULL)
	{	
		if (ft_atoi(div[i]) < 0 || ft_atoi(div[i]) > 255)
			exit_error("ERROR : invalid color code\n");
		i++;
	}
	if (i != 3)
		exit_error("ERROR : invalid color code N˚\n");
	// print_2d(div);
}
