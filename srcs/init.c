/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:57:37 by evogel            #+#    #+#             */
/*   Updated: 2019/05/16 13:22:40 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color_init(t_fractal *f)
{
	f->color.pal = NULL;
	f->color.range = MAX_ITER * 0.5;
	f->color.start = 0;
	palette0(0, (void*)f);
}

void		maths_init(t_fractal *f)
{
	if (f->fun.fset[0][f->type])
		f->fun.fset[0][f->type](&f->math);
	f->math.zoom = 0;
	f->color.range = MAX_ITER * 0.5;
	f->color.start = 0;
}

void		window_init(t_mlx *mlx, int win_x, int win_y)
{
	int	tmp;

	if (!(mlx->mlx_ptr = mlx_init())
			|| !(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, win_x, win_y,
					"fractol"))
			|| !(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, win_x, win_y))
			|| !(mlx->data = (int*)mlx_get_data_addr(mlx->img_ptr,
					&tmp, &tmp, &tmp)))
		exit(-1);
}
