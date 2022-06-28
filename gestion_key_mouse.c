/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_key_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:04:31 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/30 14:15:34 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_group *group)
{
	if (mousecode == 5)
	{
		group->mouse->x = x;
		group->mouse->y = y;
		group->img->zoom += group->img->zoom;
		group->img->iteration_max += 0.1 * group->img->iteration_max;
		ft_draw_fractal(group->win, group->img, group->mouse, group->fractal);
	}
	if (mousecode == 4)
	{
		group->mouse->x = x;
		group->mouse->y = y;
		group->img->zoom *= 0.5;
		group->img->iteration_max -= 0.1 * group->img->iteration_max;
		ft_draw_fractal(group->win, group->img, group->mouse, group->fractal);
	}
	return (0);
}

int	ft_exit(int keycode, t_group *group)
{
	exit(0);
}

void	ft_key_move(int keycode, t_group *group)
{
	if (keycode == 124)
		group->fractal->x1 += 10 / group->img->zoom;
	if (keycode == 123)
		group->fractal->x1 -= 10 / group->img->zoom;
	if (keycode == 125)
		group->fractal->y1 += 10 / group->img->zoom;
	if (keycode == 126)
		group->fractal->y1 -= 10 / group->img->zoom;
	return ;
}

int	key_hook(int keycode, t_group *group)
{
	if (keycode == 53)
	{
		mlx_destroy_image(group->win->mlx, group->img->img);
		mlx_destroy_window(group->win->mlx, group->win->win);
		exit(0);
	}
	if (keycode <= 126 && keycode >= 123)
		ft_key_move(keycode, group);
	if (keycode == 69)
		group->img->iteration_max += 0.5 * group->img->iteration_max;
	if (keycode == 78 && group->img->iteration_max > 4)
		group->img->iteration_max -= 0.5 * group->img->iteration_max;
	if (keycode == 0)
		group->fractal->variable1 += 0.01;
	if (keycode == 2)
		group->fractal->variable1 -= 0.01;
	if (keycode == 13)
		group->fractal->variable2 += 0.01;
	if (keycode == 1)
		group->fractal->variable2 -= 0.01;
	ft_draw_fractal(group->win, group->img, group->mouse, group->fractal);
	return (0);
}
