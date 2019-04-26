__kernel float		julia6(__global double *re, __gloabal double *im,
									__global float *res,
									double cx, double cy,
									int iter, int escape)
{
	unsigned int	i;
	double			zx;
	double			zy;
	double			tmp;
	float			n;

	i = get_global_id(0);
	zx = re[i];
	zy = im[i];
	n = 0;
	while (zx * zx + zy * zy < escape && n < iter)
	{
		tmp = zx * zx * zx * zx * zx * zx - 15 * zx * zx * zx * zx * zy * zy
			+ 15 * zx * zx * zy * zy * zy * zy - zy * zy * zy * zy * zy * zy
			+ cx;
		zy = 6 * zx * zx * zx * zx * zx * zy - 20 * zx * zx * zx * zy * zy * zy
			+ 6 * zx * zy * zy * zy * zy * zy + cy;
		zx = tmp;
		++n;
	}
	if (n < iter)
	{
		tmp = log((log(zx * zx + zy * zy ) / 6) / log(6)) / log(6);
		n = n + 1 - tmp;
	}
	res[i] = (n > 0 ? n : 0);
}
