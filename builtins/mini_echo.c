/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:17:44 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/20 16:25:04 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_env(t_cmd *cmd, char *s)
{
	char	*env;

	env = search_envp(cmd->envp, s);
	if (env)
		ft_putstr_fd(env, STDOUT_FILENO);
}

static void	print_vars(t_cmd *cmd, char **vars)
{
	size_t	i;

	i = 0;
	while (vars[i])
	{
		if (vars[i][0] == '$')
			print_env(cmd, vars[i] + 1);
		else
			ft_putstr_fd(vars[i], STDOUT_FILENO);
		if (vars[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
}

int	mini_echo(t_cmd *cmd, char **argv)
{
	size_t	i;
	size_t	j;
	bool	no_nl;

	i = 1;
	no_nl = false;
	if (!argv[1])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	if (argv[1][0] == '-' && !argv[1][1])
		i++;
	else
	{
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
				break;
		}
	}
	print_vars(cmd, &argv[i]);
	if (!no_nl)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
