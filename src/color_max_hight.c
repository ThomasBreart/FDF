/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_max_hight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 01:20:10 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/18 19:12:20 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	attribute_color(t_coord *tmp, int z)
{
	int		tmpz;

	while (tmp != NULL)
	{
		tmpz = tmp->z * (-1);
		if (tmpz < 0)
			tmp->color = 0x0000CC;
		else if (tmpz <= (z / 4))
			tmp->color = 0x663333;
		else if (tmpz > (z / 4) && tmpz <= (z / 2))
			tmp->color = 0x339900;
		else if (tmpz > (z / 2) && tmpz <= (z - (z / 4)))
			tmp->color = 0xCC9900;
		else
			tmp->color = 0xFFFF99;
		tmp = tmp->next;
	}
}

void	color_max_hight(t_env *e)
{
	t_coord	*tmp;
	int		z;

	z = e->first->z;
	tmp = e->first->next;
	if (e->b_color != 0)
	{
		e->b_color = 0;
		return ;
	}
	else
	{
		e->b_color = 1;
		while (tmp != NULL)
		{
			if (tmp->z <= z)
				z = tmp->z;
			tmp = tmp->next;
		}
		tmp = e->first;
		attribute_color(e->first, (z * (-1)));
	}
}
