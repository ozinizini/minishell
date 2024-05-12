NAME = libft.a
CC = gcc -c
CFLAGS = -Wall -Wextra -Werror

SOURCES =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strncmp.c ft_strlcat.c ft_atoi.c ft_atol.c ft_strnstr.c ft_strlcpy.c ft_strdup.c ft_bzero.c ft_calloc.c ft_memset.c ft_memmove.c ft_memcpy.c ft_memcmp.c ft_memchr.c ft_substr.c ft_strtrim.c ft_itoa.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_split.c ft_strcmp.c ft_lstnew_string.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c


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

.PHONY: all clean fclean