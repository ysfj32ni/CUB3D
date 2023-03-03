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

int main (int ac, char **av)
{
	char	*buf;
	int		fd;

	(void)ac;
	buf = ft_strdup("");
	fd = open(av[1], O_RDWR);
	// buf = ;
	while (get_next_line(fd))
	{
		buf = ft_strjoin(buf, get_next_line(fd));
		printf("buf [%s]\n", buf);
	}
	// printf("fd : %i\n", fd);
}