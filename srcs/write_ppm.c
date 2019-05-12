/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:10:35 by evogel            #+#    #+#             */
/*   Updated: 2019/05/12 16:22:48 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*make_filename(int n)
{
	char		*filename;

	if (!(filename = ft_strnew(38)))
		return (NULL);
	ft_strcat(filename, "/Users/evogel/Desktop/screenshot");
	filename[32] = n / 10 + '0';
	filename[33] = n % 10 + '0';
	ft_strcat(filename, ".ppm");
	return (filename);
}

static void	data_fill_ppm(int fd, int *data, int win_x, int win_y)
{
	int			i;

	ft_putendl_fd("P3", fd);
	ft_putnbr_fd(win_x, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(win_y, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
	i = 2;
	while (i < win_x * win_y * 4)
	{
		while (i % 4 != 3 && i >= 0)
		{
			ft_putnbr_fd(((unsigned char*)data)[i--], fd);
			ft_putchar_fd(' ', fd);
		}
		i += 7;
	}
	ft_putchar_fd('\n', fd);
}

void		write_ppm(int key, void *param)
{
	static int	n = 1;
	char		*filename;
	char		*tmp;
	t_fractal	*f;

	f = (t_fractal *)param;
	while (n < 100)
	{
		filename = make_filename(n);
		if (filename == NULL)
			return (ft_putendl("Error creating file"));
		if ((key = open(filename, O_CREAT | O_WRONLY | O_EXCL, 0666)) != -1)
			break ;
		free(filename);
		++n;
	}
	if (n == 100)
		return (ft_putendl("Screenshot limit reached"));
	data_fill_ppm(key, f->mlx.data, f->win_x, f->win_y);
	tmp = ft_strjoin(filename, " was successfully created");
	mlx_string_put(f->mlx.mlx_ptr, f->mlx.win_ptr, 10, 10, 0xFFFFFF, tmp);
	free(filename);
	free(tmp);
	close(key);
}
