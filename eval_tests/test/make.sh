
clang  -I libft/includes -o ../get_next_line.o -c ../get_next_line.c
clang  -I libft/includes -o main.o -c test/main.c
clang -o test_gnl main.o ../get_next_line.o -I libft/includes -L ../../libft/ -lft
#rm main.o
#rm get_next_line.o
