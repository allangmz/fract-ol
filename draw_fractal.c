/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:01:05 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/28 14:30:03 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_calcul_iteration(t_img *img, double *c, double *z, double tmp)
{
	int	i;

	i = 0;
	while ((z[0] * z[0] + z[1] * z[1]) < 4 && i < img->iteration_max)
	{
		tmp = z[0];
		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[1] * tmp + c[1];
		i++;
	}
	return (i);
}

void	ft_draw_mandelbrot(t_img *img, t_fractal *mandelbrot)
{
	int		coord[2];
	int		i;
	double	z[2];
	double	c[2];
	double	tmp;

	coord[0] = 0;
	while (coord[0] < 1080)
	{
		coord[1] = 0;
		while (coord[1] < 1080)
		{
			c[0] = (float)coord[0] / img->zoom + mandelbrot->x1;
			c[1] = (float)coord[1] / img->zoom + mandelbrot->y1;
			z[0] = 0;
			z[1] = 0;
			i = ft_calcul_iteration(img, c, z, tmp);
			ft_set_and_put_colors_pixel(img, coord[0], coord[1], i);
			coord[1] += 1;
		}
		coord[0] += 1;
	}
}

void	ft_draw_julia(t_img *img, t_fractal *julia)
{
	int		coord[2];
	int		i;
	double	z[2];
	double	c[2];
	double	tmp;

	coord[0] = 0;
	while (coord[0] < 1080)
	{
		coord[1] = 0;
		while (coord[1] < 1080)
		{
			c[0] = 0.285 + julia->variable1;
			c[1] = 0.01 + julia->variable2;
			z[0] = (float)coord[0] / img->zoom + julia->x1;
			z[1] = (float)coord[1] / img->zoom + julia->y1;
			i = ft_calcul_iteration(img, c, z, tmp);
			ft_set_and_put_colors_pixel(img, coord[0], coord[1], i);
			coord[1] += 1;
		}
		coord[0] += 1;
	}
}

int	ft_draw_fractal(t_win *win, t_img *img, t_mouse *mouse, t_fractal *fractal)
{
	if (img->lastzoom != img->zoom)
	{
		fractal->x1 = (((mouse->x / img->lastzoom) * img->zoom - mouse->x)
				/ img->zoom + fractal->x1);
		fractal->y1 = (((mouse->y / img->lastzoom) * img->zoom - mouse->y)
				/ img->zoom + fractal->y1);
	}
	if (fractal->fractal_code == 1)
		ft_draw_mandelbrot(img, fractal);
	if (fractal->fractal_code == 2)
		ft_draw_julia(img, fractal);
	img->lastzoom = img->zoom;
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	return (0);
}
