NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = minishell.c utils/exit_program.c utils/safe_malloc.c process_input/process_input.c builtins/mini_echo.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	make -C my_lib
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) -lreadline -o $@ my_lib/my_lib.a
	$(MAKE) clean

clean:
	make clean -C my_lib
	$(RM) $(OBJS)

fclean: clean
	make fclean -C my_lib
	$(RM) $(NAME)

.PHONY: all clean fclean re
