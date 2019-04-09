/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:33:24 by evogel            #+#    #+#             */
/*   Updated: 2019/04/09 16:52:35 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(float res, t_palette *c, int iter)
{
	t_color	color;
	int		index1;
	int		index2;

	if ((int)res == iter)
		return (0);
	index1 = (int)res % c->range;
	color.i = c->pal[index1].i;
	res -= (int)res;
	if ((index2 = index1 + 1) == c->range)
		index2 = 0;
	color.c[0] += (c->pal[index2].c[0] - c->pal[index1].c[0]) * res;
	color.c[1] += (c->pal[index2].c[1] - c->pal[index1].c[1]) * res;
	color.c[2] += (c->pal[index2].c[2] - c->pal[index1].c[2]) * res;
	return (color.i);
}

static void	maths(t_fractal *f, int lims[2], double scale_x, double scale_y)
{
	int		x;
	int		y;
	double	cx;
	double	cy;
	float	res;

	y = 0;
	while (y < WIN_Y)
	{
		x = lims[0];
		cy = y * scale_y + f->math.plot[2];
		while (x < lims[1])
		{
			cx = x * scale_x + f->math.plot[0];
			res = f->fun.fractal[f->type](cx, cy, &f->math);
			f->mlx.data[x + y * WIN_X] = get_color(res, &f->color, f->math.iter);
			++x;
		}
		++y;
	}
}

static void	*section(void *param)
{
	static int	i = 0;
	int			lims[2];
	t_fractal	*f;
	
	f = (t_fractal *)param;
	if (i >= THREADS)
		i = 0;
	lims[0] = (WIN_X / THREADS) * i;
	lims[1] = (WIN_X / THREADS) * ++i;
	maths(f, lims, (f->math.plot[1] - f->math.plot[0]) / WIN_X, 
			(f->math.plot[3] - f->math.plot[2]) / WIN_Y);
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
