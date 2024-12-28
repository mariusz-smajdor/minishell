#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
}   t_env;

typedef struct s_data
{
	char	**args;
	t_env	*env;
}	t_data;

void	parse_input(char *line);
void	init_env(t_data *data, char **envp);
void	exit_error(char *message);

#endif