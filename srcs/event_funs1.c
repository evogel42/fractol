/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_funs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:46:50 by evogel            #+#    #+#             */
/*   Updated: 2019/05/20 14:05:21 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pan_image(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	if (key == XK_Left)
	{
		f->math.plot[0] -= 0.05 * (f->math.plot[1] - f->math.plot[0]);
		f->math.plot[1] -= 0.05 * (f->math.plot[1] - f->math.plot[0]);
	}
	else if (key == XK_Right)
	{
		f->math.plot[0] += 0.05 * (f->math.plot[1] - f->math.plot[0]);
		f->math.plot[1] += 0.05 * (f->math.plot[1] - f->math.plot[0]);
	}
	else if (key == XK_Up)
	{
		f->math.plot[2] -= 0.05 * (f->math.plot[3] - f->math.plot[2]);
		f->math.plot[3] -= 0.05 * (f->math.plot[3] - f->math.plot[2]);
	}
	else if (key == XK_Down)
	{
		f->math.plot[2] += 0.05 * (f->math.plot[3] - f->math.plot[2]);
		f->math.plot[3] += 0.05 * (f->math.plot[3] - f->math.plot[2]);
	}
	make_image(f);
}

void	change_iter(int key, void *param)
{
	t_fractal	*f;
	int			add;

	f = (t_fractal *)param;
	if ((add = f->color.range / f->color.size) == 0)
		add = 1;
	if (key == XK_bracketright)
		f->math.iter += add;
	else if (key == XK_bracketleft)
		f->math.iter -= add;
	if (f->math.iter < 0)
		f->math.iter = 0;
	make_image(f);
}

void	change_escape(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	if (key == XK_equal)
		f->math.escape *= 2;
	else if (key == XK_minus)
		f->math.escape *= 0.5;
	if (f->math.escape == 0)
		f->math.escape = 1;
	make_image(f);
}

void	presets(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	(void)key;
	if (f->fun.fset[1][f->type])
	{
		f->fun.fset[1][f->type](&f->math);
		make_image(f);
	}
}
