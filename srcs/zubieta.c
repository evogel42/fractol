/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zubieta.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:49:10 by evogel            #+#    #+#             */
/*   Updated: 2019/04/08 23:15:39 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zubieta_presets(t_math *math)
{
	static double	val[5][2] = { {0.285, 0.01}, {-0.835, -0.2321},
		{-0.7269, 0.1889}, {0, -0.8}, {-0.624, 0.435} };
	static int		i = 0;

	math->c[0] = val[i][0];
	math->c[1] = val[i][1];
	i = (i == 4 ? 0 : i + 1);
}

void	zubieta_init(t_math *math)
{
	math->plot[3] = 1.2;
	math->plot[2] = -1.2;
	math->plot[1] = 0.5 * RATIO * (math->plot[3] - math->plot[2]);
	math->plot[0] = math->plot[1] * -1;
	math->iter = 400;
	math->escape = 16;
	math->mode = 0;
	math->c[0] = 0.14976;
	math->c[1] = 0;
}

float		zubieta(double x_start, double y_start, t_math *math)
{
	double	zx;
	double	zy;
	double	tmp;
	float	n;

	zx = x_start;
	zy = y_start;
	n = 0;
	while (zx * zx + zy * zy < math->escape && n < math->iter)
	{
		tmp = zx * zx - zy * zy +
			(math->c[0] * zx + math->c[1] * zy) / (zx * zx + zy * zy);
		zy = 2 * zx * zy +
			(math->c[1] * zx - math->c[0] * zy) / (zx * zx + zy * zy);
		zx = tmp;
		++n;
	}
	if (n < math->iter)
	{
		tmp = log((log(zx * zx + zy * zy ) * 0.5) / log(2)) / log(2);
		n = n + 1 - tmp;
	}
	return (n > 0 ? n : 0);
}
/*
c.x = 0.149760 | c.y = 0.000000
c.x = 0.153600 | c.y = 0.000000
c.x = 0.168960 | c.y = 0.000000
c.x = 0.165120 | c.y = 0.012000
c.x = 0.133393 | c.y = -0.131016
c.x = 0.152589 | c.y = -0.002642
c.x = 0.152589 | c.y = -0.000242
*/
