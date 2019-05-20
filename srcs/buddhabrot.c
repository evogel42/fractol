/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:38:32 by evogel            #+#    #+#             */
/*   Updated: 2019/05/20 11:57:37 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		buddhabrot_init(t_math *math)
{
	math->plot[3] = 1.2;
	math->plot[2] = -1.2;
	math->plot[1] = 0.5 * RATIO * (math->plot[3] - math->plot[2]) - 0.75;
	math->plot[0] = math->plot[1] * -1 - 1.5;
	math->iter = MAX_ITER;
	math->escape = 4;
	math->mode = 0;
	math->c[0] = 0;
	math->c[1] = 0;
}

static void	get_exposure(t_buddha *b, t_fractal *f, double cx, double cy)
{
	double			zx;
	double			zy;
	double			tmp;
	int				index;

	zx = 0;
	zy = 0;
	while (zx * zx + zy * zy < f->math.escape)
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = tmp;
		index = cx2x(zx, f) + cy2y(zy, f) * f->win_x;
		if (index >= 0 && index < f->win_x * f->win_y)
		{
			b->expo[index]++;
			if (b->expo[index] > b->max_expo)
				b->max_expo = b->expo[index];
		}
	}
}

static void	draw_buddha(t_buddha *b, t_fractal *f)
{
	int			x;
	int			y;
	float		res;

	y = 0;
	while (y < f->win_y)
	{
		x = 0;
		while (x < f->win_x)
		{
			res = (double)b->expo[x + y * f->win_x] / b->max_expo
				* f->color.range * 2;
			f->mlx.data[x + y * f->win_x] = get_color(res, &f->color);
			++x;
		}
		++y;
	}
}

void		buddhabrot(t_fractal *f)
{
	static t_buddha	b = {NULL, 0, 0};
	int				x;
	int				y;
	float			res;

	if (b.size != f->win_x * f->win_y)
	{
		b.size = f->win_x * f->win_y;
		b.max_expo = 0;
		if (b.expo != NULL)
			free(b.expo);
		if (!(b.expo = (int *)ft_memalloc(sizeof(int) * b.size)))
			exit(-1);
	}
	while (b.max_expo < f->math.iter && (res = f->math.iter))
	{
		while (res == f->math.iter)
		{
			x = rand() % f->win_x;
			y = rand() % f->win_y;
			res = mandelbrot(x2cx(x, f), y2cy(y, f), &f->math);
		}
		get_exposure(&b, f, x2cx(x, f), y2cy(y, f));
	}
	draw_buddha(&b, f);
}
