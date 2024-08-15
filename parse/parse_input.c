/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:31:36 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/15 20:26:54 by msmajdor         ###   ########.fr       */
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

static int commands_len(char *input)
{
	int		commands;
	char	quote;

	commands = 0;
	if (*input)
		commands++;
	while (*input)
	{
		if (is_quote(*input))
		{
			quote = *input;
			input++;
			while (*input != quote)
				input++;
		}
		if (is_space(*input))
		{
			commands++;
			skip_spaces(&input);
		}
		input++;
	}
	return (commands);
}

void	parse_input(t_shell *shell, char *input)
{
	char	**commands;

	check_unclosed_quotes(input);
	commands = malloc(sizeof(char *) * commands_len(input));
	printf("%d\n", commands_len(input));
}
