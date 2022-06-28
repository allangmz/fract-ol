/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:34:24 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/28 14:35:21 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mandelbrot(t_group *group)
{
	group->mouse->x = 1080 / 2;
	group->mouse->y = 1080 / 2;
	group->fractal->x1 = -1.8;
	group->fractal->x2 = 1.8;
	group->fractal->y1 = -1.8;
	group->fractal->y2 = 1.8;
	group->img->iteration_max = 100;
	group->img->zoom = 300;
	group->img->lastzoom = 300;
	group->fractal->variable1 = 0;
	group->fractal->variable2 = 0;
}

void	ft_init_julia(t_group *group)
{
	group->mouse->x = 1080 / 2;
	group->mouse->y = 1080 / 2;
	group->fractal->x1 = -2;
	group->fractal->x2 = 2 ;
	group->fractal->y1 = -2;
	group->fractal->y2 = 2;
	group->img->iteration_max = 100;
	group->img->zoom = 100;
	group->img->lastzoom = 100;
	group->fractal->variable1 = 0;
	group->fractal->variable2 = 0;
}

int	ft_verif_arg(int argc, char **argv)
{
	int	fractal_code;

	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		fractal_code = 1;
	}
	else if (argc == 2 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal_code = 2;
	}
	else
	{
		printf("\nerreur nom de fractal : ./fract-ol [nom fractal]");
		printf("\nfractal disponible : mandelbrot, julia.\n\n");
		exit(0);
	}
	return (fractal_code);
}

void	ft_hook(t_group *group)
{
	mlx_mouse_hook(group->win->win, mouse_hook, group);
	mlx_hook(group->win->win, 2, 1L << 0, key_hook, group);
	mlx_hook(group->win->win, 17, 1L << 0, ft_exit, group);
	mlx_loop(group->win->mlx);
}

int	main(int argc, char **argv)
{
	t_group		group;
	t_win		win;
	t_img		img;
	t_mouse		mouse;
	t_fractal	fractal;

	win.x_size = 1080;
	win.y_size = 1080;
	group.mouse = &mouse;
	group.win = &win;
	group.img = &img;
	group.fractal = &fractal;
	group.fractal->fractal_code = ft_verif_arg(argc, argv);
	if (group.fractal->fractal_code == 1)
		ft_init_mandelbrot(&group);
	else if (group.fractal->fractal_code == 2)
		ft_init_julia(&group);
	group.win->mlx = mlx_init();
	group.win->win = mlx_new_window(group.win->mlx, 1080, 1080, "fract-ol");
	group.img->img = mlx_new_image(group.win->mlx, 1080, 1080);
	group.img->addr = mlx_get_data_addr(group.img->img,
			&group.img->bits_per_pixel, &group.img->line_length,
			&group.img->endian);
	ft_draw_fractal(group.win, group.img, group.mouse, group.fractal);
	ft_hook(&group);
}
