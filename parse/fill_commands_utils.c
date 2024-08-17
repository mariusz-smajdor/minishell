/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_commands_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:58:41 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/17 19:52:50 by msmajdor         ###   ########.fr       */
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

size_t	get_command_len(t_shell *shell, char *input)
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
						len += get_env_len(shell, &input);
				if (*input == quote)
					break ;
				len++;
				input++;
			}
		}
		if (*input == '$')
			len += get_env_len(shell, &input);
		if (is_space(*input))
			break ;
		if (!is_quote(*input))
			len++;
		input++;
	}
	return (len);
}

size_t	get_env_len(t_shell *shell, char **input)
{
	size_t	i;
	size_t	j;

	i = 0;
	(*input)++;
	while (ft_isalnum(*(*input + i)) || *(*input + i) == '_')
		i++;
	j = 0;
	while (shell->envp->key)
	{
		if (ft_strncmp(shell->envp->key, *input, i) == 0)
		{
			*input += i;
			return (ft_strlen(shell->envp->value + 1));
		}
		shell->envp = shell->envp->next;
	}
	*input += i;
	return (0);
}
