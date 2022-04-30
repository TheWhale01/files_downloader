CC=gcc
BIN_DIR=bin/
SRC_DIR=src/
OBJ_DIR=obj/
CFILES=$(addprefix $(SRC_DIR), dl.c free.c get_next_line.c linked_list.c main.c utils.c)
INCLUDES=includes/
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -lreadline
OBJS=$(patsubst $(SRCS_DIR)%.c, $(OBJ_DIR)%.o, $(CFILES))
NAME=bin/download

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
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
