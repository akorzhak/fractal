
#include "fractol.h"

void	put_description_to_window(t_ptr *p)
{
	mlx_string_put(p->mlx, p->win, 15, 5, 0xffffff, "fractal name: ");
	if (p->fract_name == MANDELBROT)
		mlx_string_put(p->mlx, p->win, 160, 5, 0xed1212, "MANDELBROT");
	else if (p->fract_name == JULIA)
		mlx_string_put(p->mlx, p->win, 160, 5, 0xed1212, "JULIA");
	else if (p->fract_name == BURNINGSHIP)
		mlx_string_put(p->mlx, p->win, 160, 5, 0xed1212, "BURNING SHIP");
	else if (p->fract_name == BUFFALO)
		mlx_string_put(p->mlx, p->win, 160, 5, 0xed1212, "BUFFALO");
	else if (p->fract_name == TRICORN)
		mlx_string_put(p->mlx, p->win, 160, 5, 0xed1212, "TRICORN");
	else if (p->fract_name == DROP)
		mlx_string_put(p->mlx, p->win, 160, 5, 0xed1212, "DROP");
	mlx_string_put(p->mlx, p->win, 15, 30, 0xffffff,
		"change fractal: J, B, F, T, D, M");
	mlx_string_put(p->mlx, p->win, 15, 55, 0xffffff, "change color: Enter");
	mlx_string_put(p->mlx, p->win, 15, 80, 0xffffff, "zoom: Mouse wheel");
	mlx_string_put(p->mlx, p->win, 15, 105, 0xffffff, "move: Arrows");
	mlx_string_put(p->mlx, p->win, 15, 130, 0xffffff, "change iterations: + / -");
	mlx_string_put(p->mlx, p->win, 15, 155, 0xffffff, "reset: Space");
	mlx_string_put(p->mlx, p->win, 15, 180, 0xffffff, "exit: Esc");
}