/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_funs4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:18:10 by evogel            #+#    #+#             */
/*   Updated: 2019/05/12 13:22:06 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	disp_info(int key, void *param)
{
	t_fractal *f;

	(void)key;
	f = (t_fractal *)param;
	f->info = (f->info == 2 ? 0 : f->info + 1);
	make_image(f);
}

void	change_res(int key, void *param)
{
	t_fractal	*f;

	(void)key;
	f = (t_fractal *)param;
	if (key == PUP_KEY && f->win_y + 90 <= 4320)
		f->win_y += 90;
	else if (key == PDOWN_KEY && f->win_y - 90 >= 180)
		f->win_y -= 90;
	f->win_x = (int)(f->win_y * RATIO);
	mlx_destroy_window(f->mlx.mlx_ptr, f->mlx.win_ptr);
	window_init(&f->mlx, f->win_x, f->win_y);
	make_image(f);
	events_manager(f);
}
