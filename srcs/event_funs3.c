/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_funs3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:36:35 by evogel            #+#    #+#             */
/*   Updated: 2019/05/16 13:34:26 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_type(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	f->type = key;
	fun_tables_init(&f->fun, f->type);
	maths_init(f);
	make_image(f);
}

void	center_click(int x, int y, void *param)
{
	t_fractal	*f;
	double		x_scale;
	double		y_scale;
	double		dx;
	double		dy;

	if (x < 0 || y < 0)
		return ;
	f = (t_fractal *)param;
	dx = f->math.plot[1] - f->math.plot[0];
	dy = f->math.plot[3] - f->math.plot[2];
	x_scale = x * dx / f->win_x + f->math.plot[0];
	y_scale = y * dy / f->win_y + f->math.plot[2];
	f->math.plot[0] = x_scale - dx * 0.5;
	f->math.plot[1] = x_scale + dx * 0.5;
	f->math.plot[2] = y_scale - dy * 0.5;
	f->math.plot[3] = y_scale + dy * 0.5;
	make_image(f);
}

void	shift_range(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	if (key == NKPL_KEY)
		f->color.range += 1 + (int)(f->color.range * 0.01);
	else if (key == NKMN_KEY && f->color.range > 1)
		f->color.range -= 1 + (int)(f->color.range * 0.01);
	make_image(f);
}

void	color_start(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	(void)key;
	f->color.start += 1;
	if (f->color.start == f->color.size)
		f->color.start = 0;
	make_image(f);
}
