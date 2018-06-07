/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:23:41 by akorzhak          #+#    #+#             */
/*   Updated: 2018/03/04 14:23:33 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_ptr	p;
	pid_t   pid;

    pid = 1;
    if (argc >= 2 && define_fractal(argv[1], &p))
    {
	    init_fractal(&p);
	    p.mlx = mlx_init();
	    p.win = mlx_new_window(p.mlx, SIZE_X, SIZE_Y, "Fract'Ol");
	    draw_image(&p);
	    mlx_hook(p.win, 2, 5, handle_key, &p);
	    mlx_hook(p.win, 17, 5, exit_fdf, &p);
	    mlx_loop(p.mlx);
	}
	else
	    display_error_message(USAGE);
	return (0);
}
