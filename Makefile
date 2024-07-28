NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = minishell.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) -lreadline -o $@
	$(MAKE) clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
