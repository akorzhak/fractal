/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:02:06 by akorzhak          #+#    #+#             */
/*   Updated: 2018/06/25 06:02:09 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		change_color1(t_ptr *p)
{
	if (p->col.variant == 2)
	{
		p->col.r_freq = 0.0002;
		p->col.g_freq = 0.012;
		p->col.b_freq = 0.00812;
		p->col.r_phase = 0.01;
		p->col.b_phase = 0.04;
		p->col.center = 200;
		p->col.variant = 3;
	}
	else
		init_color(p);
}

static void		change_color(t_ptr *p)
{
	if (p->col.variant == 0)
	{
		p->col.r_freq = 0.00002;
		p->col.g_freq = 0.006;
		p->col.b_freq = 0.000206;
		p->col.r_phase = 0.002;
		p->col.g_phase = 0.009;
		p->col.b_phase = 0.04;
		p->col.center = 430;
		p->col.delta = 2;
		p->col.variant = 1;
	}
	else if (p->col.variant == 1)
	{
		p->col.r_freq = 0.002;
		p->col.g_freq = 0.00003;
		p->col.b_freq = 0.0006;
		p->col.r_phase = 0.02;
		p->col.g_phase = 0.002;
		p->col.b_phase = 0.004;
		p->col.center = 830;
		p->col.variant = 2;
	}
	else
		change_color1(p);
}

static void		move_image(int key, t_ptr *p)
{
	if (key == 126)
	{
		(p->zoom >= 1) ? p->my -= 0.1 / p->zoom : 0;
		(p->zoom < 1) ? p->my -= 0.1 * p->zoom : 0;
	}
	else if (key == 125)
	{
		(p->zoom >= 1) ? p->my += 0.1 / p->zoom : 0;
		(p->zoom < 1) ? p->my += 0.1 * p->zoom : 0;
	}
	else if (key == 124)
	{
		(p->zoom >= 1) ? p->mx += 0.1 / p->zoom : 0;
		(p->zoom < 1) ? p->mx += 0.1 * p->zoom : 0;
	}
	else if (key == 123)
	{
		(p->zoom >= 1) ? p->mx -= 0.1 / p->zoom : 0;
		(p->zoom < 1) ? p->mx -= 0.1 * p->zoom : 0;
	}
}

static void		change_fractal(int key, t_ptr *p)
{
	key == 46 ? p->fract_name = MANDELBROT : 0;
	key == 38 ? p->fract_name = JULIA : 0;
	key == 3 ? p->fract_name = BUFFALO : 0;
	key == 17 ? p->fract_name = TRICORN : 0;
	key == 2 ? p->fract_name = DROP : 0;
	key == 11 ? p->fract_name = BURNINGSHIP : 0;
	init_fractal(p);
}

int				key_hook(int key, t_ptr *p)
{
	if (key == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	(key >= 2 && key <= 46) ? change_fractal(key, p) : 0;
	(key >= 123 && key <= 126) ? move_image(key, p) : 0;
	key == 36 ? change_color(p) : 0;
	key == 69 && p->iter_max < 500 ? p->iter_max += 20 : 0;
	key == 78 && p->iter_max > 30 ? p->iter_max -= 20 : 0;
	if (key == 49)
	{
		init_ptr(p);
		init_fractal(p);
	}
	draw_image(p);
	return (0);
}
