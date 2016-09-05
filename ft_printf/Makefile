# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/22 16:00:10 by ahoareau          #+#    #+#              #
#    Updated: 2016/06/22 16:08:43 by ahoareau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CCFLAG = gcc -Wall -Wextra -Werror
SRC = ./src
INC = ./inc
OBJ =

all : $(NAME)

$(NAME):
	$(CCFLAG) -I$(INC) -c $(SRC)
	$(CCFLAG) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
