#include "minishell.h"

static short	process_quoted_arg(char **line, short *count, char *arg)
{
	short	n;
	char	quote;

	n = 0;
	quote = *(*line)++;
	while (**line != quote)
	{
		if (arg)
			*arg++ = **line;
		(*line)++;
		n++;
	}
	(*line)++;
	if (count)
		(*count)++;
	return (n);
}

static short	process_arg(char *line, char *arg)
{
	short	n;

	n = 0;
	if (is_quote(*line))
		return (process_quoted_arg(&line, NULL, arg));
	while (!is_space(*line) && !is_quote(*line) && *line)
	{
		if (arg)
			*arg++ = *line;
		line++;
		n++;
	}
	return (n);
}

static short	count_args(char *line)
{
    short   count;

    while (*line)
    {
		if (is_quote(*line))
			process_quoted_arg(&line, &count, NULL);
		else if (is_space(*line))
		{
			if (!is_quote(*(line - 1)))
				count++;
			skip_spaces(&line);
		}
		else
		{
			if (is_quote(line[1]) || !line[1])
				count++;
			line++;
		}
    }
	return (count);
}

void	parse_input(t_data *data, char *line)
{
	short	i;
	short   n;
	short	m;

	n = count_args(line);
    data->args = malloc(sizeof(char *) * (n + 1));
	data->args[n] = NULL;
	i = 0;
	while (i < n)
	{
		m = process_arg(line, NULL);
		data->args[i] = malloc(sizeof(char) * (m + 1));
		process_arg(line, data->args[i]);
		data->args[i][m] = '\0';
		if (is_quote(*line))
			m += 2;
		line += m;
		skip_spaces(&line);
		i++;
	}
}
