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
	p->mlx = mlx_init();
	p->img = mlx_new_image(p->mlx, SIZE_X, SIZE_Y);
    p->addr = mlx_get_data_addr(p->img, &(p->bpp), &(p->size_line), &(p->end));
    p->bpp /= 8;
    p->iter_max = 100;
	p->zoom = 1.0;
    init_color(p);
}

void	init_fractal(t_ptr *p)
{
	if (p->fract_name == MANDELBROT)
	{
    	p->max_real = 1.1;
    	p->min_imag = -1.2;
    }
    else if (p->fract_name == BURNINGSHIP)
    {
    	p->max_real = 1.0;
    	p->min_imag = -1.6;
    }
    else
    {
    	p->max_real = 2.6;
    	p->min_imag = -2.0;
    }
    p->min_real = -2.1;
    p->max_imag = p->min_imag + (p->max_real - p->min_real) * SIZE_Y / SIZE_X;
    p->infinit_border = 4.0;
}

void	init_factors(int x, int y, t_ptr *p)
{
	
	p->iter = 0;
	if (p->fract_name == JULIA)
	{
		p->c_imag = 0.27015;
		p->c_real = -0.7;
		p->z_real = 1.5 * (x - SIZE_X / 2) / (0.5 * p->zoom * SIZE_X);
        p->z_imag = 1.0 * (y - SIZE_Y / 2) / (0.5 * p->zoom * SIZE_Y);
	}
	else
	{	p->c_imag = p->max_imag - y * (p->max_imag - p->min_imag) / (SIZE_Y - 1);
		p->c_real = p->min_real + x * (p->max_real - p->min_real) / (SIZE_X - 1);
		p->z_real = p->c_real;
		p->z_imag = p->c_imag;
	}
}