/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:32:52 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/11 20:34:22 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	t_coord	*first;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fdf map.txt\n");
		exit(0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror(av[1]);
		exit(0);
	}
	first = parse(fd);
	display(first);
	return (0);
}
