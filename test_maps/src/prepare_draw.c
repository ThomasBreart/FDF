/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 18:27:28 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/05 23:23:16 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_list(t_coord *first)
{
	while (first != NULL)
	{
		first->print_x = 0;
		first->print_y = 0;
		first = first->next;
	}
}

void	prepare_draw(t_env *e)
{
	int		endian;

	mlx_clear_window(e->mlx, e->win);
	if (e->check_img != 0)
		mlx_destroy_image(e->mlx, e->img_ptr);
	else
		e->check_img = 1;
	e->img_ptr = mlx_new_image(e->mlx, 1200, 1200);
	e->data = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sizeline, &endian);
	reset_list(e->first);
	if (e->change_proj == 0)
		isometric_proj(e->first);
	else
		proj_parallel(e->first);
}
