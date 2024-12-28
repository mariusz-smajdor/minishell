/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:17:46 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/27 21:02:28 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static inline int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static void	toggle_quote_state(char **input, int i, char *quote)
{
	if (*quote == '\0' && is_quote((*input)[i]))
		*quote = (*input)[i];
	else if (*quote == (*input)[i])
		*quote = '\0';
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

int	check_unclosed_quotes(char *str, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < n)
	{
		if (str[i] == '"')
			count++;
		i++;
	}
	return (count % 2);
}

void	trim_spaces(char **input, char *quote, char	**result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	*quote = '\0';
	while ((*input)[i] && is_whitespace((*input)[i]))
		i++;
	while ((*input)[i])
	{
		while ((*input)[i] && (!is_whitespace((*input)[i]) || *quote))
		{
			toggle_quote_state(input, i, quote);
			(*result)[j] = (*input)[i];
			j++;
			i++;
		}
		while ((*input)[i] && is_whitespace((*input)[i]))
			i++;
		if ((*input)[i])
			(*result)[j++] = ' ';
	}
	(*result)[j] = '\0';
}
