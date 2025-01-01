#include "minishell.h"

void	skip_quotes(char **line, short *n)
{
	char	quote;

	while (is_quote(**line))
	{
		quote = *(*line)++;
		while (**line != quote)
			(*line)++;
		(*line)++;
		(*n)++;
	}
}

void	skip_spaces(char **line, short *n)
{
	if (!is_quote(*(*line - 1)))
		(*n)++;
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
