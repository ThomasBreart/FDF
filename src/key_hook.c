/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 00:53:12 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/18 19:11:40 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 53 = esc
** 123 - 126 = touches directionnelles
** 85 = "3" du pad numerique
** 82 = "0" du pad numerique
** 84 = "2" du pad numerique
** 78 = "-" du pad numerique
** 69 = "+" du pad numerique
*/

void	key_hook_2(int keycode, t_env *e)
{
	if (keycode == 69 && e->ecart < 1000)
	{
		e->ecart = e->ecart * 1.5;
		e->boost_interval = e->boost_svg - 1;
		if (e->boost_interval < 1)
			e->boost_interval = 1;
	}
	if (keycode == 84)
	{
		if (e->dotted == 0)
			e->dotted = 1;
		else
			e->dotted = 0;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		e->button_interval_x = e->button_interval_x - (e->boost_interval * 2);
	if (keycode == 124)
		e->button_interval_x = e->button_interval_x + (e->boost_interval * 2);
	if (keycode == 125)
		e->button_interval_y = e->button_interval_y + e->boost_interval;
	if (keycode == 126)
		e->button_interval_y = e->button_interval_y - e->boost_interval;
	if (keycode == 85)
	{
		if (e->change_proj == 0)
			e->change_proj = 1;
		else
			e->change_proj = 0;
	}
	if (keycode == 82)
		color_max_hight(e);
	if (keycode == 78 && e->ecart > 2 && (e->ecart = e->ecart / 1.5))
		e->boost_interval = e->boost_svg + 1;
	key_hook_2(keycode, e);
	expose_hook(e);
	return (0);
}
