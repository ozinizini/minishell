NAME = built_in.a
CC = gcc -c
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./Libft

SOURCES = built_in_error_messages.c built_in_utils.c env_variable_string_functions.c export_variables_functions.c ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean