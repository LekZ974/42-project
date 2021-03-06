#!/bin/sh

make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang  -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
echo "\n\t----------test 1----------\n"
echo "\t3 lignes simples\n"
./test_gnl "1"
echo "\n\t----------test 2----------\n"
echo "\t5 newlines d'affilee\n"
./test_gnl "2"
echo "\n\t----------test 3----------\n"
echo "\t1 ligne suivie d'une newline\n"
./test_gnl "3"
echo "\n\t----------test 4----------\n"
echo "\ttexte entier du preambule de gnl\n"
./test_gnl "4"
echo "\n\t----------test 5----------\n"
echo "\t1 ligne simple\n"
./test_gnl "5"
echo "\n\t----------test 6----------\n"
echo "\t4 lignes simples\n"
./test_gnl "6"
echo "\n\t----------test 7----------\n"
#echo "\t1 ligne tres longue\n"
#./test_gnl "7"
echo "\n\t----------test 8----------\n"
echo "\t4 lignes avec deux newlines au milieu\n"
./test_gnl "8"
echo "\n\t----------test 9----------\n"
echo "\t1 ligne simple\n"
./test_gnl "9"
echo "\n\t----------test 10---------\n"
echo "\ttest avec fd = -1\n"
./test_gnl "10"
echo "\n\t----------test 11---------\n"
echo "\t1 ligne simple\n"
./test_gnl "11"
echo "\n\t----------test 12---------\n"
echo "\ttests complets et consecutifs\n"
echo "\tde deux fichiers close avant de\n"
echo "\tpasser de l'un a l'autre\n"
echo "\t               -            \n"
./test_gnl "12"
echo "\n\t----------test 13---------\n"
echo "\ttest sur un dossier\n"
./test_gnl "13"
echo "\n\t----------test 14---------\n"
echo "\tappel une fois de gnl sur\n"
echo "\tdeux fichiers differents\n"
echo "\tsans avoir close le 1er avant\n"
echo "\tde passer au second\n"
echo "\t               -            \n"
./test_gnl "14"
echo "\n\t----------test 15---------\n"
./test_gnl "15"
rm -rf *.o test_gnl
