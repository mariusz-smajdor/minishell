/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int count_args(char *input, int i)
{
	int		count;
	char	quote;

	count = 0;
    while (input[i] || input[i] != '|' || input[i] != '>' || input[i] != '<') // todo is_operator
    {
		if (input[i] == '\'' || input[i] == '\"') // todo is_quote
		{
			quote = input[i];
			i++;
			while (input[i] != quote)
				i++;
			i++;
		}
		if (input[i] == ' ')
		{
			count++;
			while (input[i] == ' ') // is_space
				i++;
		}
		if (ft_strlen(&input[i]) > 0)
			count++;
	}
	return (count);
}

void split_cmds(t_cmd *cmd, char *input)
{
    int i = 0;
    t_cmd *new_cmd;

    while (input[i])
    {
        new_cmd = safe_malloc(sizeof(new_cmd));
        if (!cmd)
            cmd = new_cmd;
        new_cmd->args = safe_malloc(sizeof(char *) * count_args(input, i));

    }
}
