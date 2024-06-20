#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"

#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

void	parse_input(char *input);
size_t	count_commands(char *input);

#endif