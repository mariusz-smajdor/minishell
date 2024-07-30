# PROJECT NAME #
NAME =			my_lib.a

# DIRS #
SRC_DIR =		srcs
HDR_DIR =		includes
#OBJ_DIR =		objs
LIBFT_DIR =		libft
PRINTF_DIR =	printf
GNL_DIR =		get_next_line

# SRC FILES #
SRC_FLS =		$(LIBFT_SRC) \
					$(GNL_SRC) \
					$(PRINTF_SRC)

LIBFT_FLS =		$(LIBFT_DIR)/ft_atoi.c \
					$(LIBFT_DIR)/ft_bzero.c \
					$(LIBFT_DIR)/ft_calloc.c \
					$(LIBFT_DIR)/ft_isalnum.c \
					$(LIBFT_DIR)/ft_isalpha.c \
					$(LIBFT_DIR)/ft_isascii.c \
					$(LIBFT_DIR)/ft_isdigit.c \
					$(LIBFT_DIR)/ft_isprint.c \
					$(LIBFT_DIR)/ft_itoa.c \
					$(LIBFT_DIR)/ft_memchr.c \
					$(LIBFT_DIR)/ft_memcmp.c \
					$(LIBFT_DIR)/ft_memcpy.c \
					$(LIBFT_DIR)/ft_memmove.c \
					$(LIBFT_DIR)/ft_memset.c \
					$(LIBFT_DIR)/ft_putchar_fd.c \
					$(LIBFT_DIR)/ft_putendl_fd.c \
					$(LIBFT_DIR)/ft_putnbr_fd.c \
					$(LIBFT_DIR)/ft_putstr_fd.c \
					$(LIBFT_DIR)/ft_split.c \
					$(LIBFT_DIR)/ft_strchr.c \
					$(LIBFT_DIR)/ft_strdup.c \
					$(LIBFT_DIR)/ft_striteri.c \
					$(LIBFT_DIR)/ft_strjoin.c \
					$(LIBFT_DIR)/ft_strlcat.c \
					$(LIBFT_DIR)/ft_strlcpy.c \
					$(LIBFT_DIR)/ft_strlen.c \
					$(LIBFT_DIR)/ft_strmapi.c \
					$(LIBFT_DIR)/ft_strncmp.c \
					$(LIBFT_DIR)/ft_strnstr.c \
					$(LIBFT_DIR)/ft_strrchr.c \
					$(LIBFT_DIR)/ft_strtrim.c \
					$(LIBFT_DIR)/ft_substr.c \
					$(LIBFT_DIR)/ft_tolower.c \
					$(LIBFT_DIR)/ft_toupper.c

PRINTF_FLS =	$(PRINTF_DIR)/ft_printf.c \
					$(PRINTF_DIR)/ft_print_char.c \
					$(PRINTF_DIR)/ft_print_hex.c \
					$(PRINTF_DIR)/ft_print_int.c \
					$(PRINTF_DIR)/ft_print_pointer.c \
					$(PRINTF_DIR)/ft_print_str.c \
					$(PRINTF_DIR)/ft_print_unsigned_int.c

GNL_FLS =		$(GNL_DIR)/get_next_line.c

# FILEPATHS #
SRCS =			$(addprefix $(SRC_DIR)/,$(LIBFT_FLS)) \
					$(addprefix $(SRC_DIR)/,$(PRINTF_FLS)) \
					$(addprefix $(SRC_DIR)/,$(GNL_FLS))
OBJS =			$(SRCS:.c=.o)

# RULES #
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
