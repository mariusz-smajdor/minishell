#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_command t_command;

typedef enum e_tokens
{
	PIPE,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_command
{
	char		**cmds;
	t_tokens	token;
	t_command	*next;
}	t_command;

void	exit_program(const char *message, const int status);
void	process_input(char *input);

#endif