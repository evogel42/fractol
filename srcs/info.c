/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:23:05 by evogel            #+#    #+#             */
/*   Updated: 2019/05/12 16:05:24 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	make_info_bg(t_fractal *f, int width, int height, int fill)
{
	int			x;
	int			y;
	int			tmp;
	t_mlx		*mlx;

	mlx = &f->mlx;
	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			if (x < 10)
			{
				tmp = (int)(y * f->color.size / height);
				mlx->data[x + y * f->win_x] = f->color.pal[tmp].i;
			}
			else
				mlx->data[x + y * f->win_x] = fill;
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void		make_info_text(t_fractal *f)
{
	static char	names[8][12] = {"mandelbrot", "mandel4", "mandelverse", "julia",
		"julia6", "julia_sin", "zubieta", "thorn"};
	static int	nums[8] = {K1_KEY, K2_KEY, K3_KEY, K4_KEY, K5_KEY, K6_KEY,
		K7_KEY, K8_KEY};
	int				i;
	char			*tmp;

	make_info_bg(f, 270, 300, 0xAA000000);
	i = 0;
	while (f->type != nums[i] && i < 8)
		++i;
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, 10, 0xFFFFFF, "Fractal:");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 150, 10, 0xFFFFFF, names[i]);
	i = 10;
//	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, (i += 30), 0xFFFFFF, "Zoom:");
//	tmp = ft_strjoin(ft_itoa(f->math.zoom), "%");
//	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 150, i, 0xFFFFFF, tmp);
//	free(tmp);
//	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, (i += 30), 0xFFFFFF, "Zoom:");
//	tmp = ft_strjoin(ft_itoa(100.0 / (f->math.plot[1] - f->math.plot[0])), "%");
//	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 150, i, 0xFFFFFF, tmp);
//	free(tmp);
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, (i += 30), 0xFFFFFF, "Max iter:");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 150, i, 0xFFFFFF, (tmp = ft_itoa(f->math.iter)));
	free(tmp);
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, (i += 30), 0xFFFFFF, "Escape val:");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 150, i, 0xFFFFFF, (tmp = ft_itoa(f->math.escape)));
	free(tmp);
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, (i += 30), 0xFFFFFF, "Color range:");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 150, i, 0xFFFFFF, (tmp = ft_itoa(f->color.range)));
	free(tmp);
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, (i += 30), 0xFFFFFF, "Resolution:");
	tmp = ft_strjoin(ft_itoa(f->win_x), "x");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 150, i, 0xFFFFFF, tmp);
	free(tmp);
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 200, i, 0xFFFFFF, (tmp = ft_itoa(f->win_y)));
	free(tmp);
	if (f->type > K3_KEY)
	{
		mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, (i += 50), 0xFFFFFF, "Julia type parameter");
		mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 20, (i += 20), 0xFFFFFF, "------------------------");
		mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 40, (i += 30), 0xFFFFFF, "x =");
		mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 80, i, 0xFFFFFF, (tmp = ft_flotoa(f->math.c[0], 6)));
		free(tmp);
		mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 40, (i += 30), 0xFFFFFF, "y =");
		mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 80, i, 0xFFFFFF, (tmp = ft_flotoa(f->math.c[1], 6)));
		free(tmp);
	}
}

void		make_controls_text(t_fractal *f)
{
	int x;
	int	y;

	make_info_bg(f, 350, f->win_y, 0x60000000);
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
}
