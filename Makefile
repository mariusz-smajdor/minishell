NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = minishell.c tokenize/tokenize.c builtins/mini_echo.c \
		utils/inlines.c utils/exit_program.c utils/safe_malloc.c
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

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re