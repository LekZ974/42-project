/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:28:20 by ahoareau          #+#    #+#             */
/*   Updated: 2016/03/18 00:40:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

# define BUF_SIZE 1
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

int						open_close(char *file);					// plateau.c
int						ft_sqrt(int nb);
t_list					*dessine_carre(t_list *list, int res);

void					display_square(t_list *list);	//display.c
void					ft_putchar(char c);
void					ft_putstr(char *str);

t_list					*create_list(void);						// list.c
t_tlist					*create_ttlist(void);
t_list					*push_back(t_list *list, int position, char data, int res);
void					list_delete(t_list **list);
void					ttlist_delete(t_tlist **list);
t_tlist					*append_tetri(t_tlist *list, int *data, int nb, char letter);
t_tetri					*create_link(int *data);

void					add_tetriminos(char *file, t_tlist *list2);	//tetri_check.c
void					print_tetriminos(t_tlist *list);

void					square_converter(t_tlist *list, int cote1, int cote2);	//backtrack.c
int						Est_Dessinable(t_node *elem, t_tetri *forme, char c);
void					Dessine_Forme(t_node *tmp, t_tetri *forme, char letter);
int						backtracking(t_list *list, t_tlist *flist, t_node *tmp, t_tetri *forme);
t_node					*Forme_Prev(t_list *list, t_node *tmp, t_tetri *forme);
t_list					*Carre_Sup(t_list *list, t_tlist *flist);
void					Table_Rase(t_list *list, t_tetri *patron);

void					affiche_coord(t_tlist *list); // tmp.c

int						check_system_call(char *file); //check.c
int						check_file(char *file);
int						check_forme(char *schema);
#endif
