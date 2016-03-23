/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:36:25 by ggane             #+#    #+#             */
/*   Updated: 2016/03/23 12:40:35 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 1
# define SIZE 16
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct			s_node
{
	char				data;
	int					position;
	int					cote;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef	struct			s_list
{
	struct s_node		*head;
	struct s_node		*tail;
}						t_list;

typedef	struct			s_tlist
{
	struct s_tetri		*head;
	struct s_tetri		*tail;
}						t_tlist;

typedef struct			s_tetri
{
	int					coordonnees[3];
	int					nb;
	int					position;
	char				letter;
	struct s_tetri		*next;
	struct s_tetri		*prev;
}						t_tetri;

int						open_close(char *file);
int						ft_sqrt(int nb);
t_list					*dessine_carre(t_list *list, int res);

void					display_square(t_list *list);
void					ft_putchar(char c);
void					ft_putstr(char *str);

t_list					*create_list(void);
t_tlist					*create_ttlist(void);
t_list					*push_back(t_list *list, int position,
						char data, int res);
void					list_delete(t_list **list);
void					ttlist_delete(t_tlist **list);
t_tlist					*append_tetri(t_tlist *list, int *data,
						int nb, char letter);
t_tetri					*create_link(int *data);

void					add_tetriminos(char *file, t_tlist *list2);
void					print_tetriminos(t_tlist *list);

void					square_converter(t_tlist *list, int cote1, int cote2);
int						est_dessinable(t_node *elem, t_tetri *forme, char c);
void					dessine_forme(t_node *tmp, t_tetri *forme, char letter);
int						backtracking(t_list *list, t_tlist *flist,
						t_node *tmp, t_tetri *forme);
t_node					*forme_prev(t_list *list, t_node *tmp, t_tetri *forme);
t_list					*carre_sup(t_list *list, t_tlist *flist);
void					table_rase(t_list *list, t_tetri *patron);

void					affiche_coord(t_tlist *list);

int						check_system_call(char *file);
int						check_file(char *file);
int						check_forme(char *schema);
void					check_cardinaux(char *str, int i, int *tab);
int						check_doublons(int *tab);
void					affiche_tab(int *doublon);

#endif
