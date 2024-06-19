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

void	skip_spaces(char *input)
{
	while (*input == ' ')
		input++;
}

char	*closest_to_split(const char *input)
{
	char	*closest;
	
	closest = ft_strchr(input, '\0');
	if (ft_strchr(input, ' ') && ft_strchr(input, ' ') < closest)
		closest = ft_strchr(input, ' ');
	if (ft_strchr(input, '"') && ft_strchr(input, '"') < closest)
		closest = ft_strchr(input, '"');
	return (closest);
}

size_t	count_commands(char *input)
{
	size_t	count;

	count = 0;
	while(*input == ' ')
		input++;
	while (*input)
	{
		input = closest_to_split(input);
		if (*input == '"')
		{
			input++;
			input = ft_strchr(input, '"') + 1;
		}
		if (*input == ' ')
			while(*input == ' ')
				input++;
		count++;
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