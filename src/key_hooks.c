

#include "fractol.h"

int				key_hook(int keycode, t_ptr *p)
{
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
//	draw_image(p);
	return (0);
}