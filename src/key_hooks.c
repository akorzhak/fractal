

#include "fractol.h"

static void 	change_color1(t_ptr *p)
{
	if (p->col.variant = 2)
	{
		p->col.r_freq = 0.3;
		p->col.g_freq = 0.3;
		p->col.b_freq = 0.3;
		p->col.r_phase = 2;
		p->col.g_phase = 0;
		p->col.b_phase = 4;
		p->col.variant = 3;
		p->col.center = 108;
		p->col.delta = 152;
	}
	else
		init_color(p);
}

static void		change_color(t_ptr *p)
{
	if (p->col.variant == 0)
	{
		p->col.r_phase = 1;
		p->col.g_phase = 2;
		p->col.b_phase = 4;
		p->col.variant = 1;
	}
	else if (p->col.variant = 1)
	{
		p->col.r_freq = 0.2;
		p->col.g_freq = 0.2;
		p->col.b_freq = 0.2;
		p->col.r_phase = 0;
		p->col.g_phase = 2;
		p->col.b_phase = 4;
		p->col.variant = 2;
	}
	else
		change_color1(p);
}

static void		move_image(int key, t_ptr *p)
{
	key == 126 ? p->my -= 0.1 * p->zoom : 0;
	key == 125 ? p->my += 0.1 * p->zoom : 0;
	key == 124 ? p->mx += 0.1 * p->zoom : 0;
	key == 123 ? p->mx -= 0.1 * p->zoom : 0;
}

static void		change_fractal(int key, t_ptr *p)
{
	key == 46 ? p->frac_name = MANDELBROT : 0;
	key == 38 ? p->frac_name = JULIA : 0;
	key == 3 ? p->frac_name = BUFFALO : 0; //f
	key == 17 ? p->frac_name = TRICORN : 0;
	key == 2 ? p->frac_name = DROP : 0;
	key == 11 ? p->frac_name = BURNINGSHIP : 0;
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
	key == 56 ? change_color(p) : 0; //enter
	key == 69 && p->iter_max < 500 ? p->iter_max += 1 : 0;
	key == 78 && p->iter_max > 30 ? p->iter_max -= 1 : 0;
	draw_image(p);
	return (0);
}
