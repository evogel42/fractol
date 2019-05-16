/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:13:13 by evogel            #+#    #+#             */
/*   Updated: 2019/05/16 13:31:01 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		do_close1(int keycode, void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(f->mlx.mlx_ptr, f->mlx.win_ptr);
		exit(0);
	}
	return (0);
}

int		do_close2(void *param)
{
	t_fractal *f;

	f = (t_fractal *)param;
	mlx_destroy_window(f->mlx.mlx_ptr, f->mlx.win_ptr);
	exit(0);
}

int		do_key(int keycode, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (f->fun.key[keycode])
		f->fun.key[keycode](keycode, (void *)f);
	return (0);
}

int		do_mouse(int button, int x, int y, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (f->fun.mouse[button])
		f->fun.mouse[button](x, y, (void *)f);
	return (0);
}

int		do_move(int x, int y, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (f->type >= 1 && f->math.mode == 1)
	{
		f->math.c[0] = x * ((f->math.plot[1] - f->math.plot[0]) / f->win_x)
			+ f->math.plot[0];
		f->math.c[1] = y * ((f->math.plot[3] - f->math.plot[2]) / f->win_y)
			+ f->math.plot[2];
		make_image(f);
	}
	return (0);
}
