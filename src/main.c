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

void	open_window(t_ptr *p)
{
	p->win = mlx_new_window(p->mlx, SIZE_X, SIZE_Y, "Fract'ol");
	if (p->win == NULL)
		display_error_message(WINDOW_ERROR);
}

int		main(int argc, char **argv)
{
	t_ptr	    p;
//	t_fractal   f;
//	pid_t   pid;

 //   pid = 1;
    if (argc >= 2 && define_fractal(argv[1], &p))
    {
        init_ptr(&p);
	    init_fractal(&p);
	    open_window(&p);
	    draw_image(&p);
		mlx_hook(p.win, 2, 5, key_hook, &p);
		mlx_mouse_hook(p.win, mouse_hook, &p);
		mlx_hook(p.win, 6, 5, mouse_mot, &p);
		mlx_hook(t.m.win, 17, 5, exit_x, &p);
	    mlx_loop(p.mlx);
	}
	else
	    display_error_message(USAGE);
	return (0);
}
