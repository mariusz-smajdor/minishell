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

    while (*cmd)
    {
        if (*cmd == '\'' || *cmd == '\"')
        {
            quote = *cmd;
            cmd++;
            while (*cmd && *cmd != quote)
                cmd++;
            if (!*cmd)
                exit_program("You must close the quotes!", EXIT_FAILURE);
        }
        cmd++;
    }
}

void	process_input(char *input)
{
    check_unclosed_quotes(input);
}
