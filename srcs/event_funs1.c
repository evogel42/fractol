/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_funs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:46:50 by evogel            #+#    #+#             */
/*   Updated: 2019/04/09 19:15:02 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pan_image(int key, void *param)
{
	t_fractal *f;

	f = param;
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
}

void	change_iter(int key, void *param)
{
	t_fractal *f;

	f = param;
	if (key == PT_KEY)
		f->math.iter += f->color.range;
	else if (key == CM_KEY)
		f->math.iter -= f->color.range;
}

void	change_escape(int key, void *param)
{
	t_fractal *f;

	f = param;
	if (key == PL_KEY)
		f->math.escape *= 2;
	else if (key == MN_KEY)
		f->math.escape *= 0.5;
	if (f->math.escape == 0)
		f->math.escape = 1;
}

void	presets(int key, void *param)
{
	t_fractal *f;

	f = param;
	(void)key;
	if (f->type == 1)
		julia_presets(&f->math);
	else if (f->type == 2)
		thorn_presets(&f->math);
	else if (f->type == 3)
		julsin_presets(&f->math);
	else if (f->type == 4)
		zubieta_presets(&f->math);
	else if (f->type == 6)
		julia6_presets(&f->math);
}
