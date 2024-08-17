/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:39:44 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/17 17:55:00 by msmajdor         ###   ########.fr       */
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

void	fill_env(char ***input, char **command)
{
	char *fake_env[] = { "USER=msmajdor", "USE2=msmajdo2", NULL };
	size_t	i;
	size_t	j;

	i = 0;
	(**input)++;
    while (ft_isalnum(*(**input + i)) || *(**input + i) == '_')
        i++;
	j = 0;
	while (fake_env[j])
	{
		if (ft_strncmp(fake_env[j], **input, i) == 0)
		{
			ft_strlcpy(*command, fake_env[j] + i + 1, ft_strlen(fake_env[j] + i));
			*command += ft_strlen(fake_env[j] + i + 1);
			**input += i;
			return ;
		}
		j++;
	}
	**input += i;
}

size_t get_env_len(char **input)
{
    char *fake_env[] = { "USER=msmajdor", "USE2=msmajdo2", NULL };
    size_t i = 0;
    size_t j = 0;

	(*input)++;
    while (ft_isalnum(*(*input + i)) || *(*input + i) == '_')
        i++;
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
		if (**input == '$')
			fill_env(&input, &command);
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
	commands = safe_malloc(sizeof(char *) * commands_len + 1);
	i = 0;
	while (i < commands_len)
	{
		command_len = get_command_len(input);
		commands[i] = safe_malloc(sizeof(char) * (command_len + 1));
		fill_command(&input, commands[i]);
		i++;
	}
	commands[i] = NULL;
	for (i = 0; commands[i]; i++)
		printf("%s\n", commands[i]);

	return (commands);
}
