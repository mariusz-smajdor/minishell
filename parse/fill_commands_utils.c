/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_commands_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:58:41 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/17 18:17:49 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	get_commands_len(char *input)
{
	size_t	commands;
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

size_t	get_command_len(char *input)
{
	size_t	len;
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
				if (quote == '\"')
					if (*input == '$')
						len += get_env_len(&input);
				if (*input == quote)
					break ;
				len++;
				input++;
			}
		}
		if (*input == '$')
			len += get_env_len(&input);
		if (is_space(*input))
			break ;
		if (!is_quote(*input))
			len++;
		input++;
	}
	return (len);
}

size_t	get_env_len(char **input)
{
	char	*fake_env[] = { "USER=msmajdor", "USE2=msmajdo2", NULL };
	size_t	i;
	size_t	j;

	i = 0;
	(*input)++;
	while (ft_isalnum(*(*input + i)) || *(*input + i) == '_')
		i++;
	j = 0;
	while (fake_env[j])
	{
		if (ft_strncmp(fake_env[j], *input, i) == 0)
		{
			*input += i;
			return (ft_strlen(fake_env[j] + i + 1));
		}
		j++;
	}
	*input += i;
	return (0);
}
