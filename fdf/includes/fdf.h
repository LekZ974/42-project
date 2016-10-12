/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:15:56 by ahoareau          #+#    #+#             */
/*   Updated: 2016/10/11 16:21:40 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIDTH 2000
#define	HEIGHT 1000

# include "../libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct		s_tab
{
	int				cx;	//position affichage colonne
	int				cy;	//position affichage ligne
	int				i;  //nb de lignes
	int				j;	//nb de colonnes
	int				itmp;
	int				jtmp;
	int				**tab;
}					t_tab;

typedef	struct		s_coord
{
	int				x;
	int				y;
	int				x2;
	int				y2;
	int				***coord;
}					t_coord;

//typedef struct		s_color
//{
//	int				color1;
//	int				color2;
//	int				**color;
//}

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int	coef;	//coef d'affichage
	int				amp;
	int				x_origin;
	int				y_origin;
	int				ang;
	t_tab			tab;
	t_coord			coord;
//	t_color			color;
}					t_env;

int 	check(char *file);
char 	*fill_str(char *file);
int		fdf(char *str);

int		exist_file(char *file);
int		check_file(char *str);

void	mall_coord(t_env *e);
void	get_coord(t_env *e, int x, int y);

t_env	*get_tab(char *str, t_env *e);
void	tab_line(t_env *e, int fd);
void	get_int(int i, t_env *e, char *line);
int		count(char *line);
void	mall_tav(int fd, t_env *e);

void	pixel_put_r(t_env *e, int x, int x2, int y, int y2);
void	pixel_put_l(t_env *e, int x, int x2, int y, int y2);
void	pixel_put_u(t_env *e, int x, int x2, int y, int y2);
void	pixel_put_d(t_env *e, int x, int x2, int y, int y2);

void	draw_line(t_env *e, int x1, int x2, int y1, int y2);
void	draw_pos_h(t_env *e, int x, int y);
void	draw_pos_v(t_env *e, int x, int y);
void	draw(t_env *e);

int		key_funct(int keycode, t_env *e);

void	disp_window(t_env *e);
int		disp_point_x(t_env *e, int coord);
int		disp_point_y(t_env *e, int coord);
void	erase(t_env *e);

#endif
