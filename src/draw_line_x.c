/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 16:21:39 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/18 19:13:57 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_equal_x(t_env *e, t_svg *y, t_coord *tmp, t_coord *tmpcolor)
{
	y->svg1 = tmp->print_y;
	y->svg2 = tmp->prev->print_y;
	while (y->svg1 != y->svg2)
	{
		img_pixel_put(e, y->x_or_y, y->svg2, tmpcolor);
		if (y->svg1 > y->svg2)
			y->svg2++;
		if (y->svg1 < y->svg2)
			y->svg2--;
	}
}

void	draw_up_x(t_env *e, t_svg *y, t_coord *tmp, t_coord *tmpcolor)
{
	while (tmp->print_x < tmp->prev->print_x && y->x_or_y <= tmp->prev->print_x)
	{
		y->svg1 = tmp->print_y + ((tmp->print_y - tmp->prev->print_y)
		* (y->x_or_y - tmp->print_x) / (tmp->print_x - tmp->prev->print_x));
		if (e->dotted == 0 || (e->dotted == 1 && tmp->z == tmp->prev->z))
			img_pixel_put(e, y->x_or_y, y->svg1, tmpcolor);
		else
		{
			if (y->svg1 != y->svg2)
				img_pixel_put(e, y->x_or_y, y->svg1, tmpcolor);
		}
		if (e->dotted == 0 || (e->dotted == 1 && tmp->z == tmp->prev->z))
		{
			while (y->svg1 != y->svg2)
			{
				img_pixel_put(e, y->x_or_y, y->svg2, tmpcolor);
				if (y->svg1 > y->svg2)
					y->svg2++;
				if (y->svg1 < y->svg2)
					y->svg2--;
			}
		}
		y->svg2 = y->svg1;
		y->x_or_y++;
	}
}

void	draw_down_x(t_env *e, t_svg *y, t_coord *tmp, t_coord *tmpcolor)
{
	while (tmp->print_x > tmp->prev->print_x && y->x_or_y >= tmp->prev->print_x)
	{
		y->svg1 = tmp->print_y + ((tmp->print_y - tmp->prev->print_y)
		* (y->x_or_y - tmp->print_x) / (tmp->print_x - tmp->prev->print_x));
		if (e->dotted == 0 || (e->dotted == 1 && tmp->z == tmp->prev->z))
			img_pixel_put(e, y->x_or_y, y->svg1, tmpcolor);
		else
		{
			if (y->svg1 != y->svg2)
				img_pixel_put(e, y->x_or_y, y->svg1, tmpcolor);
		}
		if (e->dotted == 0 || (e->dotted == 1 && tmp->z == tmp->prev->z))
		{
			while (y->svg1 != y->svg2)
			{
				img_pixel_put(e, y->x_or_y, y->svg2, tmpcolor);
				if (y->svg1 > y->svg2)
					y->svg2++;
				if (y->svg1 < y->svg2)
					y->svg2--;
			}
		}
		y->svg2 = y->svg1;
		y->x_or_y--;
	}
}

void	draw_line_x(t_coord *tmp, t_env *e)
{
	t_svg		y;
	t_coord		*tmpcolor;

	if (tmp->z <= tmp->prev->z)
		tmpcolor = tmp;
	else
		tmpcolor = tmp->prev;
	y.x_or_y = tmp->print_x;
	y.svg2 = tmp->print_y;
	if (tmp->y == tmp->prev->y)
	{
		if (y.x_or_y == (int)tmp->prev->print_x)
			draw_equal_x(e, &y, tmp, tmpcolor);
		else if (tmp->print_x < tmp->prev->print_x)
			draw_up_x(e, &y, tmp, tmpcolor);
		else if (tmp->print_x > tmp->prev->print_x)
			draw_down_x(e, &y, tmp, tmpcolor);
	}
}
