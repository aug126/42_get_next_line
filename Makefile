NAME=test_gnl
CFLAGS=-Wall -Wextra -Werror
SRC=rendu/get_next_line.c rendu/main.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C rendu/libft/
	gcc -o test_gnl $(OBJ) -L rendu/libft/ -lft

$(OBJ): %.o:%.c
	gcc $(CFLAGS) -I rendu/libft/includes/ -o $@ -c $<
clean: 
	make -C rendu/libft/ clean
	rm -rf $(OBJ)

fclean: clean 
	make -C rendu/libft/ fclean
	rm -rf $(NAME)
re: fclean
	make

.PHONY: re fclean clean all
