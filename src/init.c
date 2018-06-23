/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:23:41 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:33 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		define_fractal(char *name, t_ptr *p)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		p->fract_name = MANDELBROT;
	else if (ft_strcmp(name, "julia") == 0)
		p->fract_name = JULIA;
	else if (ft_strcmp(name, "burningship") == 0)
		p->fract_name = BURNINGSHIP;
	else if (ft_strcmp(name, "buffalo") == 0)
		p->fract_name = BUFFALO;
	else if (ft_strcmp(name, "drop") == 0)
		p->fract_name = DROP;
	else if (ft_strcmp(name, "tricorn") == 0)
		p->fract_name = TRICORN;
	else
		return (0);
	return (1);
}

void	init_color(t_ptr *p)
{
	p->col.r_freq = 0.01;
	p->col.g_freq = 0.013;
	p->col.b_freq = 0.016;
	p->col.r_phase = 0.1;
	p->col.g_phase = 0.2;
	p->col.b_phase = 0.4;
	p->col.center = 230;
	p->col.delta = 25;
}

void	init_ptr(t_ptr *p)
{
	p->iter_max = 100;
	p->zoom = 1.0;
	p->img = mlx_new_image(p->mlx, SIZE_X, SIZE_Y);
    p->addr = mlx_get_data_addr(p->img, &(p->bpp), &(p->size_line), &(p->end));
    p->bpp /= 8;
    init_color(p);
}

void	init_fractal(t_fractal *f, t_ptr *p)
{
	if (p->fract_name == MANDELBROT)
	{
    	f->max_real = 1.1;
    	f->min_imag = -1.2;
    }
    else if (p->fract_name == BURNINGSHIP)
    {
    	f->max_real = 1.0;
    	f->min_imag = -1.6;
    }
    else
    {
    	f->max_real = 2.6;
    	f->min_imag = 2.0;
    }
    f->min_real = -2.1;
    f->max_imag = f->min_imag + (f->max_real - f->min_real) * SIZE_Y / SIZE_X;
    f->infinit_border = 4.0;
}

void	init_factors(int x, int y, t_ptr *p, t_fractal *f)
{
	f->c_imag = f->max_imag - y * (f->max_imag - f->min_imag) / (SIZE_Y - 1);
	f->c_real = f->min_real + x * (f->max_real - f->min_real) / (SIZE_X - 1);
	p->iter = 0;
	f->z_real = f->c_real;
	f->z_imag = f->c_imag;
}