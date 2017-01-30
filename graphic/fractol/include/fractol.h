/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:34:04 by ahoareau          #+#    #+#             */
/*   Updated: 2016/12/18 20:42:15 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# include "../libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct		s_comp
{
	double			r;
	double			i;
}					t_comp;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_color
{
	int				color_def;
	int				color00;
	int				color01;
	int				color02;
	int				color03;
	int				color04;
	int				color05;
	int				color06;
	int				color07;
	int				color08;
	int				color09;
}					t_color;

typedef struct		s_frac
{
	t_comp			z;
	t_comp			c;
	double			itmax;
	double			it;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;
	double			tmp;
	void			*func;
}					t_frac;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl_img;
	int				bpp;
	int				sizeline;
	int				endian;
	void			(*fractal)();
	t_color			*color;
}					t_env;

typedef struct		s_data
{
	t_env			*e;
	t_frac			*frac;
}					t_data;

t_env				*init_env(void);

t_frac				*init_frac(void);

void				handling(t_env *e, t_frac *frac);
int					key_funct(int keycode, t_data *data);

void				ft_draw_fractal(t_env *e, t_frac *frac);

#endif
