/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:34:13 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/17 19:34:34 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_envp	*init_envp(char **envp)
{
	t_envp	*env;
	t_envp	*tmp;
	size_t	i;

	i = 0;
	env = malloc(sizeof(t_envp));
	tmp = env;
	while (envp[i])
	{
		tmp->key = ft_strndup(envp[i], ft_strchr(envp[i], '=') - envp[i]);
		tmp->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		tmp->next = malloc(sizeof(t_envp));
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	return (env);
}

void	init_shell(t_shell *shell, char **envp)
{
	shell->cmd = malloc(sizeof(t_cmd));
	shell->envp = init_envp(envp);
	shell->exit = false;
}
