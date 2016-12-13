/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 12:53:22 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/18 16:36:25 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_env *e, int x, int y, t_coord *tmp)
{
	unsigned int	int_color;

	if (e->b_color == 1)
		int_color = mlx_get_color_value(e->mlx, tmp->color);
	else
		int_color = mlx_get_color_value(e->mlx, 0xFFFFFF);
	if (x > 0 && x < (e->sizeline / 4) && y > 0 && y < (e->sizeline / 4))
		memcpy(e->data + (y * e->sizeline) + ((e->bpp / 8) * x), &int_color, 3);
}

void	draw_line(t_coord *tmp, t_env *e)
{
	e->tmp_color = 0xFFFFFF;
	draw_line_x(tmp, e);
	draw_line_y(tmp, e);
}
