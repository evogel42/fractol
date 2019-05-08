/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:57:37 by evogel            #+#    #+#             */
/*   Updated: 2019/04/26 13:40:16 by evogel           ###   ########.fr       */
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
	f->fun.fset[0][f->type](&f->math);
	f->color.range = MAX_ITER * 0.5;
	f->color.start = 0;
}

void		window_init(t_mlx *mlx)
{
	int	tmp;

	if (!(mlx->mlx_ptr = mlx_init())
			|| !(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y,
					"fractol"))
			|| !(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y))
			|| !(mlx->data = (int*)mlx_get_data_addr(mlx->img_ptr,
					&tmp, &tmp, &tmp)))
		exit(-1);
}
