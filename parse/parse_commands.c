/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:36:28 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/18 15:37:08 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	get_cmd_size(char **c)
{
	size_t	s;

	s = 0;
	while (c[s] && ft_strncmp(c[s], "|", 2)
		&& ft_strncmp(c[s], "<", 2) && ft_strncmp(c[s], ">", 2)
		&& ft_strncmp(c[s], "<<", 3) && ft_strncmp(c[s], ">>", 3))
		s++;
	return (s);
}

static void	assign_cmd_op(t_cmd *cmd, char *op)
{
	if (!op)
		cmd->op = END;
	else if (!ft_strncmp(op, "|", 2))
		cmd->op = PIPE;
	else if (!ft_strncmp(op, "<", 2))
		cmd->op = LT;
	else if (!ft_strncmp(op, ">", 2))
		cmd->op = GT;
	else if (!ft_strncmp(op, "<<", 3))
		cmd->op = LTLT;
	else if (!ft_strncmp(op, ">>", 3))
		cmd->op = GTGT;
}

void	parse_commands(t_shell *shell, char **commands)
{	
	size_t	cmd_size;
	t_cmd	*curr_cmd;

	curr_cmd = shell->cmd;
	while (*commands)
	{
		cmd_size = get_cmd_size(commands);
		curr_cmd->av = safe_malloc(sizeof(char *) * (cmd_size + 1));
		ft_memcpy(curr_cmd->av, commands, sizeof(char *) * cmd_size);
		curr_cmd->av[cmd_size] = NULL;
		commands += cmd_size;
		assign_cmd_op(curr_cmd, *commands);
		if (curr_cmd->op == END)
			break ;
		commands++;
		curr_cmd->next = safe_malloc(sizeof(t_cmd));
		curr_cmd = curr_cmd->next;
		curr_cmd->next = NULL;
	}
	curr_cmd->next = NULL;
}
