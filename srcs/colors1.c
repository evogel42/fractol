/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:53:22 by evogel            #+#    #+#             */
/*   Updated: 2019/04/18 20:45:41 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	palette0(int i, void *param)
{
	static int	pal[7] = {0, 0x270056, 0xD20358, 0xFFDD66, 0xC6FFC6, 0x3DECFF, 0x111166};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 7;
	if (f->color.pal != NULL)
		free(f->color.pal);
	if (!(f->color.pal = (t_color *)malloc(sizeof(t_color) * f->color.size)))
		return ;
	i = 0;
	while (i < f->color.size)
	{
		f->color.pal[i].i = pal[i];
		++i;
	}
	make_image(f);
}

void	palette1(int i, void *param)
{
	static int	pal[6] = {0, 0x351845, 0x900C3F, 0xFF9999, 0xFFFFFF, 0x952154};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 6;
	if (f->color.pal != NULL)
		free(f->color.pal);
	if (!(f->color.pal = (t_color *)malloc(sizeof(t_color) * f->color.size)))
		return ;
	i = 0;
	while (i < f->color.size)
	{
		f->color.pal[i].i = pal[i];
		++i;
	}
	make_image(f);
}

void	palette2(int i, void *param)
{
	static int	pal[7] = {0x1F0225, 0x332F91, 0x348AA7, 0x5DD39E, 0xFFEE99, 0xFF6971, 0x7B0337};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 7;
	if (f->color.pal != NULL)
		free(f->color.pal);
	if (!(f->color.pal = (t_color *)malloc(sizeof(t_color) * f->color.size)))
		return ;
	i = 0;
	while (i < f->color.size)
	{
		f->color.pal[i].i = pal[i];
		++i;
	}
	make_image(f);
}

void	palette3(int i, void *param)
{
	static int	pal[4] = {0xE0FFFF, 0x56A7FE, 0x550044, 0xB93145};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 4;
	if (f->color.pal != NULL)
		free(f->color.pal);
	if (!(f->color.pal = (t_color *)malloc(sizeof(t_color) * f->color.size)))
		return ;
	i = 0;
	while (i < f->color.size)
	{
		f->color.pal[i].i = pal[i];
		++i;
	}
	make_image(f);
}
