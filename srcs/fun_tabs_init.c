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
	fun->fractal[XK_1] = &mandelbrot;
	fun->fset[0][XK_1] = &mandelbrot_init;
	fun->fractal[XK_2] = &mandel4;
	fun->fset[0][XK_2] = &mandel4_init;
	fun->fractal[XK_3] = &mandelverse;
	fun->fset[0][XK_3] = &mandelverse_init;
	fun->fractal[XK_4] = &julia;
	fun->fset[0][XK_4] = &julia_init;
	fun->fset[1][XK_4] = &julia_presets;
	fun->fractal[XK_5] = &julia6;
	fun->fset[0][XK_5] = &julia6_init;
	fun->fset[1][XK_5] = &julia6_presets;
	fun->fractal[XK_6] = &julia_sin;
	fun->fset[0][XK_6] = &julsin_init;
	fun->fset[1][XK_6] = &julsin_presets;
	fun->fractal[XK_7] = &zubieta;
	fun->fset[0][XK_7] = &zubieta_init;
	fun->fset[1][XK_7] = &zubieta_presets;
	fun->fractal[XK_8] = &thorn;
	fun->fset[0][XK_8] = &thorn_init;
	fun->fset[1][XK_8] = &thorn_presets;
	fun->fset[0][XK_9] = &buddhabrot_init;
}

static void	colorf_init(t_functions *fun)
{
	fun->key[KP_0] = &palette0;
	fun->key[KP_1] = &palette1;
	fun->key[KP_2] = &palette2;
	fun->key[KP_3] = &palette3;
	fun->key[KP_4] = &palette4;
	fun->key[KP_5] = &palette5;
	fun->key[KP_6] = &palette6;
	fun->key[KP_7] = &palette7;
	fun->key[KP_8] = &palette8;
	fun->key[KP_9] = &palette9;
	fun->key[XK_KP_Add] = &shift_range;
	fun->key[XK_KP_Subtract] = &shift_range;
	fun->key[XK_KP_Multiply] = &color_start;
}

static void	other_init(t_functions *fun)
{
	fun->mouse[Button4] = &zoom_in;
	fun->mouse[Button5] = &zoom_out;
	fun->mouse[Button1] = &center_click;
	fun->key[XK_1] = &change_type;
	fun->key[XK_2] = &change_type;
	fun->key[XK_3] = &change_type;
	fun->key[XK_4] = &change_type;
	fun->key[XK_5] = &change_type;
	fun->key[XK_6] = &change_type;
	fun->key[XK_7] = &change_type;
	fun->key[XK_8] = &change_type;
	fun->key[XK_9] = &change_type;
	fun->key[XK_Page_Up] = &change_res;
	fun->key[XK_Page_Down] = &change_res;
	fun->key[XK_i] = &disp_info;
	fun->key[XK_F15] = &write_ppm;
}

void		fun_tables_init(t_functions *fun, int type)
{
	ft_bzero((void *)fun, sizeof(t_functions));
	fract_init(fun);
	colorf_init(fun);
	other_init(fun);
	fun->key[XK_Up] = &pan_image;
	fun->key[XK_Down] = &pan_image;
	fun->key[XK_Left] = &pan_image;
	fun->key[XK_Right] = &pan_image;
	fun->key[XK_bracketleft] = &change_iter;
	fun->key[XK_bracketright] = &change_iter;
	fun->key[XK_equal] = &change_escape;
	fun->key[XK_minus] = &change_escape;
	fun->key[XK_space] = &reset;
	if (type > XK_3 && type != XK_9)
	{
		fun->key[XK_Tab] = &presets;
		fun->mouse[Button3] = &julia_mode;
		fun->key[XK_w] = &julia_c_modif;
		fun->key[XK_a] = &julia_c_modif;
		fun->key[XK_s] = &julia_c_modif;
		fun->key[XK_d] = &julia_c_modif;
	}
}
