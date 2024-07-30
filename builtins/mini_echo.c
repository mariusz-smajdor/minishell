#include "../minishell.h"

static void	print_vars(char **vars)
{
	size_t	i;

	i = 0;
	while (vars[i][0])
	{
		ft_putstr_fd(vars[i], STDOUT_FILENO);
		if (vars[i + 1][0])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
}

int	mini_echo(char **argv)
{
	size_t	i;
	size_t	j;
	bool	no_nl;

	i = 1;
	no_nl = false;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == 'n')
	{
		j = 1;
		while (argv[i][j] == 'n')
			j++;
		if (argv[i][j] == '\0')
		{
			no_nl = true;
			i++;
		}
		else
			break ;
	}
	print_vars(&argv[i]);
	if (!no_nl)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}