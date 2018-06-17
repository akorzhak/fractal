/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:16:49 by akorzhak          #+#    #+#             */
/*   Updated: 2018/02/18 14:16:51 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define SIZE_X 1000
# define SIZE_Y 1000
# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2

# define USAGE "Usage: ./fractol [mandelbrot/julia/burningship]\n"
# define WINDOW_ERROR "Error: Mlx window is failed to open.\n"

typedef struct		s_fractal
{
    double          z_squared;
    double          z_real;
    double          z_imag;
    double          c_real;
    double          c_imag;
    // double          c_real_step;
    // double          c_imag_step;
    double	    	min_real;
    double	    	max_real;
    double	    	min_imag;
    double		    max_imag;
    double          infinit_border;
}                   t_fractal;

typedef struct      s_color
{
    double          r_freq;
    double          g_freq;
    double          b_freq;
    double          r_phase;
    double          g_phase;
    double          b_phase;
    int             center;
    int             delta;
}                   t_color;

typedef struct		s_ptr
{
	int 			fract_name;
	void			*mlx;
	void			*win;
	void			*img;
	double			zoom;
	int				bpp;
	int				size_line;
	int				end;
    int             iter;
	int 			iter_max;
	char			*addr;
    t_color         col;

}					t_ptr;

int					main(int argc, char **argv);
void 				display_error_message(char *message);
void				display_message(char *message);
int					define_fractal(char *name, t_ptr *p);
void				init_fractal(t_fractal *f);
void                init_ptr(t_ptr *p);
void                draw_fractal(t_ptr *p, t_fractal *f);


#endif
