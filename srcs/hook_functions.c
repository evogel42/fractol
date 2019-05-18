/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:13:13 by evogel            #+#    #+#             */
/*   Updated: 2019/05/18 17:58:33 by evogel           ###   ########.fr       */
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
		f->math.c[0] = x2cx(x, f);
		f->math.c[1] = y2cy(y, f);
		make_image(f);
	}
	return (0);
}
