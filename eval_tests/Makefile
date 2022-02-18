NAME = a.out

SRCS = 	../get_next_line.c

HDRS = ../get_next_line.h ../libft/libft.h

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) test_main.c $(SRCS) $(HDRS) ../libft/*.c

agane:
	rm a.out
	make all

