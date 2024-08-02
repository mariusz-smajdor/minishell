#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./my_lib/includes/get_next_line.h"
# include "./my_lib/includes/libft.h"
# include "./my_lib/includes/printf.h"

typedef struct s_cmd t_cmd;

typedef enum e_tokens
{
	PIPE,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_cmd
{
	char		**args;
	t_tokens	token;
	t_cmd		*next;
}	t_cmd;

void	exit_program(const char *message, const int status);
void	*safe_malloc(size_t size);
void	process_input(t_cmd *cmd, char *input);

// BUILTINS
int	mini_echo(char **argv);

#endif