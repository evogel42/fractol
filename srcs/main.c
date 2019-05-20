/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:56:41 by evogel            #+#    #+#             */
/*   Updated: 2019/05/20 12:06:47 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_type(char *av)
{
	if (ft_strequ(av, "mandelbrot"))
		return (K1_KEY);
	else if (ft_strequ(av, "mandel4"))
		return (K2_KEY);
	else if (ft_strequ(av, "mandelverse"))
		return (K3_KEY);
	else if (ft_strequ(av, "julia"))
		return (K4_KEY);
	else if (ft_strequ(av, "julia6"))
		return (K5_KEY);
	else if (ft_strequ(av, "julia_sin"))
		return (K6_KEY);
	else if (ft_strequ(av, "zubieta"))
		return (K7_KEY);
	else if (ft_strequ(av, "thorn"))
		return (K8_KEY);
	else if (ft_strequ(av, "buddhabrot"))
		return (K9_KEY);
	else
		return (-1);
}

static int	ft_usage(void)
{
	ft_putstr("usage: ./fractol [type]\n");
	ft_putstr("types: mandelbrot, mandel4, mandelverse, julia6, julia_sin, ");
	ft_putstr("zubieta, thorn, buddhabrot\n");
	return (0);
}

void		events_manager(t_fractal *f)
{
	void *win;

	win = f->mlx.win_ptr;
	mlx_hook(win, KEYRELEASE, KEYRELEASEMASK, do_close1, (void*)f);
	mlx_hook(win, DESTROYNOTIFY, 0, do_close2, (void*)f);
	mlx_hook(win, KEYPRESS, KEYPRESSMASK, do_key, (void*)f);
	mlx_hook(win, BUTTONPRESS, BUTTONPRESSMASK, do_mouse, (void*)f);
	mlx_hook(win, MOTIONNOTIFY, POINTERMOTIONMASK, do_move, (void*)f);
	mlx_loop(f->mlx.mlx_ptr);
}

int			main(int ac, char **av)
{
	t_fractal	f;

	if (ac != 2)
		return (ft_usage());
	if ((f.type = get_type(av[1])) == -1)
		return (ft_usage());
	f.win_y = WIN_Y;
	f.win_x = WIN_X;
	fun_tables_init(&f.fun, f.type);
	maths_init(&f);
	window_init(&f.mlx, f.win_x, f.win_y);
	color_init(&f);
	events_manager(&f);
	return (0);
}
/*
**#include <stdio.h>
**void		end(void)
**{
**	printf("\nIN END\n");
**	while (1);
**}
*/
