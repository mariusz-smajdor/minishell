/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:42:59 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/20 16:26:35 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_exec(t_cmd *cmd)
{
	perror(cmd->av[0]);
	if (!ft_strncmp(cmd->av[0], "echo", ft_strlen(cmd->av[0])))
		return (mini_echo(cmd, cmd->av));
	if (!ft_strncmp(cmd->av[0], "env", ft_strlen(cmd->av[0])))
		return (mini_env(cmd));
	if (!ft_strncmp(cmd->av[0], "pwd", ft_strlen(cmd->av[0])))
		return (mini_pwd(cmd));
	if (!ft_strncmp(cmd->av[0], "cd", ft_strlen(cmd->av[0])))
		return (mini_cd(cmd));
	return (1);
}
