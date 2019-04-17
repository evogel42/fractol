/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:53:22 by evogel            #+#    #+#             */
/*   Updated: 2019/04/17 18:39:42 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	palette0(int i, void *param)
{
	static int	pal[7] = {0, 0x000064, 0xff0064, 0xffff64, 0xffffff, 0x00ffff,
		0x0000ff};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 7;
	if (!(f->color.pal != NULL))
		free(f->color.pal);
	if (!(f->color.pal = (t_color *)malloc(sizeof(t_color) * f->color.size)))
		return ;
	i = 0;
	while (i < f->color.size)
	{
		f->color.pal[i].i = pal[i];
		++i;
	}
}

void	palette1(int i, void *param)
{
	static int	pal[7] = {0, 0x351845, 0x900C3F, 0xFF5566, 0xFF9999, 0xFFFFFF, 0x952154};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 7;
	if (!(f->color.pal != NULL))
		free(f->color.pal);
	if (!(f->color.pal = (t_color *)malloc(sizeof(t_color) * f->color.size)))
		return ;
	i = 0;
	while (i < f->color.size)
	{
		f->color.pal[i].i = pal[i];
		++i;
	}
}
