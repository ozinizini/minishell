CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./Libft -I./built_in

FUNC_SRC_BUILT_IN = ./built_in

LIB_BUILT_IN = ./built_in/built_in.a

FUNC_SRC_DIR = ./Libft

LIB = ./Libft/libft.a

SRCS =	./pipex_bonus.c\
		./utils_error_messages.c\
		./utils_memory_management.c\
		./utils_paths.c\
		./utils_processes.c\
		./utils_processes_bonus.c\
		./utils_heredoc_bonus.c\
		./utils_structs.c\
		./utils_file_descriptors.c\
		./utils_run_built_in.c\
		./prueba.c

OBJS = ${SRCS:.c=.o}

NAME = minishell

all: $(NAME)

$(NAME): $(LIB) $(LIB_BUILT_IN) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(LIB_BUILT_IN) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIB):
	make -C $(FUNC_SRC_DIR)

$(LIB_BUILT_IN):
	make -C $(FUNC_SRC_BUILT_IN)

clean:
	rm -f $(OBJS)
	@make -s clean -C $(FUNC_SRC_BUILT_IN)
	@make -s clean -C $(FUNC_SRC_DIR)

fclean: clean
	rm -f $(NAME)
	@make -s fclean -C $(FUNC_SRC_BUILT_IN)
	@make -s fclean -C $(FUNC_SRC_DIR)

re: fclean all

.PHONY: all clean fclean re
