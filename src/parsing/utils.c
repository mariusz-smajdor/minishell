#include "minishell.h"

void	skip_spaces(char **line)
{
	while (is_space(**line))
		(*line)++;
}

bool	is_space(char c)
{
	return (c == ' ');
}

bool	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}
