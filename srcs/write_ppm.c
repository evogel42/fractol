/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:10:35 by evogel            #+#    #+#             */
/*   Updated: 2019/04/08 20:46:14 by evogel           ###   ########.fr       */
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

static void	data_fill_ppm(int fd, int *data)
{
	int			i;

	ft_putendl_fd("P3", fd);
	ft_putnbr_fd(WIN_X, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(WIN_Y, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
	i = 2;
	while (i < WIN_X * WIN_Y * 4)
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
	int			fd;
	char		*filename;

	(void)key;
	while (n < 100 && (fd = open((filename = make_filename(n)), 
					O_CREAT | O_WRONLY | O_EXCL, 0666)) == -1)
	{
		if (filename == NULL)
			return (ft_putendl("Error creating file"));
		free(filename);
		++n;
	}
	if (n == 100)
		return (ft_putendl("Screenshot limit reached"));
	data_fill_ppm(fd, ((t_fractal *)param)->mlx.data);
	ft_printf("%s was successfully created\n", filename);
	free(filename);
	close(fd);
}
