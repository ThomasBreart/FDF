/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 13:59:05 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/23 13:38:51 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_nbr(char *alpha_nbr)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	if (alpha_nbr[i] == '-' || alpha_nbr[i] == '+')
	{
		if (alpha_nbr[i] == '-')
			neg = -1;
		i++;
	}
	while (alpha_nbr[i] != '\0')
	{
		while (ft_isdigit(alpha_nbr[i]) == 0 && alpha_nbr[i] != '\0')
			i++;
		nb = nb * 10 + alpha_nbr[i++] - '0';
	}
	return (nb * neg);
}

void		map_non_valide(int x)
{
	if (x > 1000000)
	{
		ft_putstr("map non valide, t'abuses.\n");
		exit (0);
	}
}

void		cut_line(char *s, int y, t_coord **before, t_coord **current)
{
	int		z;
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) != 0 || ((s[i] == '-') && ft_isdigit(s[i + 1])))
		{
			z = ft_atoi(s + i);
			map_non_valide(z);
			*current = create_elem(x++, y, z);
			if (*before != NULL)
				(*before)->next = *current;
			if (*before != NULL)
				(*current)->prev = *before;
			*before = *current;
			while (ft_isnumber(s[i]) != 0)
				i++;
		}
		else
			i++;
	}
	map_non_valide(x);
}

t_coord		*parse(int fd)
{
	int		y;
	char	*line;
	t_coord	*before;
	t_coord	*current;
	int		rd;

	y = 0;
	before = NULL;
	current = NULL;
	while ((rd = get_next_line(fd, &line) > 0))
	{
		cut_line(line, y, &before, &current);
		y++;
		free(line);
		line = NULL;
	}
	if (line != NULL)
		free(line);
	if (rd < 0)
	{
		ft_putendl("error read");
		exit(0);
	}
	map_non_valide(y);
	if (current == NULL)
	{
		ft_putstr("fichier vide\n");
		exit(0);
	}
	while (current->prev != NULL)
		current = current->prev;
	return (current);
}
