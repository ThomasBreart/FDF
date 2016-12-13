/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 17:09:27 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/11 16:10:09 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Les cste doivent etre entre 0.5 et 1
*/

void	proj_parallel(t_coord *first)
{
	float		cste;

	cste = 0.5;
	while (first != NULL)
	{
		first->print_x = first->x + (cste * first->z);
		first->print_y = first->y + (cste / 2) * first->z;
		first = first->next;
	}
}

void	isometric_proj(t_coord *first)
{
	float	cste1;
	float	cste2;

	cste1 = 1;
	cste2 = 1;
	while (first != NULL)
	{
		first->print_x = (cste1 * first->x) - (cste2 * first->y);
		first->print_y = first->z + ((cste1 / 2) * first->x) +
													((cste2 / 2) * first->y);
		first = first->next;
	}
}
