NAME		:= minishell
RM			:= rm -f

CC			:= cc
FLAGS		:= -Wall -Wextra -Werror -I./src -I./libft
LIBS		:= -lreadline

SRC			:= $(wildcard src/*.c) $(wildcard src/parsing/*.c) $(wildcard src/env/*.c) $(wildcard src/utils/*.c)
OBJ			:= $(SRC:.c=.o)

LIBFT_DIR	:= libft
LIBFT_ARCH	:= $(LIBFT_DIR)/libft.a
LIBFT_REPO	:= https://github.com/mariusz-smajdor/libft.git

all: $(LIBFT_ARCH) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT_ARCH) $(LIBS)

$(LIBFT_ARCH):
	@if [ ! -d $(LIBFT_DIR) ]; then git clone $(LIBFT_REPO); fi
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@if [ -d $(LIBFT_DIR) ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi

re: fclean all

.PHONY: all clean fclean re
