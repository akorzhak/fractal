/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:23:41 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:33 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(int x, int y, t_ptr *p)
{
	int		i;
	t_point	*ptr;

	ptr = p->point;
	if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y)
	{
		i = x * p->bpp + y * p->size_line;
		p->addr[i] = p->color;
		p->addr[++i] = p->color >> 8;
		p->addr[++i] = p->color >> 16;
	}
}

void	draw_mandelbrot(t_ptr *p)
{
	double x;
	double y;
	int i;

	y = 0;
	i = 0;
	while (y < SIZE_Y)
	{
		x = 0;
		while (x < SIZE_X)
		{
			while (i < p->iter_max)
			{
				
			}
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_ptr *p)
{
	p->img = mlx_new_image(p->mlx, SIZE_X, SIZE_Y);
	p->addr = mlx_get_data_addr(p->img, &(p->bpp), &(p->size_line), &(p->end));
	p->bpp /= 8;
	if (p->fractal == MANDELBROT)
		draw_mandelbrot(p);
	else if (p->fractal == JULIA)
		draw_julia(p);
	else
		draw_burningship(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}