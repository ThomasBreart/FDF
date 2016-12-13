/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 01:21:28 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/18 19:12:53 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*create_elem(int x, int y, int z)
{
	t_coord	*newelem;

	newelem = (t_coord *)malloc(sizeof(t_coord));
	if (newelem == NULL)
		return (NULL);
	newelem->x = x;
	newelem->y = y;
	newelem->z = -z;
	newelem->prev = NULL;
	newelem->next = NULL;
	newelem->color = 0xFFFFFF;
	return (newelem);
}
