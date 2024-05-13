CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./Libft -I./built_in -I./parser
LDFLAGS = -lreadline

FUNC_SRC_BUILT_IN = ./built_in

LIB_BUILT_IN = ./built_in/built_in.a

FUNC_SRC_PARSER = ./parser

LIB_PARSER = ./parser/parser.a

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
		./utils_env_export_lists.c\
		./readline_test.c

OBJS = ${SRCS:.c=.o}

NAME = minishell

all: $(NAME)

$(NAME): $(LIB) $(LIB_BUILT_IN) $(LIB_PARSER) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB) $(LIB_BUILT_IN) $(LIB_PARSER) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIB_PARSER):
	make -C $(FUNC_SRC_PARSER)

$(LIB):
	make -C $(FUNC_SRC_DIR)

$(LIB_BUILT_IN):
	make -C $(FUNC_SRC_BUILT_IN)

clean:
	rm -f $(OBJS)
	@make -s clean -C $(FUNC_SRC_BUILT_IN)
	@make -s clean -C $(FUNC_SRC_DIR)
	@make -s clean -C $(FUNC_SRC_PARSER)

fclean: clean
	rm -f $(NAME)
	@make -s fclean -C $(FUNC_SRC_BUILT_IN)
	@make -s fclean -C $(FUNC_SRC_DIR)
	@make -s fclean -C $(FUNC_SRC_PARSER)

re: fclean all

.PHONY: all clean fclean re
