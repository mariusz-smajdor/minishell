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

static void	fill_commands(char **commands, char *input)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	skip_spaces(input, &i);
	while (input[i])
	{
		if (!ft_isspace(input[i]))
		{
			commands[j] = malloc(sizeof(char) * (commandlen(input + i) + 1));
			if (!commands[j])
				exit(1);
			while (input[i] && !ft_isspace(input[i]))
				commands[j][k++] = input[i++];
			commands[j][k] = '\0';
			k = 0;
			j++;
		}
		i++;
	}
	commands[j] = NULL;
}

void	parse_input(char *input)
{
	char **commands;

	commands = malloc(sizeof(char *) * count_commands(input) + 1);
	if (!commands)
		exit(1);
	fill_commands(commands, input);
}