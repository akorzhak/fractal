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

void		init_fractal(t_ptr *p)
{
	p->color = 0xFFFFFF;
	p->iter_max = 50;

	if (p->fract_name == MANDELBROT)
		init_mandelbrot(p);
	else if (p->fract_name == JULIA)
		init_julia(p);
	else if (p->fract_name == BURNINGSHIP)
		init_burningship(p);
}

void 	init_mandelbrot(t_ptr *p)
{
	p->min_real = -2.0;
	p->max_real = 1.0;
	p->min_imag = -1.2;
	p->max_imag = 

}