make -C libft/ fclean && make -C libft/

clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft


echo ----- test 2 -----
./test_gnl "2"

echo ----- test 3 -----
./test_gnl "3"

echo ----- test 4 -----
./test_gnl "4"

echo ----- test 5 -----
./test_gnl "5"
