/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 16:31:28 by tbreart           #+#    #+#             */
/*   Updated: 2015/05/18 16:20:44 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_coord	t_coord;
struct				s_coord
{
	int				x;
	int				y;
	int				z;
	float			print_x;
	float			print_y;
	int				color;
	struct s_coord	*prev;
	struct s_coord	*next;
};

typedef struct s_svg	t_svg;
struct				s_svg
{
	int				svg1;
	int				svg2;
	int				x_or_y;
};

typedef struct s_env	t_env;
struct				s_env
{
	t_coord			*first;
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*data;
	int				sizeline;
	int				bpp;
	int				button_interval_x;
	int				button_interval_y;
//	int				color_max;
	int				check_max;
	int				change_proj;
	int				ecart;
	int				b_color;
	int				boost_interval;
	int				boost_svg;
	int				check_img;
	int				dotted;
	int				tmp_color;
};

t_coord				*create_elem(int x, int y, int z);
t_coord				*parse(int fd);
void				display(t_coord *first);
void				proj_parallel(t_coord *first);
void				isometric_proj(t_coord *first);
void				draw_line(t_coord *tmp, t_env *e);
int					key_hook(int keycode, t_env *e);
void				draw(t_env *e);
int					expose_hook(t_env *e);
void				prepare_draw(t_env *e);
void				color_max_hight(t_env *e);
void				img_pixel_put(t_env *e, int x, int y, t_coord *tmp);
void				draw_line_x(t_coord *tmp, t_env *e);
void				draw_line_y(t_coord *tmp, t_env *e);
void				check_color_max(t_env *e, t_coord *tmp, t_coord *tmp2);
#endif
