/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:31:04 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/27 00:41:21 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_status(t_hell *hell, char *home)
{
	if (hell->argv[0] == NULL)
	{
		if (home == NULL)
		{
			ft_putstr_fd("The HOME variable is not set\n", 2);
			return (1);
		}
		if (chdir(home) != 0)
		{
			ft_putstr_fd("The HOME variable is not valid\n", 2);
			return (1);
		}
	}
	else
	{
		if (chdir(hell->argv[0]) != 0)
		{
			ft_putstr_fd("cd: No such file or directory\n", 2);
			return (1);
		}
	}
	return (0);
}

int	mini_cd(t_env *env, t_hell hell)
{
	char	*home;
	char	buffer[1024];
	int		status;

	home = get_env(env, "HOME");
	status = get_status(&hell, home);
	del_env(env, "PWD");
	add_env(env, "PWD", getcwd(buffer, 1024));
	return (status);
}
