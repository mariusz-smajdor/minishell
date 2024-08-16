/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:39:44 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/16 18:53:36 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static unsigned int	get_commands_len(char *input)
{
	int		commands;
	char	quote;

	commands = 0;
	if (*input)
		commands++;
	while (*input)
	{
		while (is_quote(*input))
		{
			quote = *input;
			input++;
			while (*input != quote)
				input++;
			input++;
		}
		if (is_space(*input))
		{
			commands++;
			skip_spaces(&input);
			continue ;
		}
		input++;
	}
	return (commands);
}

static unsigned int	get_command_len(char *input)
{
	int		len;
	char	quote;

	len = 0;
	while (*input)
	{
		if (is_quote(*input))
		{
			quote = *input;
			input++;
			while (*input != quote)
			{
				len++;
				input++;
			}
		}
		if (is_space(*input))
			break ;
		if (!is_quote(*input))
			len++;
		input++;
	}
	return (len);
}

static void	fill_command(char **input, char *command)
{
	char	quote;

	while (**input)
	{
		while (is_quote(**input) && **input == *(*input + 1))
			(*input) += 2;
		while (is_quote(**input))
		{
			quote = **input;
			(*input)++;
			while (**input != quote)
			{
				*command = **input;
				command++;
				(*input)++;
			}
			(*input)++;
		}
		if (is_space(**input))
			break ;
		*command = **input;
		command++;
		(*input)++;
	}
	*command = '\0';
	skip_spaces(input);
}

char	**fill_commands(char *input)
{
	char	**commands;
	int		commands_len;
	int		command_len;
	int		i;

	commands_len = get_commands_len(input);
	commands = malloc(sizeof(char *) * commands_len + 1);
	i = 0;
	while (i < commands_len)
	{
		command_len = get_command_len(input);
		commands[i] = malloc(sizeof(char) * (command_len + 1));
		fill_command(&input, commands[i]);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
