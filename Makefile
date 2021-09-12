CC=gcc
BIN_DIR=bin/
OBJS_DIR=objs/
SRCS_DIR=srcs/
INCLUDES=includes/
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES)
CFILES=$(addprefix $(SRCS_DIR), main.c file.c dl.c basic/ft_putchar.c basic/ft_split.c basic/ft_strlen.c parsing/parser.c)
OBJS=$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(CFILES))
NAME=$(BIN_DIR)download

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(shell mkdir -p $(dir $@))
	$(CC) $(CFLAGS) -c $< -o $@

(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lcurl -o $(NAME)

all: $(NAME)

sanitize: CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -fsanitize=address
sanitize: $(NAME) clean

debug: CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -g
debug: $(NAME) clean

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

re_sanitize: fclean sanitize

re_debug: fclean debug

.PHONY: all sanitize debug clean fclean
