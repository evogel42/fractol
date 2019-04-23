/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:13:35 by brichard          #+#    #+#             */
/*   Updated: 2019/04/23 17:56:13 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx_codes.h"
# include "mlx.h"

/*
** Authorised includes
*/

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

/*
** Bonus includes
*/

# include <pthread.h>

# define RATIO 1.6
# define WIN_Y 1:q
:q

# define WIN_X (int)(WIN_Y * RATIO)
# define THREADS 1
# define MAX_ITER 60
# define FRACT_NUM 8

# define PUT1 ft_putendl("HERE1");
# define PUT2 ft_putendl("HERE2");
# define PUT3 ft_putendl("HERE3");
# define PUT4 ft_putendl("HERE4");
# define PUT5 ft_putendl("HERE5");

typedef union	u_color
{
	unsigned int	i;
	unsigned char	c[4];
}				t_color;

typedef	struct	s_palette
{
	t_color			*pal;
	unsigned short	size;
	unsigned short	start;
	int				range;
}				t_palette;

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
}				t_mlx;

/*
** plot[0,1,2,3] = x.min, x.max, y.min, y.max
*/

typedef struct	s_math
{
	double	plot[4];
	int		iter;
	int		escape;
	short	mode;
	double	c[2];
}				t_math;

typedef	struct	s_functions
{
	void	(*key[KEY_MAX])(int, void *);
	void	(*mouse[MOUSE_MAX])(int, int, void *);
	float	(*fractal[FRACT_NUM])(double, double, t_math *);
}				t_functions;

typedef	struct	s_fractal
{
	short		type;
	t_mlx		mlx;
	t_math		math;
	t_palette	color;
	t_functions	fun;
}				t_fractal;

/*
** Init functions
*/

void	window_init(t_mlx *mlx);
void	maths_init(t_fractal *f);
void	fun_tables_init(t_functions *fun, int type);
void	color_init(t_fractal *f);

/*
** Fractal functions
*/

float	mandelbrot(double cx, double cy, t_math *math);
void	mandelbrot_init(t_math *math);

float	julia(double x_start, double y_start, t_math *math);
void	julia_init(t_math *math);
void	julia_presets(t_math *math);

float	thorn(double x_start, double y_start, t_math *math);
void	thorn_init(t_math *math);
void	thorn_presets(t_math *math);

float	julia_sin(double x_start, double y_start, t_math *math);
void	julsin_init(t_math *math);
void	julsin_presets(t_math *math);

float	zubieta(double x_start, double y_start, t_math *math);
void	zubieta_init(t_math *math);
void	zubieta_presets(t_math *math);

float	mandel4(double cx, double cy, t_math *math);
void	mandel4_init(t_math *math);

float	julia6(double x_start, double y_start, t_math *math);
void	julia6_init(t_math *math);
void	julia6_presets(t_math *math);

float	mandelverse(double cx, double cy, t_math *math);
void	mandelverse_init(t_math *math);

/*
** Color functions
*/

void	color_start(int key, void *param);
void	shift_range(int key, void *param);
void	palette0(int i, void *param);
void	palette1(int i, void *param);
void	palette2(int i, void *param);
void	palette3(int i, void *param);

/*
** mlx hook functions
*/

int		do_close1(int keycode, void *param);
int		do_close2(void *param);
int		do_key(int keycode, void *param);
int		do_mouse(int button, int x, int y, void *param);
int		do_move(int x, int y, void *param);

/*
** key/mouse event functions
*/

void	zoom_in(int x, int y, void *param);
void	zoom_out(int x, int y, void *param);
void	center_click(int x, int y, void *param);
void	reset(int key, void *param);
void	pan_image(int key, void *param);
void	change_iter(int key, void *param);
void	change_escape(int key, void *param);
void	presets(int key, void *param);
void	julia_mode(int x, int y, void *param);
void	julia_c_modif(int key, void *param);
void	change_type(int key, void *param);

/*
** Creation functions
*/

void	make_image(t_fractal *f);
void	write_ppm(int key, void *param);

void	buddhabrot(t_fractal *f);
int		get_color(float res, t_palette *c);

#endif
