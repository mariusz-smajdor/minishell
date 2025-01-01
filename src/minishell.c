#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*line;

	((void)argc, (void)argv);
	init_env(&data, envp);
	while (true)
    {
        line = readline("minishell$ ");
        if (line == NULL)
			break;
		if (line[0] != '\0')
		{
			parse_input(&data, ft_strtrim(line, " "));
			add_history(line);
		}
		free(line);
	}
	return (0);
}
