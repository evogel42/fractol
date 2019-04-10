/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_funs3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:36:35 by evogel            #+#    #+#             */
/*   Updated: 2019/04/10 19:46:40 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_type(int key, void *param)
{
	t_fractal *f;

	f = param;
	if (key == K1_KEY)
		f->type = 0;
	else if (key == K2_KEY)
		f->type = 1;
	else if (key == K3_KEY)
		f->type = 2;
	else if (key == K4_KEY)
		f->type = 3;
	else if (key == K5_KEY)
		f->type = 4;
	else if (key == K6_KEY)
		f->type = 5;
	else if (key == K7_KEY)
		f->type = 6;
	else if (key == K8_KEY)
		f->type = 7;
	fun_tables_init(&f->fun, f->type);
	maths_init(&f->math, f->type);
}

void	center_click(int x, int y, void *param)
{
	t_fractal	*f;
	double		x_scale;
	double		y_scale;
	double		dx;
	double		dy;

	f = param;
	dx = f->math.plot[1] - f->math.plot[0];
	dy = f->math.plot[3] - f->math.plot[2];
	x_scale = x * dx / WIN_X + f->math.plot[0];
	y_scale = y * dy / WIN_Y + f->math.plot[2];
	f->math.plot[0] = x_scale - dx * 0.5;
	f->math.plot[1] = x_scale + dx * 0.5;
	f->math.plot[2] = y_scale - dy * 0.5;
	f->math.plot[3] = y_scale + dy * 0.5;
}