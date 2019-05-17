/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_funs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:46:50 by evogel            #+#    #+#             */
/*   Updated: 2019/05/17 15:38:40 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	(void)key;
	maths_init(f);
	make_image(f);
}

void	zoom_in(int x, int y, void *param)
{
	t_fractal	*f;
	double		cx;
	double		cy;

	f = (t_fractal *)param;
	cx = x2cx(x, f);
	cy = y2cy(y, f);
	f->math.plot[0] = cx + (f->math.plot[0] - cx) * 0.9;
	f->math.plot[1] = cx + (f->math.plot[1] - cx) * 0.9;
	f->math.plot[2] = cy + (f->math.plot[2] - cy) * 0.9;
	f->math.plot[3] = cy + (f->math.plot[3] - cy) * 0.9;
	calc_zoom(f);
	make_image(f);
}

void	zoom_out(int x, int y, void *param)
{
	t_fractal	*f;
	double		cx;
	double		cy;

	f = (t_fractal *)param;
	cx = x2cx(x, f);
	cy = y2cy(y, f);
	f->math.plot[0] = cx + (f->math.plot[0] - cx) * 1.1;
	f->math.plot[1] = cx + (f->math.plot[1] - cx) * 1.1;
	f->math.plot[2] = cy + (f->math.plot[2] - cy) * 1.1;
	f->math.plot[3] = cy + (f->math.plot[3] - cy) * 1.1;
	calc_zoom(f);
	make_image(f);
}

void	julia_mode(int x, int y, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	(void)x;
	(void)y;
	f->math.mode = (f->math.mode == 0 ? 1 : 0);
}

void	julia_c_modif(int key, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	if (key == W_KEY)
		f->math.c[1] += 0.001 * (f->math.plot[3] - f->math.plot[2]);
	else if (key == A_KEY)
		f->math.c[0] -= 0.001 * (f->math.plot[1] - f->math.plot[0]);
	else if (key == S_KEY)
		f->math.c[1] -= 0.001 * (f->math.plot[3] - f->math.plot[2]);
	else if (key == D_KEY)
		f->math.c[0] += 0.001 * (f->math.plot[1] - f->math.plot[0]);
	make_image(f);
}
