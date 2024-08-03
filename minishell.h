#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

// UTILS
void	exit_program(const char *message, const int status);
void	*safe_malloc(size_t size);

// BUILTINS
int		mini_echo(char **argv);

#endif