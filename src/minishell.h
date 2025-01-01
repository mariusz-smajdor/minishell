#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

typedef struct s_env t_env;
typedef struct s_data t_data;

typedef struct s_env
{
    char	*key;
    char	*value;
	t_env	*next;
}   t_env;

typedef struct s_data
{
	char	**args;
	t_env	*env;
}	t_data;

void	init_env(t_data *data, char **envp);
void	parse_input(t_data *data, char *line);
void	exit_error(char *message);

void	skip_spaces(char **line);
bool	is_space(char c);
bool	is_quote(char c);

#endif