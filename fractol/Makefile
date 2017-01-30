# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahoareau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 10:26:45 by ahoareau          #+#    #+#              #
#    Updated: 2016/12/19 12:59:46 by ahoareau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FRACTOL

CC = gcc -Wall -Wextra -Werror -g

SRC = ./src/main.c\
	  ./src/env.c\
	  ./src/handling.c\
	  ./src/fractal.c\
	  ./src/mandelbrot.c

OBJ = main.o\
	  env.o\
	  handling.o\
	  fractal.o\
	  mandelbrot.o

HEADER = ./include/fractol.h\
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
	@rm -f /include/fractol.h.gch
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
