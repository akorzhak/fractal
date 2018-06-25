/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:06:11 by akorzhak          #+#    #+#             */
/*   Updated: 2018/06/25 06:31:46 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	open_window(t_ptr *p)
{
	p->win = mlx_new_window(p->mlx, SIZE_X, SIZE_Y, "Fract'ol");
	if (p->win == NULL)
		display_error_message("Error: Mlx window is failed to open.\n");
}

int		main(int argc, char **argv)
{
	t_ptr p;

	if (argc >= 2 && define_fractal(argv[1], &p))
	{
		init_ptr(&p);
		init_fractal(&p);
		open_window(&p);
		draw_image(&p);
		mlx_hook(p.win, 2, 5, key_hook, &p);
		mlx_mouse_hook(p.win, mouse_hook, &p);
		mlx_hook(p.win, 6, 5, julia_vary, &p);
		mlx_hook(p.win, 17, 5, exit_x, &p);
		mlx_loop(p.mlx);
	}
	else
	{
		display_error_message("Usage: ./fractol\
		[mandelbrot/julia/burningship/buffalo/tricorn/drop]\n");
	}
	return (0);
}
