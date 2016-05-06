# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/29 10:07:34 by ahoareau          #+#    #+#              #
#    Updated: 2016/04/29 10:07:37 by ahoareau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -c -Wall -Wextra -Werror
SRC = *.c
HDR = libft.h
OBJ = *.o
NAME = libft.a

all:	$(NAME)

$(NAME):	
		$(CC) $(SRC)
		ar rc $(NAME) $(OBJ) 
		ranlib $(NAME)

clean:
		rm -rf $(OBJ) 

fclean:	clean
		rm -rf $(NAME)

re:	fclean all
