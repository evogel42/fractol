/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_tabs_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:42:38 by evogel            #+#    #+#             */
/*   Updated: 2019/05/20 14:33:28 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_init(t_functions *fun)
{
	fun->fractal[K1_KEY] = &mandelbrot;
	fun->fset[0][K1_KEY] = &mandelbrot_init;
	fun->fractal[K2_KEY] = &mandel4;
	fun->fset[0][K2_KEY] = &mandel4_init;
	fun->fractal[K3_KEY] = &mandelverse;
	fun->fset[0][K3_KEY] = &mandelverse_init;
	fun->fractal[K4_KEY] = &julia;
	fun->fset[0][K4_KEY] = &julia_init;
	fun->fset[1][K4_KEY] = &julia_presets;
	fun->fractal[K5_KEY] = &julia6;
	fun->fset[0][K5_KEY] = &julia6_init;
	fun->fset[1][K5_KEY] = &julia6_presets;
	fun->fractal[K6_KEY] = &julia_sin;
	fun->fset[0][K6_KEY] = &julsin_init;
	fun->fset[1][K6_KEY] = &julsin_presets;
	fun->fractal[K7_KEY] = &zubieta;
	fun->fset[0][K7_KEY] = &zubieta_init;
	fun->fset[1][K7_KEY] = &zubieta_presets;
	fun->fractal[K8_KEY] = &thorn;
	fun->fset[0][K8_KEY] = &thorn_init;
	fun->fset[1][K8_KEY] = &thorn_presets;
	fun->fset[0][K9_KEY] = &buddhabrot_init;
}

static void	colorf_init(t_functions *fun)
{
	fun->key[NK0_KEY] = &palette0;
	fun->key[NK1_KEY] = &palette1;
	fun->key[NK2_KEY] = &palette2;
	fun->key[NK3_KEY] = &palette3;
	fun->key[NK4_KEY] = &palette4;
	fun->key[NK5_KEY] = &palette5;
	fun->key[NK6_KEY] = &palette6;
	fun->key[NK7_KEY] = &palette7;
	fun->key[NK8_KEY] = &palette8;
	fun->key[NK9_KEY] = &palette9;
	fun->key[NKPL_KEY] = &shift_range;
	fun->key[NKMN_KEY] = &shift_range;
	fun->key[NKWC_KEY] = &color_start;
}

static void	other_init(t_functions *fun)
{
	fun->mouse[SCROLLUP_KEY] = &zoom_in;
	fun->mouse[SCROLLDOWN_KEY] = &zoom_out;
	fun->mouse[BUT1_KEY] = &center_click;
	fun->key[K1_KEY] = &change_type;
	fun->key[K2_KEY] = &change_type;
	fun->key[K3_KEY] = &change_type;
	fun->key[K4_KEY] = &change_type;
	fun->key[K5_KEY] = &change_type;
	fun->key[K6_KEY] = &change_type;
	fun->key[K7_KEY] = &change_type;
	fun->key[K8_KEY] = &change_type;
	fun->key[K9_KEY] = &change_type;
	fun->key[PUP_KEY] = &change_res;
	fun->key[PDOWN_KEY] = &change_res;
	fun->key[I_KEY] = &disp_info;
	fun->key[F15_KEY] = &write_ppm;
}

void		fun_tables_init(t_functions *fun, int type)
{
	ft_bzero((void *)fun, sizeof(t_functions));
	fract_init(fun);
	colorf_init(fun);
	other_init(fun);
	fun->key[UP_KEY] = &pan_image;
	fun->key[DOWN_KEY] = &pan_image;
	fun->key[LEFT_KEY] = &pan_image;
	fun->key[RIGHT_KEY] = &pan_image;
	fun->key[CM_KEY] = &change_iter;
	fun->key[PT_KEY] = &change_iter;
	fun->key[PL_KEY] = &change_escape;
	fun->key[MN_KEY] = &change_escape;
	fun->key[SP_KEY] = &reset;
	if (type > K3_KEY && type != K9_KEY)
	{
		fun->key[TAB_KEY] = &presets;
		fun->mouse[BUT3_KEY] = &julia_mode;
		fun->key[W_KEY] = &julia_c_modif;
		fun->key[A_KEY] = &julia_c_modif;
		fun->key[S_KEY] = &julia_c_modif;
		fun->key[D_KEY] = &julia_c_modif;
	}
}
