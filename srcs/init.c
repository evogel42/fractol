/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:57:37 by evogel            #+#    #+#             */
/*   Updated: 2019/04/17 16:49:04 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color_init(t_fractal *f)
{
	f->color.pal = NULL;
	palette0(0, (void*)f);
	f->color.range = MAX_ITER;
	f->color.start = 0;
}

void		maths_init(t_fractal *f)
{
	if (f->type == 0)
		mandelbrot_init(&f->math);
	else if (f->type == 1)
		julia_init(&f->math);
	else if (f->type == 2)
		thorn_init(&f->math);
	else if (f->type == 3)
		julsin_init(&f->math);
	else if (f->type == 4)
		zubieta_init(&f->math);
	else if (f->type == 5)
		mandel4_init(&f->math);
	else if (f->type == 6)
		julia6_init(&f->math);
	else if (f->type == 7)
		mandelverse_init(&f->math);
	f->color.range = MAX_ITER;
}

void		window_init(t_mlx *mlx)
{
	int	tmp;

	if (!(mlx->mlx_ptr = mlx_init())
			|| !(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y,
					"PRETTY MATHS"))
			|| !(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y))
			|| !(mlx->data = (int*)mlx_get_data_addr(mlx->img_ptr,
					&tmp, &tmp, &tmp)))
		exit(-1);
}
