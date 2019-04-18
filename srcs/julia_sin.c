/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_sin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:41:05 by evogel            #+#    #+#             */
/*   Updated: 2019/04/18 15:03:44 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julsin_presets(t_math *math)
{
	static double	val[5][2] = { {1, 0}, {0, 1.5},
		{0.984808, 0.173648}, {-1.29904, -0.75}, {-0.2, 1} };
	static int		i = 0;

	math->c[0] = val[i][0];
	math->c[1] = val[i][1];
	i = (i == 4 ? 0 : i + 1);
}

void	julsin_init(t_math *math)
{
	math->plot[3] = 6;
	math->plot[2] = -6;
	math->plot[1] = 0.5 * RATIO * (math->plot[3] - math->plot[2]);
	math->plot[0] = math->plot[1] * -1;
	math->iter = MAX_ITER;
	math->escape = 4800;
	math->mode = 0;
	math->c[0] = 1.0384;
	math->c[1] = 0.244;
}

float		julia_sin(double x_start, double y_start, t_math *math)
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
		tmp = math->c[0] * sin(zx) * cosh(zy) - math->c[1] * cos(zx) * sinh(zy);
		zy = math->c[1] * sin(zx) * cosh(zy) + math->c[0] * cos(zx) * sinh(zy);
		zx = tmp;
		++n;
	}
	return (n);
}
