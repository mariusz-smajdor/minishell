/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_tokens(t_token **token)
{
	t_token	*tmp;

	while (*token)
	{
		tmp = *token;
		*token = (*token)->next;
		free(tmp->value);
		free(tmp);
	}
}

static void	free_commands(t_cmd **cmd)
{
	t_cmd	*tmp;

	while (*cmd)
	{
		tmp = *cmd;
		*cmd = (*cmd)->next;
		free(tmp->av);
		free(tmp);
	}
}

void	free_lists(t_token **token, t_cmd **cmd)
{
	free_tokens(token);
	free_commands(cmd);
}
