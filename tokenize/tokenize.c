/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	skip_spaces(char **input)
{
	while (is_space(**input))
		(*input)++;
}

static int	token_len(char *input)
{
	int		len;
	char	quote;

	len = 0;
	while (input[len] && !is_space(input[len]))
	{
		if (is_quote(input[len]))
		{
			quote = input[len];
			len++;
			while (input[len] && input[len] != quote)
				len++;
		}
		len++;
	}
	return (len);
}

static void	add_new_token(t_token **token, char *input, int len)
{
	t_token	*new;
	t_token	*begin;

	new = safe_malloc(sizeof(t_token));
	new->value = safe_malloc(len + 1);
	ft_strlcpy(new->value, input, len + 1);
	new->next = NULL;
	if (!*token)
	{
		*token = new;
		begin = *token;
	}
	else
	{
		while ((*token)->next)
			*token = (*token)->next;
		(*token)->next = new;
	}
		*token = begin;
}

void	tokenize(char *input)
{
	int		len;
	t_token	*token;

	token = NULL;
	while (*input)
	{
		len = token_len(input);
		add_new_token(&token, input, len);
		input += len;
		skip_spaces(&input);
	}
}
