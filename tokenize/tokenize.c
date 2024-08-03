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

void	tokenize(char *input)
{
	int		len;
	t_token *begin;
	t_token *token;
	t_token	*new_token;

	token = NULL;
	begin = NULL;
	while (*input)
	{
		new_token = safe_malloc(sizeof(t_token));
		new_token->next = NULL;
		if (!token)
		{
			token = new_token;
			begin = token;
		}	
		else
		{
			while (token->next)
				token = token->next;
			token->next = new_token;
		}
		len = token_len(input);
		new_token->value = safe_malloc(len + 1);
		ft_strlcpy(new_token->value, input, len + 1);
		input += len;
		skip_spaces(&input);
	}
	token = begin;
	while (token)
	{
		printf("Token: %s\n", token->value);
		token = token->next;
	}
}
