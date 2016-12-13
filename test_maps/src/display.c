/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/18 19:13:23 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_env *e)
{
	t_coord	*tmp;

	tmp = e->first;
	while (tmp != NULL)
	{
		tmp->print_x = (tmp->print_x + e->button_interval_x) * e->ecart + 500;
		tmp->print_y = (tmp->print_y + e->button_interval_y) * e->ecart + 500;
		if (tmp != e->first)
			draw_line(tmp, e);
		img_pixel_put(e, tmp->print_x, tmp->print_y, tmp);
		tmp = tmp->next;
	}
}

int		expose_hook(t_env *e)
{
	prepare_draw(e);
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

void	display(t_coord *first)
{
	t_env	e;

	e.first = first;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1200, 1200, "FDF - 42");
	e.button_interval_x = 0;
	e.button_interval_y = 0;
	e.b_color = 0;
	e.check_max = 0;
	e.change_proj = 0;
	e.ecart = 40;
	e.boost_interval = 6;
	e.boost_svg = 6;
	e.check_img = 0;
	e.dotted = 0;
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
