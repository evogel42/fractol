/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:15:27 by evogel            #+#    #+#             */
/*   Updated: 2019/04/09 19:10:56 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel4_init(t_math *math)
{
	math->plot[3] = 1.2;
	math->plot[2] = -1.2;
	math->plot[1] = 0.5 * RATIO * (math->plot[3] - math->plot[2]);
	math->plot[0] = math->plot[1] * -1;
	math->iter = MAX_ITER;
	math->escape = 16;
	math->mode = 0;
	math->c[0] = 0;
	math->c[1] = 0;
}

float	mandel4(double cx, double cy, t_math *math)
{
	double	zx;
	double	zy;
	double	tmp;
	float	n;

	zx = cx;
	zy = cy;
	n = 1;
	while (zx * zx + zy * zy < math->escape && n < math->iter)
	{
		tmp = zx * zx * zx * zx + zy * zy * zy * zy - 6 * zx * zx * zy * zy + cx;
		zy = 4 * zx * zx * zx * zy - 4 * zx * zy * zy * zy + cy;
		zx = tmp;
		++n;
	}
	if (n < math->iter)
	{
		tmp = log((log(zx * zx + zy * zy ) * 0.25) / log(4)) / log(4);
		n = n + 1 - tmp;
	}
	return (n > 0 ? n : 0);
}
