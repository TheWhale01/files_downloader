CC=gcc
CFILES=srcs/main.c srcs/file.c srcs/dl.c srcs/basic/ft_putchar.c srcs/basic/ft_strlen.c srcs/basic/ft_split.c srcs/parsing/parser.c
INCLUDES=includes/
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES)
OBJS=${CFILES:.c=.o}
NAME=download

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lcurl

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_sanitize: fclean sanitize

re_debug: fclean debug

.PHONY: all sanitize clean fclean re
