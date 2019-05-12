/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:23:05 by evogel            #+#    #+#             */
/*   Updated: 2019/05/12 10:52:36 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_info_text2(t_fractal *f)
{
	static char	names[8][12] = {"mandelbrot", "mandel4", "mandelverse", "julia",
	"julia6", "julia_sin", "zubieta", "thorn"};
	static int	nums[8] = {K1_KEY, K2_KEY, K3_KEY, K4_KEY, K5_KEY, K6_KEY, K7_KEY, K8_KEY};
	int				i;

	i = 0;
	while (f->type != nums[i] && i < 8)
		++i;
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, WIN_X - 200, 20, 0xFFFFFF, names[i]);
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, WIN_X - 200, 60, 0xFFFFFF, ft_itoa(f->math.iter));
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, WIN_X - 200, 100, 0xFFFFFF, ft_itoa(f->math.escape));
	if (i > 2)
	{
		mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, WIN_X - 200, 140, 0xFFFFFF, ft_flotoa(f->math.c[0], 6));
		mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, WIN_X - 200, 180, 0xFFFFFF, ft_flotoa(f->math.c[1], 6));
	}
}

void	make_info_bg(t_fractal *f)
{
	int			x;
	int			y;

	x = 0;
	while (x < 350)
	{
		y = 0;
		while (y < WIN_Y)
		{
			if (x < 10)
				f->mlx.data[x + y * WIN_X] = f->color.pal[(int)(y * f->color.size / WIN_Y)].i;
			else
				f->mlx.data[x + y * WIN_X] = 0x60000000;
			++y;
		}
		++x;
	}
}

void	make_info_text(t_fractal *f)
{
	int x;
	int	y;

	make_info_bg(f);
	mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.win_ptr, f->mlx.img_ptr, 0, 0);
	x = 20;
	y = 10;
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, y, 0xFFFFFF, "Mouse Controls");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 20), 0xFFFFFF, "--------------------------------");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "Scrollwheel : Zoom in/out");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "Left click  : Center");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "Wheel click : Lock/unlock param");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 60), 0xFFFFFF, "Keyboard Controls");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 20), 0xFFFFFF, "--------------------------------");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "#1-9   : Change fractal");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "Arrows : Pan image");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "WASD   : Increment param");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "< >    : Vary max iterations");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "- +    : Vary escape value");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "Tab    : Example param values");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "I      : Toggle info");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "Space  : Reset");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "F15    : Save screenshot");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 60), 0xFFFFFF, "Numpad Controls");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 20), 0xFFFFFF, "--------------------------------");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "#1-6 : Change color palette");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "- +  : Change color range");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, (y += 30), 0xFFFFFF, "*    : Change palette order");
	make_info_text2(f);
}
