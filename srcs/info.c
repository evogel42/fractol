/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:23:05 by evogel            #+#    #+#             */
/*   Updated: 2019/05/20 14:26:17 by evogel           ###   ########.fr       */
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

static int	string_put(t_fractal *f, int x, int y, int param)
{
	char	*tmp;
	int		len;

	if (!(tmp = ft_itoa(param)))
		return (0);
	len = ft_strlen(tmp);
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, x, y, WHITE, tmp);
	free(tmp);
	return (len);
}

static void	make_info_text2(t_fractal *f, int i, void *mlx, void *win)
{
	char	*tmp;
	int		len;

	mlx_string_put(mlx, win, 20, (i += 30), WHITE, "Resolution:");
	len = string_put(f, 150, i, f->win_x);
	mlx_string_put(mlx, win, (len = 150 + len * 10), i, WHITE, "x");
	string_put(f, len + 10, i, f->win_y);
	if (f->type > XK_3 && f->type != XK_9)
	{
		mlx_string_put(mlx, win, 20, (i += 50), WHITE, "Julia type parameter");
		mlx_string_put(mlx, win, 20, (i += 20), WHITE,
				"------------------------");
		mlx_string_put(mlx, win, 40, (i += 30), WHITE, "x =");
		if ((tmp = ft_flotoa(f->math.c[0], 6)))
		{
			mlx_string_put(mlx, win, 80, i, WHITE, tmp);
			free(tmp);
		}
		mlx_string_put(mlx, win, 40, (i += 30), WHITE, "y =");
		if ((tmp = ft_flotoa(f->math.c[1], 6)))
		{
			mlx_string_put(mlx, win, 80, i, WHITE, tmp);
			free(tmp);
		}
	}
}

void		make_info_text1(t_fractal *f, void *mlx, void *win)
{
	static char	names[8][12] = {"mandelbrot", "mandel4", "mandelverse", "julia",
		"julia6", "julia_sin", "zubieta", "thorn"};
	static int	nums[8] = {XK_1, XK_2, XK_3, XK_4, XK_5, XK_6,
		XK_7, XK_8};
	int			i;

	make_info_bg(f, 270, 330, 0xAA000000);
	i = 0;
	while (f->type != nums[i] && i < 8)
		++i;
	mlx_string_put(mlx, win, 20, 10, WHITE, "Fractal:");
	mlx_string_put(mlx, win, 150, 10, WHITE, names[i]);
	i = 10;
	mlx_string_put(mlx, win, 20, (i += 30), WHITE, "Zoom:");
	mlx_string_put(mlx, win, 150, i, WHITE, "x");
	string_put(f, 160, i, f->math.zoom);
	mlx_string_put(mlx, win, 20, (i += 30), WHITE, "Max iter:");
	string_put(f, 150, i, f->math.iter);
	mlx_string_put(mlx, win, 20, (i += 30), WHITE, "Escape val:");
	string_put(f, 150, i, f->math.escape);
	mlx_string_put(mlx, win, 20, (i += 30), WHITE, "Color range:");
	string_put(f, 150, i, f->color.range);
	make_info_text2(f, i, mlx, win);
}

void		make_controls_text(t_fractal *f, void *mlx, void *win)
{
	int	y;

	make_info_bg(f, 350, f->win_y, 0x60000000);
	mlx_string_put(mlx, win, 20, (y = 10), WHITE, C1);
	mlx_string_put(mlx, win, 20, (y += 20), WHITE, C2);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C3);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C4);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C5);
	mlx_string_put(mlx, win, 20, (y += 60), WHITE, C6);
	mlx_string_put(mlx, win, 20, (y += 20), WHITE, C7);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C8);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C9);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C10);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C11);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C12);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C13);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C14);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C15);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C16);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C17);
	mlx_string_put(mlx, win, 20, (y += 60), WHITE, C18);
	mlx_string_put(mlx, win, 20, (y += 20), WHITE, C19);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C20);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C21);
	mlx_string_put(mlx, win, 20, (y += 30), WHITE, C22);
}
