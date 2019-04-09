/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:53:22 by evogel            #+#    #+#             */
/*   Updated: 2019/04/09 13:55:35 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color1(int i, void *param)
{
	t_palette	*col;

	col = &((t_fractal *)param)->color;
	col->range = 60;
	if (col->pal != NULL)
		free(col->pal);
	if(!(col->pal = (t_color *)ft_memalloc(sizeof(t_color) * col->range)))
		exit(-1);
	i = 0;
	while (i < col->range)
	{
		col->pal[i].i = (i > 0 ? col->pal[i - 1].i : 100);
		if (col->pal[i].c[2] < 250 && col->pal[i].c[0] == 100)
			col->pal[i].c[2] += 25;
		else if (col->pal[i].c[1] < 250 && col->pal[i].c[2] == 250)
			col->pal[i].c[1] += 25;
		else if (col->pal[i].c[0] < 250 && col->pal[i].c[1] == 250)
			col->pal[i].c[0] += 15;
		else if (col->pal[i].c[0] == 250 && col->pal[i].c[2] > 0)
			col->pal[i].c[2] -= 25;
		else if (col->pal[i].c[0] == 250 && col->pal[i].c[1] > 0)
			col->pal[i].c[1] -= 25;
		else if (col->pal[i].c[0] > 100)
			col->pal[i].c[0] -= 15;
		i++;
	}
}
