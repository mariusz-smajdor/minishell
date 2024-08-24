/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:33:55 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/21 14:00:53 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_vars(char **vars)
{
	size_t	i;

	i = 0;
	while (vars[i])
	{
		ft_putstr_fd(vars[i], STDOUT_FILENO);
		if (vars[i + 1] && ft_strlen(vars[i])) /// strlen check zeby nie dodawac spacji miedziy pustymi stringami : )))
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
