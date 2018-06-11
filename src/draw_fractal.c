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

void	draw_pixel(t_ptr *p, t_fractal *f, int i)
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

void	draw_mandelbrot(t_ptr *p, t_fractal *f)
{
    int x;
    int y;
    int i;
    double temp;

	y = 0;
	while (y++ < SIZE_Y)
	{
		x = 0;
		f->c_real = f->min_real;
		while (x++ < SIZE_X)
		{
		    i = 0;
			while (i++ < p->iter_max &&
			(f->z_real * f->z_real + f->z_imag * f->z->imag) < f->infinit_border)
			{
			    temp = fabs(f->z_real * f->z_real - f->z_imag * f->z_imag + f->c_real);
                f->z_imag = fabs(2 * f->z_real * f->z_imag + f->c_imag);
                f->z_real = temp;
			}
			f->z_squared = f->z_real * f->z_real + f->z_imag * f->z->imag;
			draw_pixel(p, f, i);
			f->c_real += c_real_step;
		}
		f->c_imag -= c_imag_step;
	}
}

void	draw_fractal(t_ptr *p, t_fractal *f)
{
	if (p->fractal == MANDELBROT)
		draw_mandelbrot(p, f);
	else if (p->fractal == JULIA)
		draw_julia(p, f);
	else
		draw_burningship(p, f);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}