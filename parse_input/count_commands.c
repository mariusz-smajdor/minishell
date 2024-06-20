/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/20 17:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	count_quoted_command(char *input, size_t *count, size_t *i)
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

static void	count_command(char *input, size_t *count, size_t *i)
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