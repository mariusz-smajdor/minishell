/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:45:15 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/24 20:11:38 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_exec(t_shell *shell, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->av[0], "echo", ft_strlen(cmd->av[0])))
		return (mini_echo(cmd->av));
	if (!ft_strncmp(cmd->av[0], "env", ft_strlen(cmd->av[0])))
		return (mini_env(shell->envp));
	if (!ft_strncmp(cmd->av[0], "pwd", ft_strlen(cmd->av[0])))
		return (mini_pwd());
	if (!ft_strncmp(cmd->av[0], "cd", ft_strlen(cmd->av[0])))
		return (mini_cd(shell, cmd));
	if (!ft_strncmp(cmd->av[0], "unset", ft_strlen(cmd->av[0])))
		return (mini_unset(shell->envp, cmd));
	if (!ft_strncmp(cmd->av[0], "export", ft_strlen(cmd->av[0])))
		return (mini_export(shell->envp, cmd));
	return (-1);
}
