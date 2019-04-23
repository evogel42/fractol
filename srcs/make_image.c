/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:33:24 by evogel            #+#    #+#             */
/*   Updated: 2019/04/23 16:39:38 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(float res, t_palette *c)
{
	int				index1;
	int				index2;
	double			scale;
	t_color			color;

	scale = fmod(res, c->range) * c->size / c->range;
	index1 = ((int)scale + c->start) % c->size;
	if ((index2 = index1 + 1) == c->size)
		index2 = 0;
	scale -= (int)scale;
	color.i = c->pal[index1].i;
	color.c[0] += (c->pal[index2].c[0] - c->pal[index1].c[0]) * scale;
	color.c[1] += (c->pal[index2].c[1] - c->pal[index1].c[1]) * scale;
	color.c[2] += (c->pal[index2].c[2] - c->pal[index1].c[2]) * scale;
	return (color.i);
}

static void	maths(t_fractal *f, int x_min, int x_max)
{
	int		x;
	int		y;
	double	scale_x;
	double	scale_y;
	float	res;

	if (f->type == 0)
		buddhabrot(f);
	else
	{
	scale_x = (f->math.plot[1] - f->math.plot[0]) / WIN_X;
	scale_y = (f->math.plot[3] - f->math.plot[2]) / WIN_Y;
	y = 0;
	while (y < WIN_Y)
	{
		x = x_min;
		while (x < x_max)
		{
			res = f->fun.fractal[f->type](x * scale_x + f->math.plot[0],
					y * scale_y + f->math.plot[2], &f->math);
			if ((int)res == f->math.iter)
				f->mlx.data[x + y * WIN_X] = 0;
			else
				f->mlx.data[x + y * WIN_X] = get_color(res, &f->color);
			++x;
		}
		++y;
	}
	}
}

static void	*section(void *param)
{
	static int	i = 0;
	int			x_min;
	int			x_max;
	t_fractal	*f;
	
	f = (t_fractal *)param;
	if (i >= THREADS)
		i = 0;
	x_min = (WIN_X / THREADS) * i;
	x_max = (WIN_X / THREADS) * ++i;
	maths(f, x_min, x_max);
	return (NULL);
}

void	make_image(t_fractal *f)
{
	pthread_t	tid[THREADS];
	t_mlx		*mlx;
	int			i;

	mlx = &f->mlx;
	i = 0;
	while (i < THREADS)
		if (pthread_create(&tid[i++], NULL, section, (void *)f) != 0)
			exit(-1); 
	i = 0;
	while (i < THREADS)
		if (pthread_join(tid[i++], NULL) != 0)
			exit(-1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
