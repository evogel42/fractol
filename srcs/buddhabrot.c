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
	int		values[WIN_X * WIN_Y];
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
//	*x = WIN_X * (zx - f->math.plot[0]) / (f->math.plot[1] - f->math.plot[0]);
//	*y = WIN_Y * (zy - f->math.plot[1]) / (f->math.plot[3] - f->math.plot[2]);
	*x = WIN_X * zx / (f->math.plot[1] - f->math.plot[0]) + WIN_X / 2;
	*y = WIN_Y * zy / (f->math.plot[3] - f->math.plot[2]) + WIN_Y / 2;
}	

void			get_exposure(t_buddha *buddha, t_fractal *f, double cx, double cy)//, int *i)
{
	double			zx;
	double			zy;
	double			tmp;
	int				x;
	int				y;
	int				index;
	
	zx = 0;
	zy = 0;
//	ft_printf("for number at: %d\n", i);
	while (zx * zx + zy * zy < f->math.escape)
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = tmp;
		z2xy(zx, zy, &x, &y, f);
		index = x + y * WIN_X;
//		index = (index < 0 ? -index : index);
//		ft_printf("index: x = %8f = %8d y = %8f = %8d\nindex = %d\n", zx, x, zy, y, index);
		if (index >= 0 && index < WIN_X * WIN_Y)
		{
			buddha->exposure[index]++;
			if (buddha->exposure[index] > buddha->max_exposure)
				buddha->max_exposure = buddha->exposure[index];
//			(*i)++;
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
			res = (double)buddha->exposure[x + y * WIN_X] / buddha->max_exposure * f->math.iter;
//			if (res)
//				ft_printf("res: %f\n", res);
			f->mlx.data[x + y * WIN_X] = get_color(res, &f->color);
			++x;
		}
		++y;
	}
}

void	get_values(t_buddha *buddha, t_fractal *f)
{
	int x;
	int y;
	double cx;
	double cy;

	y = 0 ;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			xy2z(x, y, &cx, &cy, f);
			if (mandelbrot(cx, cy, &f->math) < f->math.iter)
				buddha->values[x + y * WIN_X] = 1;
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
	get_values(&buddha, f);
	y = 0 ;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			if (buddha.values[x + y * WIN_X] == 1)
			{
				xy2z(x, y, &cx, &cy, f);
				get_exposure(&buddha, f, cx, cy);
			}
			++x;
		}
		++y;
	}
	i = 0;
	while (buddha.max_exposure < 500)
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
//	ft_printf("exposure generated from %d values\n", count, f);
	ft_printf("max exposure: %d\n", buddha.max_exposure);
	draw_buddha(&buddha,f);
}
