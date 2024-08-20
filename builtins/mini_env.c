/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:23:35 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/20 16:26:19 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_env(t_cmd *cmd)
{
	size_t	i;
	char	**envp;

	envp = cmd->envp;
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], STDIN_FILENO);
		ft_putchar_fd('\n', STDIN_FILENO);
		i++;
	}
	return (0);
}
