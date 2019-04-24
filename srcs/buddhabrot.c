/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 17:30:37 by evogel            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_buddha
{
	int		exposure[WIN_X * WIN_Y];
	int		max_exposure;
}				t_buddha;

void			xy2z(int x, int y, double *zx, double *zy, t_fractal *f)
{
	*zx = x * (f->math.plot[1] - f->math.plot[0]) / WIN_X + f->math.plot[0];
	*zy = y * (f->math.plot[3] - f->math.plot[2]) / WIN_Y + f->math.plot[2];
}	

void			z2xy(double zx, double zy, int *x, int *y, t_fractal *f)
{
	*x = WIN_X * zx / (f->math.plot[1] - f->math.plot[0]) + WIN_X / 2;
	*y = WIN_Y * zy / (f->math.plot[3] - f->math.plot[2]) + WIN_Y / 2;
}	

void			get_exposure(t_buddha *buddha, t_fractal *f, double cx, double cy)
{
	double			zx;
	double			zy;
	double			tmp;
	int				x;
	int				y;
	int				index;
	
	zx = 0;
	zy = 0;
	while (zx * zx + zy * zy < f->math.escape)
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = tmp;
		z2xy(zx, zy, &x, &y, f);
		index = x + y * WIN_X;
		if (index >= 0 && index < WIN_X * WIN_Y)
		{
			buddha->exposure[index]++;
			if (buddha->exposure[index] > buddha->max_exposure)
				buddha->max_exposure = buddha->exposure[index];
		}
	}
}

void		draw_buddha(t_buddha *buddha, t_fractal *f)
{
	int			x;
	int			y;
	float		res;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			res = (double)buddha->exposure[x + y * WIN_X] / buddha->max_exposure * f->color.range * 2;
			f->mlx.data[x + y * WIN_X] = get_color(res, &f->color);
			++x;
		}
		++y;
	}
}

void	buddhabrot(t_fractal *f)
{
	static t_buddha	buddha;
	int			i;
	int			x;
	int			y;
	float		res;
	double		cx;
	double		cy;
	
	ft_bzero((void*)&buddha, sizeof(t_buddha));
	i = 0;
	while (buddha.max_exposure < 800)
	{
		res = f->math.iter;
		while (res == f->math.iter)
		{
			x = rand() % WIN_X;
			y = rand() % WIN_Y;
			xy2z(x, y, &cx, &cy, f);
			res = mandelbrot(cx, cy, &f->math);
		}
		get_exposure(&buddha, f, cx, cy);
	}
	draw_buddha(&buddha,f);
}
