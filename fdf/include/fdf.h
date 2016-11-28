/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:34:31 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/28 17:53:42 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1000
# define HEIGHT 1000
# define INIT_X 400
# define INIT_Y 100

# include "../libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*win;

}					t_env;

typedef struct		s_tab
{
	int				xmax;
	int				ymax;
	int				z1;
	int				z2;
	int				zmax;
	int				zmid;
	int				zmin;
	int				coef;
	int				amp;
	int				rotx;
	int				roty;
	int				**input;
	t_point			**grid;
	t_point			pos;
}					t_tab;

typedef struct		s_data
{
	t_env			*e;
	t_tab			*tab;
}					t_data;

t_tab				*init_tab(void);
void				get_tab(char *file, t_tab *tab);
int					get_width(char *line);

t_env				*init_env(void);
void				data_handing(t_tab *tab);
void				get_min_max(t_tab *tab);

void				parse(t_tab *tab);

void				draw(t_env *e, t_tab *tab);

void				pixel_put1(t_env *e, t_point start, t_point end, \
		t_tab *tab);
void				pixel_put2(t_env *e, t_point start, t_point end, \
		t_tab *tab);
void				display_aff(t_env *e, t_tab *tab);
void				display_param(t_env *e);

void				handling(t_env *e, t_tab *tab);
int					key_funct(int keycode, t_data *data);
int					key_funct_2(int keycode, t_data *data);
int					ft_quit(t_env *e);
void				ft_erase(t_env *e);

int					ft_color(t_tab *tab);
int					get_level(int z1, int z2, t_tab *tab);

int					check(char *file);
int					valid_file(t_tab *tab, char *line);
#endif
