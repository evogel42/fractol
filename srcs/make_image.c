/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:33:24 by evogel            #+#    #+#             */
/*   Updated: 2019/05/20 11:50:30 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_color(float res, t_palette *c)
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

static void	maths(t_fractal *f, int lims[2])
{
	int		x;
	int		y;
	float	res;

	y = 0;
	while (y < f->win_y)
	{
		x = lims[0];
		while (x < lims[1])
		{
			res = f->fun.fractal[f->type](x2cx(x, f), y2cy(y, f), &f->math);
			if ((int)res == f->math.iter)
				f->mlx.data[x + y * f->win_x] = 0;
			else
				f->mlx.data[x + y * f->win_x] = get_color(res, &f->color);
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
	lims[0] = (f->win_x / THREADS) * i;
	lims[1] = (f->win_x / THREADS) * ++i;
	if (i >= THREADS)
		i = 0;
	maths(f, lims);
	return (NULL);
}

void		make_image(t_fractal *f)
{
	pthread_t	tid[THREADS];
	t_mlx		*mlx;
	int			i;

	if (f->type != XK_9)
	{
		i = 0;
		while (i < THREADS)
			if (pthread_create(&tid[i++], NULL, section, (void *)f) != 0)
				exit(-1);
		i = 0;
		while (i < THREADS)
			if (pthread_join(tid[i++], NULL) != 0)
				exit(-1);
	}
	else
		buddhabrot(f);
	mlx = &f->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	if (f->info == 1)
		make_controls_text(f, mlx->mlx_ptr, mlx->win_ptr);
	if (f->info == 2)
		make_info_text1(f, mlx->mlx_ptr, mlx->win_ptr);
}
