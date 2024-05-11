NAME =	minishell
CC =	gcc
LIBFT =	./libft/libft.a
FLAGS =	-Wall -Wextra -Werror
HEADER = minishell.h
SRC =	parser.c parse_process.c ft_clean_quotes.c quotes.c ft_split_words.c\
		get_redir.c get_redir_type.c ft_split_process.c\
		expander.c get_expanded_len.c expander_utils.c main.c
OBJ =	$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ):$(SRC) $(HEADER)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	cd libft && make

clean:
	rm -f $(OBJ)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re