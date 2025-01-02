#include "minishell.h"

static short	process_env(t_env *env, char **line, char **arg)
{
	t_env	*current;
	short	n;

	(*line)++;
	current = env;
	n = 0;
	while (current)
	{
		if (!ft_strncmp(current->key, *line, ft_strlen(current->key)))
		{
			if (*arg)
				*arg += ft_strlcpy(*arg, current->value, ft_strlen(current->value) + 1);
			*line += ft_strlen(current->key);
			n += ft_strlen(current->value);
			break ;
		}
		current = current->next;
	}
	return (n);
}

static short	process_quoted_arg(t_env *env, char **line, short *count, char *arg)
{
	short	n;
	char	quote;

	n = 0;
	quote = *(*line)++;
	while (**line != quote)
	{
		if (quote == '"' && **line == '$' && env)
			n += process_env(env, line, &arg);
		else
		{
			if (arg)
				*arg++ = **line;
			(*line)++;
			n++;
		}
	}
	(*line)++;
	if (count)
		(*count)++;
	return (n);
}

static short	process_arg(t_env *env, char *line, char *arg)
{
	short	n;

	n = 0;
	if (is_quote(*line))
		return (process_quoted_arg(env, &line, NULL, arg));
	while (!is_space(*line) && !is_quote(*line) && *line)
	{
		if (env && *line == '$')
			n += process_env(env, &line, &arg);
		else
		{
			if (arg)
				*arg++ = *line;
			line++;
			n++;
		}
	}
	return (n);
}

static short	count_args(char *line)
{
    short   count;

    while (*line)
    {
		if (is_quote(*line))
			process_quoted_arg(NULL, &line, &count, NULL);
		else if (is_space(*line))
		{
			if (!is_quote(*(line - 1)))
				count++;
			skip_spaces(&line);
		}
		else
		{
			line++;
			if (is_quote(*line) || !*line)
				count++;
		}
    }
	return (count);
}

void	parse_input(t_data *data, char *line)
{
	t_env	*env;
	short	i;
	short   n;
	short	m;

	env = data->env;
	n = count_args(line);
    data->args = malloc(sizeof(char *) * (n + 1));
	data->args[n] = NULL;
	i = 0;
	while (i < n)
	{
		m = process_arg(env, line, NULL);
		data->args[i] = malloc(sizeof(char) * (m + 1));
		data->args[i][m] = '\0';
		process_arg(env, line, data->args[i]);
		if (is_quote(*line))
			process_quoted_arg(env, &line, NULL, NULL);
		else
			line += process_arg(NULL, line, NULL);
		skip_spaces(&line);
		i++;
	}
}
