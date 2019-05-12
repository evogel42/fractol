/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:15:27 by evogel            #+#    #+#             */
/*   Updated: 2019/05/12 16:06:48 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelverse_init(t_math *math)
{
	math->plot[3] = 1.7;
	math->plot[2] = -1.7;
	math->plot[1] = 0.5 * RATIO * (math->plot[3] - math->plot[2]) + 1.3;
	math->plot[0] = math->plot[1] * -1 + 2.6;
	math->iter = MAX_ITER;
	math->escape = 16;
	math->mode = 0;
	math->c[0] = (math->plot[1] - math->plot[0]) * 0.5 + math->plot[0];
	math->c[1] = 0;
}

float	mandelverse(double cx, double cy, t_math *math)
{
	double	zx;
	double	zy;
	double	tmp;
	float	n;

	tmp = cx / (cx * cx + cy * cy);
	cy = -1 * cy / (cx * cx + cy * cy);
	cx = tmp;
	zx = cx;
	zy = cy;
	n = 1;
	while (zx * zx + zy * zy < math->escape && n < math->iter)
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
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
