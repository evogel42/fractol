/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:13:35 by brichard          #+#    #+#             */
/*   Updated: 2019/05/20 12:07:05 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx_codes.h"
# include "mlx.h"

/*
**void end(void)__attribute__((destructor));
*/

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

# define RATIO 16 / 9
# define WIN_Y 720
# define WIN_X (int)(WIN_Y * RATIO)
# define THREADS 8
# define MAX_ITER 60

# define C1	"Mouse Controls"
# define C2 "--------------------------------"
# define C3 "Scrollwheel : Zoom in/out"
# define C4 "Left click  : Center"
# define C5 "Wheel click : Lock/unlock param"
# define C6 "Keyboard Controls"
# define C7 "--------------------------------"
# define C8 "#1-9   : Change fractal"
# define C9 "Arrows : Pan image"
# define C10 "WASD   : Increment param"
# define C11 "< >    : Vary max iterations"
# define C12 "- +    : Vary escape value"
# define C13 "Tab    : Example param values"
# define C14 "I      : Toggle info"
# define C15 "Space  : Reset"
# define C16 "F15    : Save screenshot"
# define C17 "Numpad Controls"
# define C18 "--------------------------------"
# define C19 "#0-9 : Change color palette"
# define C20 "- +  : Change color range"
# define C21 "*    : Change palette order"
# define WHITE 0xFFFFFF

typedef struct	s_buddha
{
	int		*expo;
	int		size;
	int		max_expo;
}				t_buddha;

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
	double		plot[4];
	int			iter;
	int			escape;
	short		mode;
	double		c[2];
	long long	zoom;
}				t_math;

typedef	struct	s_functions
{
	void	(*key[KEY_MAX])(int, void *);
	void	(*mouse[MOUSE_MAX])(int, int, void *);
	float	(*fractal[K0_KEY])(double, double, t_math *);
	void	(*fset[2][K0_KEY])(t_math *);
}				t_functions;

typedef	struct	s_fractal
{
	short		type;
	short		info;
	int			win_x;
	int			win_y;
	t_mlx		mlx;
	t_math		math;
	t_palette	color;
	t_functions	fun;
}				t_fractal;

/*
** Init functions
*/

void			window_init(t_mlx *mlx, int win_x, int win_y);
void			maths_init(t_fractal *f);
void			fun_tables_init(t_functions *fun, int type);
void			color_init(t_fractal *f);
void			events_manager(t_fractal *f);

/*
** Fractal functions
*/

float			mandelbrot(double cx, double cy, t_math *math);
void			mandelbrot_init(t_math *math);

float			mandel4(double cx, double cy, t_math *math);
void			mandel4_init(t_math *math);

float			mandelverse(double cx, double cy, t_math *math);
void			mandelverse_init(t_math *math);

float			julia(double x_start, double y_start, t_math *math);
void			julia_init(t_math *math);
void			julia_presets(t_math *math);

float			julia6(double x_start, double y_start, t_math *math);
void			julia6_init(t_math *math);
void			julia6_presets(t_math *math);

float			julia_sin(double x_start, double y_start, t_math *math);
void			julsin_init(t_math *math);
void			julsin_presets(t_math *math);

float			zubieta(double x_start, double y_start, t_math *math);
void			zubieta_init(t_math *math);
void			zubieta_presets(t_math *math);

float			thorn(double x_start, double y_start, t_math *math);
void			thorn_init(t_math *math);
void			thorn_presets(t_math *math);

void			buddhabrot(t_fractal *f);
void			buddhabrot_init(t_math *math);

/*
** Color functions
*/

int				get_color(float res, t_palette *c);
void			color_start(int key, void *param);
void			shift_range(int key, void *param);
void			palette0(int i, void *param);
void			palette1(int i, void *param);
void			palette2(int i, void *param);
void			palette3(int i, void *param);
void			palette4(int i, void *param);
void			palette5(int i, void *param);
void			palette6(int i, void *param);
void			palette7(int i, void *param);
void			palette8(int i, void *param);
void			palette9(int i, void *param);

/*
** mlx hook functions
*/

int				do_close1(int keycode, void *param);
int				do_close2(void *param);
int				do_key(int keycode, void *param);
int				do_mouse(int button, int x, int y, void *param);
int				do_move(int x, int y, void *param);

/*
** key/mouse event functions
*/

void			zoom_in(int x, int y, void *param);
void			zoom_out(int x, int y, void *param);
void			center_click(int x, int y, void *param);
void			reset(int key, void *param);
void			pan_image(int key, void *param);
void			change_iter(int key, void *param);
void			change_escape(int key, void *param);
void			presets(int key, void *param);
void			julia_mode(int x, int y, void *param);
void			julia_c_modif(int key, void *param);
void			change_type(int key, void *param);
void			disp_info(int key, void *param);
void			res_increase(int key, void *param);
void			change_res(int key, void *param);

/*
** Creation functions
*/

void			make_image(t_fractal *f);
void			make_info_text1(t_fractal *f, void *mlx, void *win);
void			make_controls_text(t_fractal *f, void *mlx, void *win);
void			write_ppm(int key, void *param);

/*
** Tools
*/

double			x2cx(int x, t_fractal *f);
double			y2cy(int y, t_fractal *f);
int				cx2x(double cx, t_fractal *f);
int				cy2y(double cy, t_fractal *f);
void			calc_zoom(t_fractal *f);

#endif
