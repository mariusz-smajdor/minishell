/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:20:18 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/20 16:25:31 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	set_envp(t_cmd *cmd, char *key, char *value)
{
	char	*tmp;
	char	*new;
	size_t	i;

	i = 0;
	tmp = search_envp(cmd->envp, key);
	if (tmp)
	{
		while (cmd->envp[i])
		{
			if (!ft_strncmp(cmd->envp[i], key, ft_strlen(key)))
			{
//				free(cmd->envp[i]);
				new = ft_strjoin(key, "=");
				cmd->envp[i] = ft_strjoin(new, value);
				free(new);
				return (0);
			}
			i++;
		}
	}
	return (-1);
}

static void	change_pwd(t_cmd *cmd, char *pwd)
{
	char	*oldpwd;

	oldpwd = search_envp(cmd->envp, "PWD");
	if (!oldpwd)
	{
		ft_putstr_fd("minishell: cd: PWD not set\n", STDERR_FILENO);
		return ;
	}
	if (set_envp(cmd, "OLDPWD", oldpwd) == -1)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
		return ;
	}
	if (set_envp(cmd, "PWD", pwd) == -1)
	{
		ft_putstr_fd("minishell: cd: PWD not set\n", STDERR_FILENO);
		return ;
	}
}

int	mini_cd(t_cmd *cmd)
{
	char	*dir;

	if (!cmd->av[1])
		dir = search_envp(cmd->envp, "HOME");
	else
		dir = cmd->av[1];
	if (chdir(dir) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(cmd->av[1], STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	change_pwd(cmd, getcwd(NULL, 0));
	return (0);
}
