/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:21:07 by evogel            #+#    #+#             */
/*   Updated: 2019/04/26 14:18:14 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia6_presets(t_math *math)
{
	static double	val[5][2] = { {-1.063579, 0.032842}, {-0.923468, 0.136},
		{-0.184421, -0.818526}, {-0.016, -0.794667}, {-0.4743, -0.3446} };
	static int		i = 0;

	math->c[0] = val[i][0];
	math->c[1] = val[i][1];
	i = (i == 4 ? 0 : i + 1);
}

void	julia6_init(t_math *math)
{
	math->plot[3] = 1.2;
	math->plot[2] = -1.2;
	math->plot[1] = 0.5 * RATIO * (math->plot[3] - math->plot[2]);
	math->plot[0] = math->plot[1] * -1;
	math->iter = MAX_ITER;
	math->escape = 16;
	math->mode = 0;
	math->c[0] = -0.326167;
	math->c[1] = -0.766211;
}

float		julia6(double x_start, double y_start, t_math *math)
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
		tmp = zx * zx * zx * zx * zx * zx - 15 * zx * zx * zx * zx * zy * zy
			+ 15 * zx * zx * zy * zy * zy * zy - zy * zy * zy * zy * zy * zy
			+ math->c[0];
		zy = 6 * zx * zx * zx * zx * zx * zy - 20 * zx * zx * zx * zy * zy * zy
			+ 6 * zx * zy * zy * zy * zy * zy + math->c[1];
		zx = tmp;
		++n;
	}
	if (n < math->iter)
	{
		tmp = log((log(zx * zx + zy * zy ) / 6) / log(6)) / log(6);
		n = n + 1 - tmp;
	}
	return (n > 0 ? n : 0);
}
