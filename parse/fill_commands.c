/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int  arg_len(t_token *token)
{
	int len;

    len = 0;
    while (token)
    {
        if (token->operator == NONE)
            len++;
		else
			break ;
		token = token->next;
    }
    return (len);
}

static void	assign_args(char **av, t_token **token)
{
	int	i;

	i = 0;
	while ((*token)->operator == NONE)
	{
		av[i] = ft_strdup((*token)->value);
		if ((*token)->next)
			(*token) = (*token)->next;
		else
			break ;
		i++;
	}
	av[i] = NULL;
}

static void	assign_operator(t_ops *op, t_token **token)
{
	if ((*token)->operator)
		*op = (*token)->operator;
	else
		*op = END;
}

static void	add_new_command(t_cmd **cmd, t_token **token)
{
    t_cmd	*new;
    t_cmd	*tmp;

    new = safe_malloc(sizeof(t_cmd));
    new->av = safe_malloc(sizeof(char *) * arg_len(*token) + 1);
	assign_args(new->av, token);
	assign_operator(&new->op, token);
	new->next = NULL;
	(*token) = (*token)->next;
	if (!(*cmd))
		*cmd = new;
	else
	{
		tmp = *cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	fill_commands(t_cmd **cmd, t_token **token)
{
	while (*token)
		add_new_command(cmd, token);
}
