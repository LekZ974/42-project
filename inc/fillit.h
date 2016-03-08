/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:28:20 by ahoareau          #+#    #+#             */
/*   Updated: 2016/03/08 11:24:25 by ggane            ###   ########.fr       */
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
	int					pos;
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
	int					p[3];
	struct s_tetri		*next;
	struct s_tetri		*prev;
}						t_tetri;

int						open_close(char *file);					// plateau.c
int						ft_sqrt(int nb);

void					display_square(t_list *list);	//display.c
void					ft_putchar(char c);

t_list					*create_list(void);						// list.c
t_tlist					*create_ttlist(void);						// list.c
t_list					*push_back(t_list *list, int position, char data);
void					list_delete(t_list **list);
void					ttlist_delete(t_tlist **list);
t_tlist					*append_tetri(t_tlist *list, int *data);
t_tetri					*create_link(int *data);

void					add_tetriminos(char *file, t_tlist *list2);	//tetri_check.c
void					print_tetriminos(t_tlist *list);

void					square_converter(t_tlist *list, int res);	//backtrack.c
int						non_present(t_node *elem, t_tetri *forme);
void					design_letters(t_node *tmp, t_tetri *forme, char letter);
int						backtracking(t_list *list1, t_tlist *list2, char letter);

void					affiche_coord(t_tlist *list); // tmp.c
#endif
