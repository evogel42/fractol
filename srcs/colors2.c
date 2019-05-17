/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:39:32 by evogel            #+#    #+#             */
/*   Updated: 2019/05/17 14:39:54 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	palette5(int i, void *param)
{
	static int	pal[9] = {0xF7FCFD, 0xE0ECF4, 0xBFD3E6, 0x9EBCDA, 0x8C96C6,
		0x8C6BB1, 0x88419D, 0x810F7C, 0xE28CD5};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 9;
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

void	palette6(int i, void *param)
{
	static int	pal[6] = {0x85FFD0, 0x84D2FF, 0xE199FF, 0xFF8998, 0xFFD685,
		0xFFF385};
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

void	palette7(int i, void *param)
{
	static int	pal[8] = {0x331436, 0x331436, 0x7A1745, 0xCB4F57, 0xEB9961,
		0xFCF4B6, 0xFF9999, 0x7A1745};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 8;
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

void	palette8(int i, void *param)
{
	static int	pal[15] = {0x081D58, 0x081D58, 0x253494, 0x225EA8, 0x1D91C0,
		0x41B6C4, 0x7FCDBB, 0xC7E9B4, 0xD9E8B4, 0xEDF8B1, 0xF4FAC6, 0xFEFDDB,
		0xFFFFD9, 0x1D91C0, 0x223494};
	t_fractal	*f;

	f = (t_fractal *)param;
	f->color.size = 15;
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

void	palette9(int i, void *param)
{
	static int	pal[7] = {0x332F91, 0x78478B, 0xB65070, 0xF08664, 0xFCCB87,
		0xDBE6A2, 0x88BFB1};
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
