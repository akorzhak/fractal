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
	else
		return (0);
	return (1);
}

void		init_ptr(t_ptr *p)
{
	p->color = 0xFFFFFF;
	p->iter_max = 50;
	p->zoom = 1.0;
	p->img = mlx_new_image(p->mlx, SIZE_X, SIZE_Y);
    p->addr = mlx_get_data_addr(p->img, &(p->bpp), &(p->size_line), &(p->end));
    p->bpp /= 8;
}

void        init_fractal(t_fractal *f)
{
    f->min_real = -2.0;
    f->max_real = 1.0;
    f->min_imag = -1.2;
    f->max_imag = p->min_imag + (p->max_real - p->min_real) * SIZE_Y / SIZE_X;
    f->z_real = 0.0;
    f->z_imag = 0.0;
    f->c_real = f->min_real;
    f->c_imag = f->max_imag;
    f->infinit_border = 4.0;
    f->c_real_step = (f->max_real - f->min_real) / SIZE_X;
    f->c_imag_step = (f->max_imag - f->min_imag) / SIZE_Y;
}

// void 	init_mandelbrot(t_ptr *p)
// {
// 	p->min_real = -2.0;
// 	p->max_real = 1.0;
// 	p->min_imag = -1.2;
// 	p->max_imag = 1.0;

// }