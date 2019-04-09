/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:56:41 by evogel            #+#    #+#             */
/*   Updated: 2019/04/09 20:23:12 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_type(char *av)
{
	if (ft_strequ(av, "mandelbrot"))
		return (0);
	else if (ft_strequ(av, "julia"))
		return (1);
	else if (ft_strequ(av, "thorn"))
		return (2);
	else if (ft_strequ(av, "julia_sin"))
		return (3);
	else if (ft_strequ(av, "zubieta"))
		return (4);
	else if (ft_strequ(av, "mandel4"))
		return (5);
	else if (ft_strequ(av, "julia6"))
		return (6);
	else if (ft_strequ(av, "mandelverse"))
		return (7);
	else
		return (-1);
}

static int	ft_usage(void)
{
	ft_putstr("usage: ./fractol [type]\n");
	ft_putstr("available types: mandelbrot, julia, thorn, julia_sin, zubieta, mandel4, julia6\n");
	return (0);
}

static void	events_manager(t_fractal *f)
{
	mlx_hook(f->mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, do_close1, (void *)f);
	mlx_hook(f->mlx.win_ptr, DESTROYNOTIFY, 0, do_close2, (void *)f);
	mlx_hook(f->mlx.win_ptr, KEYPRESS, KEYPRESSMASK, do_key, (void *)f);
	mlx_hook(f->mlx.win_ptr, BUTTONPRESS, BUTTONPRESSMASK, do_mouse, (void *)f);
	mlx_hook(f->mlx.win_ptr, MOTIONNOTIFY, POINTERMOTIONMASK, do_move, (void *)f);
	mlx_loop(f->mlx.mlx_ptr);
}

int		main(int ac, char **av)
{
	t_fractal	f;
	
	if (ac != 2)
		return (ft_usage());
	if ((f.type = get_type(av[1])) == -1)
		return (ft_usage());
	fun_tables_init(&f.fun, f.type);
	f.color.pal = NULL;
	color1(0, &f);
	maths_init(&f.math, f.type);
	window_init(&f.mlx);
	make_image(&f);
	events_manager(&f);
	return (0);
}

/* KEY ACTIONS:
 * - arrows move picture
 * - mouse wheel zoom on mouse position
 * - add fractal types
 * - add colors
 * - varying escape value
*/
