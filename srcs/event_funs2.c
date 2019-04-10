/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_funs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:46:50 by evogel            #+#    #+#             */
/*   Updated: 2019/04/10 19:47:46 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset(int key, void *param)
{
	t_fractal *f;

	f = param;
	(void)key;
	maths_init(&f->math, f->type);
}

void	zoom_in(int x, int y, void *param)
{
	t_fractal	*f;
	double		x_scale;
	double		y_scale;

	f = param;
	x_scale = x * (f->math.plot[1] - f->math.plot[0]) / WIN_X + f->math.plot[0];
	y_scale = y * (f->math.plot[3] - f->math.plot[2]) / WIN_Y + f->math.plot[2];
	f->math.plot[0] = x_scale + (f->math.plot[0] - x_scale) * 0.9;
	f->math.plot[1] = x_scale + (f->math.plot[1] - x_scale) * 0.9;
	f->math.plot[2] = y_scale + (f->math.plot[2] - y_scale) * 0.9;
	f->math.plot[3] = y_scale + (f->math.plot[3] - y_scale) * 0.9;
}

void	zoom_out(int x, int y, void *param)
{
	t_fractal	*f;
	double		x_scale;
	double		y_scale;

	f = param;
	x_scale = x * (f->math.plot[1] - f->math.plot[0]) / WIN_X + f->math.plot[0];
	y_scale = y * (f->math.plot[3] - f->math.plot[2]) / WIN_Y + f->math.plot[2];
	f->math.plot[0] = x_scale + (f->math.plot[0] - x_scale) * 1.1;
	f->math.plot[1] = x_scale + (f->math.plot[1] - x_scale) * 1.1;
	f->math.plot[2] = y_scale + (f->math.plot[2] - y_scale) * 1.1;
	f->math.plot[3] = y_scale + (f->math.plot[3] - y_scale) * 1.1;
}

void	julia_mode(int x, int y, void *param)
{
	t_fractal *f;

	f = param;
	(void)x;
	(void)y;
	f->math.mode = (f->math.mode == 0 ? 1 : 0);
	if (f->math.mode == 1)
		f->math.iter = MAX_ITER;
}

void	julia_c_modif(int key, void *param)
{
	t_fractal *f;

	f = param;
	if (key == W_KEY)
		f->math.c[1] += 0.001 * (f->math.plot[3] - f->math.plot[2]);
	else if (key == A_KEY)
		f->math.c[0] -= 0.001 * (f->math.plot[1] - f->math.plot[0]);
	else if (key == S_KEY)
		f->math.c[1] -= 0.001 * (f->math.plot[3] - f->math.plot[2]);
	else if (key == D_KEY)
		f->math.c[0] += 0.001 * (f->math.plot[1] - f->math.plot[0]);
}
