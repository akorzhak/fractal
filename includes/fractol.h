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

# define SIZE_X 1700
# define SIZE_Y 1200
# define MANDELBROT 0
# define JULIA 1
# define BURNINGSHIP 2

# define USAGE "Usage: /fractol [mandelbrot/julia/burningship]\n"

typedef struct		s_fractal
{
	long double		min_real;
	long double		max_real;
	long double		min_imag;
	long double		max_imag;
	long double		z_real;
	long double		z_imag;
	long double		c_real;
	long double		c_imag;
}					t_fractal;

typedef struct		s_ptr
{
	int 			fract_name;
	void			*mlx;
	void			*win;
	void			*img;
	int				zoom;
	int				bpp;
	int				size_line;
	int				end;
	int 			iter_max;
	int				color;
	char			*addr;
	double			x;
	double			y;
	t_fractal		*fractal;
}					t_ptr;

int					ft_error(void);
int					ft_usage(void);
void				initialize_ptr(t_ptr *p);
void				add_point(t_point **point, t_point *new);
t_point				*create_point(int x, int y, char *z, t_ptr *p);
void				center_map(t_ptr *p);
void				rotate_map(t_point *ptr, t_ptr *p);
void				project_map(t_point *ptr, t_ptr *p);
void				draw_image(t_ptr *p);
void				connect_dots(t_dot *d, t_ptr *p);
void				draw_pixel(int x, int y, t_ptr *p);
int					handle_key(int keycode, t_ptr *p);
int					exit_fdf(t_ptr *p);

#endif
