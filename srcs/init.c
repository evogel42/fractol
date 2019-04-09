/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:57:37 by evogel            #+#    #+#             */
/*   Updated: 2019/04/09 20:26:24 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	null_init(t_functions *fun)
{
	int	i;

	i = 0;
	while (i < KEY_MAX)
		fun->key[i++] = NULL;
	i = 0;
	while (i < MOUSE_MAX)
		fun->mouse[i++] = NULL;
}

static void	fract_init(t_functions *fun)
{
	fun->fractal[0] = &mandelbrot;
	fun->fractal[1] = &julia;
	fun->fractal[2] = &thorn;
	fun->fractal[3] = &julia_sin;
	fun->fractal[4] = &zubieta;
	fun->fractal[5] = &mandel4;
	fun->fractal[6] = &julia6;
	fun->fractal[7] = &mandelverse;
}

void		fun_tables_init(t_functions *fun, int type)
{
	null_init(fun);
	//zoom
	fun->mouse[SCROLLUP_KEY] = &zoom_in;
	fun->mouse[SCROLLDOWN_KEY] = &zoom_out;
	//make screenshot
	fun->key[F15_KEY] = &write_ppm;
	//reset params
	fun->key[SP_KEY] = &reset;
	//pan image
	fun->key[UP_KEY] = &pan_image;
	fun->key[DOWN_KEY] = &pan_image;
	fun->key[LEFT_KEY] = &pan_image;
	fun->key[RIGHT_KEY] = &pan_image;
	//change max iter
	fun->key[CM_KEY] = &change_iter;
	fun->key[PT_KEY] = &change_iter;
	//change escape
	fun->key[PL_KEY] = &change_escape;
	fun->key[MN_KEY] = &change_escape;
	//Depending on type shows interesting values
	if (type != 0 && type != 5 && type != 7)
		fun->key[TAB_KEY] = &presets;
	//if julia types -- change mode & c preset
	if (type >= 1)
	{
		fun->mouse[BUT3_KEY] = &julia_mode;
		fun->key[W_KEY] = &julia_c_modif;
		fun->key[A_KEY] = &julia_c_modif;
		fun->key[S_KEY] = &julia_c_modif;
		fun->key[D_KEY] = &julia_c_modif;
	}
	//change color
	fun->key[K1_KEY] = &color1;
	fract_init(fun);
}

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
