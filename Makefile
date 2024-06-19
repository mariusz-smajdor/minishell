NAME = minishell
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c parse_input/parse_input.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) -lreadline -o $@
	$(RM) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(LIBFT_DIR)/*.o

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: all clean fclean re
