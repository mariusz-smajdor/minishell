#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_cmd	t_cmd;

typedef enum e_ops
{
	PIPE,
	LT,
	GT,
	LTLT,
	GTGT,
	END,
}	t_ops;

typedef struct s_cmd
{
	char	**av;
	t_ops	op;
	t_cmd	*next;
}	t_cmd;

// UTILS
bool	is_operator(const char c);
bool	is_space(const char c);
bool	is_quote(const char c);
void	exit_program(const char *message, const int status);
void	*safe_malloc(size_t size);
void	skip_spaces(char **input);

// PARSING
void	parse_input(t_shell *shell, char *input);

// BUILTINS
int		mini_echo(char **argv);

#endif
