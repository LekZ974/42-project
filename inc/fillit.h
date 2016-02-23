/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:28:20 by ahoareau          #+#    #+#             */
/*   Updated: 2016/02/23 17:01:19 by ahoareau         ###   ########.fr       */
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

typedef struct			s_tetri
{
	char				tetriminos[21];
	struct s_tetri		*next;
	struct s_tetri		*prev;
}						t_tetri;

int						open_close(char *file);					// plateau.c
int						ft_sqrt(int nb);

void					display_square(t_list *list, int res);	//display.c
void					ft_putchar(char c);

t_list					*create_list(void);						// list.c
t_list					*push_back(t_list *list, int position);
void					list_delete(t_list **list);

#endif
