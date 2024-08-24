/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:01:17 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/19 15:41:48 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	set_pwds(t_envp *envp, char *prev_dir, char *dir)
{
	t_envp	*pwd;
	t_envp	*old_pwd;

	pwd = search_var(envp, "PWD");
	old_pwd = search_var(envp, "OLDPWD");
	if (old_pwd != NULL)
	{
		free(old_pwd->value);
		old_pwd->value = ft_strdup(prev_dir);
	}
	else
		envp_add_back(&envp, "OLDPWD", prev_dir);
	if (pwd)
	{
		free(pwd->value);
		pwd->value = ft_strdup(getcwd(NULL, 0));
	}
}

int	mini_cd(t_shell *shell, t_cmd *cmd)
{
	char	*prev_dir;

	prev_dir = getcwd(NULL, 0);
	if (!cmd->av[1] || cmd->av[2])
	{
		printf("Wrong amount of arguments!\n");
		return (1);
	}
	if (!ft_strncmp(cmd->av[1], "-", 1))
	{
		printf("Flag not supported.\n");
		return (1);
	}
	if (chdir(cmd->av[1]))
	{
		printf("Failed to reach the destination target!\n");
		return (1);
	}
	set_pwds(shell->envp, prev_dir, cmd->av[1]);
	return (0);
}
