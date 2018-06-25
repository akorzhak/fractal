#include "fractol.h"

double 		define_interpolation(int button, t_ptr *p)
{
	if ((button == 1 || button == 4) && p->zoom < 320)
	{
		p->zoom++;
		return (0.9);
	}
	else if (button == 2 || button == 5)
	{
		p->zoom--;
		return (1.1);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_ptr *p)
{
	double m_real;
	double m_imag;
	double interpolation;

	if ((x > 0 && y > 0 && x < SIZE_X && y < SIZE_Y) &&
		(button == 1 || button == 2 || button == 4 || button == 5))
	{
		interpolation = define_interpolation(button, p);
		if (interpolation)
		{
			m_imag = p->max_imag - y * (p->max_imag - p->min_imag) / (SIZE_Y - 1);
			m_real = p->min_real + x * (p->max_real - p->min_real) / (SIZE_X - 1);
			p->min_real = m_real + ((p->min_real - m_real) * interpolation);
			p->max_real = m_real + ((p->max_real - m_real) * interpolation);
			p->min_imag = m_imag + ((p->min_imag - m_imag) * interpolation);
			p->max_imag = m_imag + ((p->max_imag - m_imag) * interpolation);
		}
		draw_image(p);
	}
	return (0);
}

int 	julia_vary(int x, int y, t_ptr *p)
{
	if ((x > 0 && y > 0 && x < SIZE_X && y < SIZE_Y) && p->fract_name == JULIA)
	{
		p->j_real = (double)x / SIZE_X * 4 - 2;
		p->j_imag = (double)y / SIZE_Y * 4 - 2;
		draw_image(p);
	}
	return (0);
}
