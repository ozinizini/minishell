CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./Libft -I./built_in -I./parser -I$(HOME)/.brew/opt/readline/include
LDFLAGS = -lreadline -L$(HOME)/.brew/opt/readline/lib

FUNC_SRC_BUILT_IN = ./built_in

LIB_BUILT_IN = ./built_in/built_in.a

FUNC_SRC_PARSER = ./parser

LIB_PARSER = ./parser/parser.a

FUNC_SRC_DIR = ./Libft

LIB = ./Libft/libft.a

SRCS =	./execution.c\
		./execution_error_messages.c\
		./execution_memory_management.c\
		./execution_paths.c\
		./execute_child.c\
		./setting_up_children_built_ins.c\
		./execution_heredoc_management.c\
		./execution_heredoc_file.c\
		./utils_structs.c\
		./execution_file_descriptors.c\
		./execution_run_built_in.c\
		./execution_env_export_lists.c\
		./main.c

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
