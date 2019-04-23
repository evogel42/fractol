/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_tabs_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:42:38 by evogel            #+#    #+#             */
/*   Updated: 2019/04/21 14:25:58 by evogel           ###   ########.fr       */
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

static void	type_init(t_functions *fun)
{
	fun->key[K1_KEY] = &change_type;
	fun->key[K2_KEY] = &change_type;
	fun->key[K3_KEY] = &change_type;
	fun->key[K4_KEY] = &change_type;
	fun->key[K5_KEY] = &change_type;
	fun->key[K6_KEY] = &change_type;
	fun->key[K7_KEY] = &change_type;
	fun->key[K8_KEY] = &change_type;
}

void		fun_tables_init(t_functions *fun, int type)
{
	null_init(fun);
	//zoom
	fun->mouse[SCROLLUP_KEY] = &zoom_in;
	fun->mouse[SCROLLDOWN_KEY] = &zoom_out;
	fun->mouse[BUT1_KEY] = &center_click;
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
	//if julia types -- change mode & c preset
	if (type != 0 && type != 5 && type != 7)
	{
		fun->key[TAB_KEY] = &presets;
		fun->mouse[BUT3_KEY] = &julia_mode;
		fun->key[W_KEY] = &julia_c_modif;
		fun->key[A_KEY] = &julia_c_modif;
		fun->key[S_KEY] = &julia_c_modif;
		fun->key[D_KEY] = &julia_c_modif;
	}
	type_init(fun);
	//change color
	fun->key[NK0_KEY] = &palette0;
	fun->key[NK1_KEY] = &palette1;
	fun->key[NK2_KEY] = &palette2;
	fun->key[NK3_KEY] = &palette3;
//	fun->key[NK4_KEY] = &palette4;
	fun->key[NKPL_KEY] = &shift_range;
	fun->key[NKMN_KEY] = &shift_range;
	fun->key[NKWC_KEY] = &color_start;
	fract_init(fun);
}
