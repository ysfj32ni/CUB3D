/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:57:36 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/08 13:21:48 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_bool	check_path(char *av)
{
	int		i;
	char	*test;

	i = 0;
	test = ft_strnstr(av, ".cub", ft_strlen(av));
	if (test && ft_strlen(test) == 4)
		return (TRUE);
	else
		return (FALSE);
}

char	**get_map(char *av)
{
	char	*buf;
	char	*current;
	char	**line;
	int		fd;

	fd = open(av, O_RDWR);
	if (fd < 0)
		exit_error("ERROR : PATH of map\n");
	buf = 0;
	current = get_next_line(fd);
	while (current)
	{
		buf = ft_strjoin(buf, current);
		current = get_next_line(fd);
	}
	line = ft_split(buf, '\n');
	if (!line)
		exit_error("ERROR : Empty file\n");
	return (line);
}
