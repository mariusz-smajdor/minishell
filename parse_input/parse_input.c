/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

void	skip_spaces(char *input, size_t *i)
{
	while (is_space(input[*i]))
		(*i)++;
}

bool	is_quote(char c)
{
	return (c == '`' || c == '\'' || c == '"');
}

void	count_quoted_command(char *input, size_t *count, size_t *i)
{
	char	quote;

	quote = input[*i];
	(*i)++;
	while (input[*i] && input[*i] != quote)
	{
		if (input[*i] == '\\')
			(*i) += 2;
		(*i)++;
	}
	(*count)++;
	(*i)++;
}

void	cound_command(char *input, size_t *count, size_t *i)
{
	while (input[*i] && !is_space(input[*i]) && !is_quote(input[*i]))
		(*i)++;
	(*count)++;
}

size_t	count_commands(char *input)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (input[i])
	{
		if (is_space(input[i]))
			skip_spaces(input, &i);
		if (is_quote(input[i]))
			count_quoted_command(input, &count, &i);
		if (!is_space(input[i]) && !is_quote(input[i]) && input[i])
			count_command(input, &count, &i);
	}
	return (count);
}

void	parse_input(char *input)
{
	char	**commands;

	commands = malloc(sizeof(char *) * count_commands(input) + 1);
	if (!commands)
		exit(1);
	printf("count_commands: %zu\n", count_commands(input));
}