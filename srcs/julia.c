/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:21:07 by evogel            #+#    #+#             */
/*   Updated: 2019/05/12 16:05:52 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_presets(t_math *math)
{
	static double	val[5][2] = { {0.285, 0.01}, {-0.835, -0.2321},
		{-0.762910, 0.093017}, {-0.75, 0.0525}, {-0.624, 0.435} };
	static int		i = 0;

	math->c[0] = val[i][0];
	math->c[1] = val[i][1];
	i = (i == 4 ? 0 : i + 1);
}

void	julia_init(t_math *math)
{
	math->plot[3] = 1.5;
	math->plot[2] = -1.5;
	math->plot[1] = 0.5 * RATIO * (math->plot[3] - math->plot[2]);
	math->plot[0] = math->plot[1] * -1;
	math->iter = MAX_ITER;
	math->escape = 16;
	math->mode = 0;
	math->c[0] = -0.747;
	math->c[1] = -0.054;
}

float	julia(double x_start, double y_start, t_math *math)
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
		tmp = zx * zx - zy * zy + math->c[0];
		zy = 2 * zx * zy + math->c[1];
		zx = tmp;
		++n;
	}
	if (n < math->iter)
	{
		tmp = log((log(zx * zx + zy * zy) * 0.5) / log(2)) / log(2);
		n = n + 1 - tmp;
	}
	return (n > 0 ? n : 0);
}
