/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:57:37 by evogel            #+#    #+#             */
/*   Updated: 2019/04/10 14:43:14 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		maths_init(t_math *math, int type)
{
	if (type == 0)
		mandelbrot_init(math);
	else if (type == 1)
		julia_init(math);
	else if (type == 2)
		thorn_init(math);
	else if (type == 3)
		julsin_init(math);
	else if (type == 4)
		zubieta_init(math);
	else if (type == 5)
		mandel4_init(math);
	else if (type == 6)
		julia6_init(math);
	else if (type == 7)
		mandelverse_init(math);
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
