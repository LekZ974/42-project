# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/12 15:37:33 by ahoareau          #+#    #+#              #
#    Updated: 2016/11/28 17:08:02 by ahoareau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -Wall -Wextra -Werror -g

SRC = ./src/main.c\
	  ./src/tab.c\
	  ./src/env.c\
	  ./src/parse.c\
	  ./src/draw.c\
	  ./src/pixel_put.c\
	  ./src/handling.c\
	  ./src/color.c\
	  ./src/check.c

OBJ = main.o\
	 tab.o\
	 env.o\
	 parse.o\
	 draw.o\
	 pixel_put.o\
	 handling.o\
	 color.o\
	 check.o

HEADER = ./include/fdf.h\
		 ./libft/libft.h

FINDLIBFT = -Llibft

LIBFTA = ./libft/libft.a

LIBFT_DIR = ./libft/

all : $(NAME)

$(NAME):
	@clear
	@echo "\033[35;4mRule all!\033[0m"
	@make fclean -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
	@$(CC) -c $(SRC) $(HEADER)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFTA) -lmlx -framework OpenGL -framework AppKit

clean :
	@clear
	@echo "\033[35;4mRule clean!\033[0m"
	@rm -f $(OBJ)
	@rm -f fdf.h.gch
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@clear
	@echo "\033[35;4mRule fclean!\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re : fclean all
	@clear
	@echo "\033[35;4mRule fclean!\033[0m"

.PHONY: all, clean, fclean, re
