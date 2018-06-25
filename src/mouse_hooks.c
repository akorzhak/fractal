/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 05:52:07 by akorzhak          #+#    #+#             */
/*   Updated: 2018/06/25 05:52:16 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	define_interpolation(int button, t_ptr *p)
{
	if ((button == 1 || button == 4) && p->zoom < 320)
	{
		p->zoom++;
		return (0.9);
	}
	else if (button == 2 || button == 5)
	{
		p->zoom--;
		return (1.1);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_ptr *p)
{
	double m_re;
	double m_im;
	double interpolation;

	if ((x > 0 && y > 0 && x < SIZE_X && y < SIZE_Y) &&
		(button == 1 || button == 2 || button == 4 || button == 5))
	{
		interpolation = define_interpolation(button, p);
		if (interpolation)
		{
			m_im = p->max_imag - y * (p->max_imag - p->min_imag) / (SIZE_Y - 1);
			m_re = p->min_real + x * (p->max_real - p->min_real) / (SIZE_X - 1);
			p->min_real = m_re + ((p->min_real - m_re) * interpolation);
			p->max_real = m_re + ((p->max_real - m_re) * interpolation);
			p->min_imag = m_im + ((p->min_imag - m_im) * interpolation);
			p->max_imag = m_im + ((p->max_imag - m_im) * interpolation);
		}
		draw_image(p);
	}
	return (0);
}

int		julia_vary(int x, int y, t_ptr *p)
{
	if ((x > 0 && y > 0 && x < SIZE_X && y < SIZE_Y) && p->fract_name == JULIA)
	{
		p->j_real = (double)x / SIZE_X * 4 - 2;
		p->j_imag = (double)y / SIZE_Y * 4 - 2;
		draw_image(p);
	}
	return (0);
}

int		exit_x(t_ptr *p)
{
	p = NULL;
	exit(0);
	return (0);
}
