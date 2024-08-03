#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef enum e_ops
{
	NONE,
	PIPE,
	LT,
	GT,
	LTLT,
	GTGT,
	END,
}	t_ops;

typedef struct s_token
{
	char	*value;
	t_ops	operator;
	t_token	*next;
}	t_token;

// UTILS
void	exit_program(const char *message, const int status);
void	*safe_malloc(size_t size);

// BUILTINS
int		mini_echo(char **argv);

#endif
