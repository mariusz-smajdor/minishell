/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:31:36 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/18 15:36:47 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	check_unclosed_quotes(char *input)
{
	char	quote;

	while (*input)
	{
		if (*input == '\'' || *input == '\"')
		{
			quote = *input;
			input++;
			while (*input != quote)
			{
				if (!*input)
					exit_program("Unclosed quotes", EXIT_FAILURE);
				input++;
			}
		}
		input++;
	}
}

void	parse_input(t_shell *shell, char *input)
{
	char	**commands;

	check_unclosed_quotes(input);
	commands = fill_commands(shell, input);
	parse_commands(shell, commands);
}
