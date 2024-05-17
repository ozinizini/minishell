NAME =	parser.a
CC =	gcc
INCLUDES = -I./Libft -I$(HOME)/.brew/opt/readline/include
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lreadline -L$(HOME)/.brew/opt/readline/lib
HEADER = minishell.h
SRC =	parser.c parse_process.c ft_clean_quotes.c quotes.c ft_split_words.c\
		get_redir.c get_redir_type.c ft_split_process.c ft_check_syntax.c\
		expander.c get_expanded_len.c expander_utils.c check_empty.c signals.c
OBJ =	$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME)  $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re