/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thorn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:54:56 by evogel            #+#    #+#             */
/*   Updated: 2019/04/08 22:53:54 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	thorn_presets(t_math *math)
{
	static double	val[5][2] = { {1, 1}, {2, 2},
		{3, 3}, {4, 4}, {5, 5} };
	static int		i = 0;

	math->c[0] = val[i][0];
	math->c[1] = val[i][1];
	i = (i == 4 ? 0 : i + 1);
}

void	thorn_init(t_math *math)
{
	math->plot[3] = 5;
	math->plot[2] = -5;
	math->plot[1] = 0.5 * RATIO * (math->plot[3] - math->plot[2]);
	math->plot[0] = math->plot[1] * -1;
	math->iter = MAX_ITER;
	math->escape = 400;
	math->mode = 0;
	math->c[0] = 0;
	math->c[1] = 0;
}

float	thorn(double x_start, double y_start, t_math *math)
{
	double	zx;
	double	zy;
	double	tmp;
	int		n;

	zx = x_start;
	zy = y_start;
	n = 0;
	while (zx * zx + zy * zy < math->escape && n < math->iter)
	{
		tmp = zx / cos(zy) + math->c[0];
		zy = zy / cos(zx) + math->c[1];
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
