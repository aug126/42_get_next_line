NAME=test_gnl
CFLAGS=#-Wall -Wextra -Werror
SRC=rendu/get_next_line.c main.c
OBJ=$(SRC:.c=.o)

all: libft $(NAME)

libft: 
	make -C rendu/libft/

$(NAME): $(OBJ) ./rendu/libft/libft.a
	gcc -o test_gnl $(OBJ) -L rendu/libft/ -lft
$(OBJ): %.o:%.c rendu/get_next_line.h
	gcc $(CFLAGS) -I rendu/libft/includes/ -I rendu/ -o $@ -c $<
rendu/get_next_line.h:
clean:
	make -C rendu/libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C rendu/libft/ fclean
	rm -rf $(NAME)
re: fclean
	make

.PHONY: re fclean clean all

test:
	@./test_gnl file1.txt

.PHONY: test
