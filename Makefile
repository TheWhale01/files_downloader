CC=gcc
BIN_DIR=bin/
SRCS_DIR=srcs/
OBJS_DIR=objs/
CFILES=srcs/main.c srcs/file.c srcs/dl.c srcs/progbar.c srcs/basic/ft_putnbr.c srcs/basic/ft_putchar.c srcs/basic/ft_strlen.c srcs/basic/ft_split.c srcs/parsing/parser.c
INCLUDES=includes/
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES)
OBJS=$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(CFILES))
NAME=bin/download

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lcurl

all: $(NAME)

debug: CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -g
debug: $(NAME)

sanitize: CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -fsanitize=address
sanitize: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_debug: fclean debug

re_sanitize: fclean sanitize

.PHONY: all debug sanitize clean fclean re re_debug re_sanitize
