/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:51:24 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/28 14:05:26 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		x_size;
	int		y_size;
}	t_win;

typedef struct s_img
{	
	void	*img;
	char	*dest;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	lastzoom;
	int		iteration_max;
}	t_img;

typedef struct s_mouse
{
	int		x;
	int		y;
}	t_mouse;

typedef struct s_fractal
{
	int		fractal_code;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	variable1;
	double	variable2;
}	t_fractal;

typedef struct s_group
{
	t_img		*img;
	t_win		*win;
	t_mouse		*mouse;
	t_fractal	*fractal;
}	t_group;

int		ft_verif_arg(int argc, char **argv);
void	ft_init_julia(t_group *group);
void	ft_init_mandelbrot(t_group *group);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_draw_fractal(t_win *win, t_img *img,
			t_mouse *mouse, t_fractal *fractal);
void	ft_draw_julia(t_img *img, t_fractal *julia);
void	ft_draw_mandelbrot(t_img *img, t_fractal *mandelbrot);
void	ft_set_and_put_colors_pixel(t_img *img, int x, int y, int i);
int		key_hook(int keycode, t_group *group);
int		ft_exit(int keycode, t_group *group);
int		mouse_hook(int mousecode, int x, int y, t_group *group);
#endif