/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:15:56 by ahoareau          #+#    #+#             */
/*   Updated: 2016/09/05 18:28:15 by ahoareau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct		s_tab
{
	int				x;	//position affichage colonne
	int				y;	//position affichage ligne
	int				i;  //nb de lignes
	int				j;	//nb de colonnes
	int				**tab;
}					t_tab;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				coef;	//coef d'affichage
	t_tab			tab;
}					t_env;

int 	check(char *file);
char 	*fill_str(char *file);
int		fdf(char *str);

int		exist_file(char *file);
int		check_file(char *str);

void	get_tab(char *str, t_env *env);
void	get_int(int i, t_env *env, char *line);
int		count(char *line);

void	pixel_put(t_env *env);

int		key_funct(int keycode, t_env *env);

#endif
