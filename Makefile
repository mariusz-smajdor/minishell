NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = minishell.c $(UTILS_SRCS) $(PARSE_SRCS) $(BUILTINS_SRCS) $(EXEC_SRCS)
UTILS_SRCS = utils/safe_malloc.c utils/exit_program.c utils/env.c utils/free.c utils/parse.c
PARSE_SRCS = parse/parse_input.c parse/helpers.c parse/init_hell.c parse/validate_input.c
EXEC_SRCS = exec/exec.c exec/helpers.c exec/path_commands.c exec/redirections.c exec/pipes.c
BUILTINS_SRCS = builtins/mini_echo.c builtins/mini_cd.c builtins/mini_pwd.c \
				builtins/mini_export.c builtins/mini_unset.c builtins/mini_env.c builtins/mini_exit.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -Llibft -lft -lreadline -o $@

clean:
	$(RM) $(OBJS)
	make fclean -C libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
