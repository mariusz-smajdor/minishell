/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 17:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

bool	is_operator(char c)
{
	return (c == '|' || c == ';' || c == '<' || c == '>');
}

bool	is_quote(char c)
{
	return (c == '`' || c == '\'' || c == '"');
}

void	skip_spaces(char *input, size_t *i)
{
	while (is_space(input[*i]))
		(*i)++;
}
