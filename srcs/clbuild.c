/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clbuild.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:09:39 by evogel            #+#    #+#             */
/*   Updated: 2019/04/26 12:31:18 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_cl
{
	cl_device_id		device;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	queue;
	cl_mem				d_fractal;
	cl_mem				d_data;
}				t_cl;

cl_device_id	get_device()
{
	cl_platform_id	platform;
	cl_device_id	device;
	int				err;

	err = clGetPlatformIDs(1, &platform, NULL);
	if (err < 0)
	{
		ft_putendl("OpenCL could not identify a platform");
		exit (1);
	}
	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	if (err == CL_DEVICE_NOT_FOUND)
		err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &device, NULL);
	if (err < 0)
	{
		ft_putendl("OpenCL could not ccess any devices");
		exit (1);
	}
	return (device);
}

void	init_cl(t_cl *cl)
{
	cl_int	err;
//	char	*filename;

	cl->device = get_device();
	cl->context = lCreateContext(NULL, 1, &cl->device, NULL, NULL, &err);
//	filename = make_filename(f->type);
	cl->program = build_program(cl, "src/julia6.cl");
	cl->queue = clCreateCommandQueue(cl->context, cl->device, 0, &err);
}

void	make_image(t_fractal *f)
{
	t_cl	cl;
	double	*re;
	double	*im;
	float	*res;
	
	init_cl(&cl);
	init_args(re, im, res);
}
