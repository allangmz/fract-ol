/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:00:00 by aguemazi          #+#    #+#             */
/*   Updated: 2022/05/28 14:30:33 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_set_and_put_colors_pixel2(t_img *img, int x, int y, int i)
{
	if (i > img->iteration_max / 2)
	{
		img->dest = img->addr + (y * img->line_length
				+ (x * (img->bits_per_pixel / 8)));
		*(unsigned int *)img->dest = (0x00FF00FF);
	}
	else if (i > img->iteration_max / 3)
	{
		img->dest = img->addr + (y * img->line_length
				+ (x * (img->bits_per_pixel / 8)));
		*(unsigned int *)img->dest = (0x00FFFF00);
	}
	else
	{
		img->dest = img->addr + (y * img->line_length
				+ (x * (img->bits_per_pixel / 8)));
		*(unsigned int *)img->dest = (0x0000FFFF);
	}
	return ;
}

void	ft_set_and_put_colors_pixel(t_img *img, int x, int y, int i)
{
	if (i == img->iteration_max)
	{
		img->dest = img->addr + (y * img->line_length
				+ (x * (img->bits_per_pixel / 8)));
		*(unsigned int *)img->dest = 0x0000000;
	}
	else if (i == img->iteration_max - 1)
	{
		img->dest = img->addr + (y * img->line_length
				+ (x * (img->bits_per_pixel / 8)));
		*(unsigned int *)img->dest = (0xFFFFFFF);
	}
	else
		ft_set_and_put_colors_pixel2(img, x, y, i);
	return ;
}
