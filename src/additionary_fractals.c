/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionary_fractals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:07:09 by akorzhak          #+#    #+#             */
/*   Updated: 2018/06/25 06:07:12 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
