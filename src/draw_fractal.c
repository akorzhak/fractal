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
	double	zn;
	double	index;

	if (x < 0 || x >= SIZE_X || y < 0 || y >= SIZE_Y)
		return ;
	i = x * p->bpp + y * p->size_line;
	if (p->iter < p->iter_max)
	{
		zn = sqrt(p->z_real * p->z_real + p->z_imag * p->z_imag);
		index = p->iter + 1 - (log(2) / zn) / log(2);
		p->addr[i] = sin(p->col.b_freq * index + p->col.b_phase)
					* p->col.center * p->col.delta;
		p->addr[++i] = sin(p->col.g_freq * index + p->col.g_phase)
					* p->col.center * p->col.delta;
		p->addr[++i] = sin(p->col.r_freq * index + p->col.r_phase)
					* p->col.center * p->col.delta;
	}
	else
	{	
		p->addr[i] = 0;
		p->addr[++i] = 0;
		p->addr[++i] = 0;
	}
}

void	draw_tricorn(t_ptr *p)
{
	double temp;

	while ((p->iter)++ < p->iter_max &&
	(p->z_real * p->z_real + p->z_imag * p->z_imag) < p->infinit_border)
	{
		temp = p->z_real * p->z_real - p->z_imag * p->z_imag + p->c_real;
        p->z_imag = -2 * p->z_real * p->z_imag + p->c_imag;
        p->z_real = temp;
	}
}

void	draw_buffalo(t_ptr *p)
{
	double temp;

	while ((p->iter)++ < p->iter_max &&
	(p->z_real * p->z_real + p->z_imag * p->z_imag) < p->infinit_border)
	{
		temp = fabs(p->z_real * p->z_real - p->z_imag * p->z_imag + p->c_real);
        p->z_imag = fabs(2 * p->z_real * p->z_imag - p->z_imag + p->c_imag);
        p->z_real = temp;
	}
}

void	draw_drop(t_ptr *p)
{
	double temp;

	while ((p->iter)++ < p->iter_max &&
	(p->z_real * p->z_real + p->z_imag * p->z_imag) < p->infinit_border)
	{
		temp = p->z_real * p->z_real - p->z_imag * p->z_imag + p->c_real /
				(p->c_real * p->c_real + p->c_imag * p->c_imag);
        p->z_imag = 2 * p->z_real * p->z_imag - p->c_imag /
        		(p->c_real * p->c_real + p->c_imag * p->c_imag);
        p->z_real = temp;
	}
}

void	draw_julia(t_ptr *p)
{
	double temp;

	while ((p->iter)++ < p->iter_max &&
	(p->z_real * p->z_real + p->z_imag * p->z_imag) < p->infinit_border)
	{
		temp = p->z_real * p->z_real - p->z_imag * p->z_imag;
        p->z_imag = 2 * p->z_real * p->z_imag + p->c_imag;
        p->z_real = temp + p->c_real;
	}
}

void	draw_mandelbrot(t_ptr *p)
{
	double temp;

	while ((p->iter)++ < p->iter_max &&
	(p->z_real * p->z_real + p->z_imag * p->z_imag) < p->infinit_border)
	{
		temp = p->z_real * p->z_real - p->z_imag * p->z_imag + p->c_real;
        p->z_imag = 2 * p->z_real * p->z_imag + p->c_imag;
        p->z_real = temp;
	}
}

void	draw_burningship(t_ptr *p)
{
    double temp;

	while ((p->iter)++ < p->iter_max &&
	(p->z_real * p->z_real + p->z_imag * p->z_imag) < p->infinit_border)
	{
		temp = p->z_imag;
        p->z_imag = fabs(2 * p->z_real * p->z_imag + p->c_imag);
        p->z_real = fabs(p->z_real * p->z_real - temp * temp + p->c_real);
	}	
}

void	draw_fractal(t_ptr *p)
{
    int x;
    int y;

	y = 0;
	while (y++ < SIZE_Y)
	{
		x = 0;
		while (x++ < SIZE_X)
		{
			init_factors(x, y, p);
		    if (p->fract_name == MANDELBROT)
		    	draw_mandelbrot(p);
		    else if (p->fract_name == BURNINGSHIP)
		    	draw_burningship(p);
		    else if (p->fract_name == JULIA)
		    	draw_julia(p);
		    else if (p->fract_name == BUFFALO)
		    	draw_buffalo(p);
		    else if (p->fract_name == DROP)
		    	draw_drop(p);
		    else if (p->fract_name == TRICORN)
		    	draw_tricorn(p);
			draw_pixel(x, y, p);
		}		
	}
}

void	draw_image(t_ptr *p)
{
	draw_fractal(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}