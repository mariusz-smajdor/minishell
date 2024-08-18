NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = minishell.c init_shell.c parse/parse_input.c parse/fill_commands.c parse/fill_commands_utils.c \
		parse/parse_commands.c utils/exit_program.c utils/inlines.c utils/skip_spaces.c utils/safe_malloc.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -Llibft -lft -lreadline -o $@
	$(MAKE) clean

clean:
	$(RM) $(OBJS)
	make fclean -C libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
