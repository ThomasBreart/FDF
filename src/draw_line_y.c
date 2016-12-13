/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 16:14:40 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/18 19:16:12 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*find_the_good(t_coord *tmp, t_coord *tmp2)
{
	if (tmp->z <= tmp2->z)
		return (tmp);
	return (tmp2);
}

void		draw_equal_y(t_env *e, t_svg *x, t_coord *tmp, t_coord *tmp2)
{
	x->svg1 = tmp->print_x;
	x->svg2 = tmp2->print_x;
	while (x->svg1 != x->svg2)
	{
		img_pixel_put(e, x->svg2, x->x_or_y, find_the_good(tmp, tmp2));
		if (x->svg1 > x->svg2)
			x->svg2++;
		if (x->svg1 < x->svg2)
			x->svg2--;
	}
}

void		draw_up_y(t_env *e, t_svg *x, t_coord *tmp, t_coord *tmp2)
{
	while (tmp->print_y < tmp2->print_y && x->x_or_y <= tmp2->print_y)
	{
		x->svg1 = tmp->print_x + ((tmp->print_x - tmp2->print_x)
		* (x->x_or_y - tmp->print_y) / (tmp->print_y - tmp2->print_y));
		if (e->dotted == 0 || (e->dotted == 1 && tmp->z == tmp2->z))
			img_pixel_put(e, x->svg1, x->x_or_y, find_the_good(tmp, tmp2));
		else
		{
			if (x->svg1 != x->svg2)
				img_pixel_put(e, x->svg1, x->x_or_y, find_the_good(tmp, tmp2));
		}
		if ((e->dotted == 0 || (e->dotted == 1 && tmp->z == tmp2->z)))
		{
			while (x->svg1 != x->svg2)
			{
				img_pixel_put(e, x->svg2, x->x_or_y, find_the_good(tmp, tmp2));
				if (x->svg1 > x->svg2)
					x->svg2++;
				if (x->svg1 < x->svg2)
					x->svg2--;
			}
		}
		x->svg2 = x->svg1;
		x->x_or_y++;
	}
}

void		draw_down_y(t_env *e, t_svg *x, t_coord *tmp, t_coord *tmp2)
{
	while (tmp->print_y > tmp2->print_y && x->x_or_y >= tmp2->print_y)
	{
		x->svg1 = tmp->print_x + ((tmp->print_x - tmp2->print_x)
		* (x->x_or_y - tmp->print_y) / (tmp->print_y - tmp2->print_y));
		if (e->dotted == 0 || (e->dotted == 1 && tmp->z == tmp2->z))
			img_pixel_put(e, x->svg1, x->x_or_y, find_the_good(tmp, tmp2));
		else
		{
			if (x->svg1 != x->svg2)
				img_pixel_put(e, x->svg1, x->x_or_y, find_the_good(tmp, tmp2));
		}
		if (e->dotted == 0 || (e->dotted == 1 && tmp->z == tmp2->z))
		{
			while (x->svg1 != x->svg2)
			{
				img_pixel_put(e, x->svg2, x->x_or_y, find_the_good(tmp, tmp2));
				if (x->svg1 > x->svg2)
					x->svg2++;
				if (x->svg1 < x->svg2)
					x->svg2--;
			}
		}
		x->svg2 = x->svg1;
		x->x_or_y--;
	}
}

void		draw_line_y(t_coord *tmp, t_env *e)
{
	t_coord *tmp2;
	t_svg	x;

	x.svg2 = tmp->print_x;
	if (tmp->y > 0)
	{
		x.x_or_y = tmp->print_y;
		tmp2 = tmp->prev;
		while (tmp2->x != tmp->x && tmp2->prev != NULL)
			tmp2 = tmp2->prev;
		if ((tmp2->prev == NULL && tmp->x != 0) || (tmp->y != tmp2->y + 1))
			return ;
		if ((int)tmp->print_y == (int)tmp2->print_y)
			draw_equal_y(e, &x, tmp, tmp2);
		if (tmp->print_y < tmp2->print_y && x.x_or_y <= tmp2->print_y)
			draw_up_y(e, &x, tmp, tmp2);
		if (tmp->print_y > tmp2->print_y && x.x_or_y >= tmp2->print_y)
			draw_down_y(e, &x, tmp, tmp2);
	}
}
