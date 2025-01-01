#include "minishell.h"

static short	count_args(char *line)
{
    short   n;

    while (*line)
    {
		if (is_quote(*line))
			skip_quotes(&line, &n);
		else if (is_space(*line))
			skip_spaces(&line, &n);
		else
		{
			if (!line[1] || is_quote(line[1]))
				n++;
			line++;
		}
    }
	return (n);
}

void	parse_input(t_data *data, char *line)
{
	short   n;

	n = count_args(line);
    data->args = malloc(sizeof(char *) * (n + 1));
    printf("%d\n", n);
}
