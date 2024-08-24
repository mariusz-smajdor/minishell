/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:18:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/19 15:30:42 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	remove_envp_node(t_envp **head, const char *key)
{
	t_envp	*current;
	t_envp	*previous;

	current = *head;
	previous = NULL;
	while (current != NULL)
	{
		if (!ft_strncmp(current->key, key, ft_strlen(key)))
		{
			if (previous == NULL)
				*head = current->next;
			else
				previous->next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

int	mini_unset(t_envp *envp, t_cmd *cmd)
{
	size_t	i;

	i = 1;
	while (cmd->av[i])
	{
		remove_envp_node(&envp, cmd->av[i]);
		i++;
	}
	return (0);
}
