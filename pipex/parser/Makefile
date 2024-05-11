NAME =	parser.a
CC =	gcc
INCLUDES = -I./Libft
FLAGS =	-Wall -Wextra -Werror
HEADER = minishell.h
SRC =	parser.c parse_process.c ft_clean_quotes.c quotes.c ft_split_words.c\
		get_redir.c get_redir_type.c ft_split_process.c\
		expander.c get_expanded_len.c expander_utils.c
OBJ =	$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re