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

static void check_unclosed_quotes(char *cmd)
{
    char    quote;
	short	i;

    while (cmd[i])
    {
        if (*cmd == '\'' || *cmd == '\"')
        {
            quote = cmd[i];
            i++;
            while (cmd[i] && cmd[i] != quote)
                cmd++;
            if (!cmd[i])
                exit_program("You must close the quotes!", EXIT_FAILURE);
        }
        i++;
    }
}

void	process_input(t_cmd *cmd, char *input)
{
    check_unclosed_quotes(input);
}
