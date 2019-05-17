/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:00:42 by evogel            #+#    #+#             */
/*   Updated: 2019/05/17 16:06:02 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	x2cx(int x, t_fractal *f)
{
	double cx;

	cx = x * (f->math.plot[1] - f->math.plot[0]) / f->win_x + f->math.plot[0];
	return (cx);
}

double	y2cy(int y, t_fractal *f)
{
	double cy;

	cy = y * (f->math.plot[3] - f->math.plot[2]) / f->win_y + f->math.plot[2];
	return (cy);
}

int		cx2x(double cx, t_fractal *f)
{
	int x;

	x = f->win_x * cx / (f->math.plot[1] - f->math.plot[0]) + f->win_x * 0.5;
	return (x);
}

int		cy2y(double cy, t_fractal *f)
{
	int y;

	y = f->win_y * cy / (f->math.plot[3] - f->math.plot[2]) + f->win_y * 0.5;
	return (y);
}

void	calc_zoom(t_fractal *f)
{
	static double ori = 0;

	if (ori == 0)
		ori = f->math.plot[1] - f->math.plot[0];
	f->math.zoom = ori / (f->math.plot[1] - f->math.plot[0]);
}
