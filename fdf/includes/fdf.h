/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:15:56 by ahoareau          #+#    #+#             */
/*   Updated: 2016/11/06 18:00:37 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIDTH 1000
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
	int				i;
	int				j;
	int				itmp;
	int				jtmp;
	int				**tab;
}					t_tab;

typedef	struct		s_coord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				***coord;
}					t_coord;

/*typedef struct		s_color
{
	int				color1;
	int				color2;
	int				**color;
}					t_color;
*/
typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*file;
	int				level;
	int				coef;
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
void	get_coord(t_env *e);

t_env	*get_tab(t_env *e);
void	tab_line(t_env *e, int fd);
void	get_int(int i, t_env *e, char *line);
int		count(char *line);
void	mall_tab(int fd, t_env *e);

void	pixel_put1(t_env *e);
void	pixel_put2(t_env *e);
void	pixel_put3(t_env *e);
void	pixel_put4(t_env *e);

void	join(t_env *e);
void	draw_pos(t_env *e, int x, int y);
void	draw(t_env *e);
void	coord_h(t_env *e, int x, int y);
void	coord_v(t_env *e, int x, int y);

int		key_funct(int keycode, t_env *e);
int		key_funct2(int keycode, t_env *e);

void	disp_window(t_env *e);
void	disp_limit(t_env *e);
void	display_param(t_env *e);
void	erase(t_env *e);

int		ft_color(t_env *e);

#endif
