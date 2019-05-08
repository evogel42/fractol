/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_funs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:46:50 by evogel            #+#    #+#             */
/*   Updated: 2019/04/26 13:31:26 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pan_image(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	if (key == LEFT_KEY)
	{
		f->math.plot[0] -= 0.05 * (f->math.plot[1] - f->math.plot[0]);
		f->math.plot[1] -= 0.05 * (f->math.plot[1] - f->math.plot[0]);
	}
	else if (key == RIGHT_KEY)
	{
		f->math.plot[0] += 0.05 * (f->math.plot[1] - f->math.plot[0]);
		f->math.plot[1] += 0.05 * (f->math.plot[1] - f->math.plot[0]);
	}
	else if (key == DOWN_KEY)
	{
		f->math.plot[2] -= 0.05 * (f->math.plot[3] - f->math.plot[2]);
		f->math.plot[3] -= 0.05 * (f->math.plot[3] - f->math.plot[2]);
	}
	else if (key == UP_KEY)
	{
		f->math.plot[2] += 0.05 * (f->math.plot[3] - f->math.plot[2]);
		f->math.plot[3] += 0.05 * (f->math.plot[3] - f->math.plot[2]);
	}
	make_image(f);
}

void	change_iter(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	if (key == PT_KEY)
		f->math.iter += f->color.range / f->color.size;
	else if (key == CM_KEY)
		f->math.iter -= f->color.range / f->color.size;
	make_image(f);
}

void	change_escape(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	if (key == PL_KEY)
		f->math.escape *= 2;
	else if (key == MN_KEY)
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
