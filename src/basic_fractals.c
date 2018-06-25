/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:06:50 by akorzhak          #+#    #+#             */
/*   Updated: 2018/06/25 06:06:53 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	draw_julia(t_ptr *p)
{
	double temp;

	while ((p->iter)++ < p->iter_max &&
	(p->z_real * p->z_real + p->z_imag * p->z_imag) < p->infinit_border)
	{
		temp = p->z_real * p->z_real - p->z_imag * p->z_imag;
		p->z_imag = 2 * p->z_real * p->z_imag + p->j_imag;
		p->z_real = temp + p->j_real;
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
