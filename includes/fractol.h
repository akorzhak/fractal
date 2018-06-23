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

# define SIZE_X 1200
# define SIZE_Y 900
# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2
# define BUFFALO 3
# define DROP 4
# define TRICORN 5

# define USAGE "Usage: ./fractol [mandelbrot/julia/burningship]\n"
# define WINDOW_ERROR "Error: Mlx window is failed to open.\n"

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
    double          z_real;
    double          z_imag;
    double          c_real;
    double          c_imag;
    double          min_real;
    double          max_real;
    double          min_imag;
    double          max_imag;
    double          infinit_border;

}					t_ptr;

int					main(int argc, char **argv);
void 				display_error_message(char *message);
void				display_message(char *message);
int					define_fractal(char *name, t_ptr *p);
void                init_fractal(t_ptr *p);
void                init_ptr(t_ptr *p);
void                draw_image(t_ptr *p);
void                init_factors(int x, int y, t_ptr *p);


#endif
