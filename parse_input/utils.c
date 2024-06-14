/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	count_commands(char *input)
{
	size_t	commands;
	size_t	i;

	commands = 0;
	i = 0;
	skip_spaces(input, &i);
	while (input[i])
	{
		if (!ft_isspace(input[i]))
		{
			commands++;
			while (input[i] && !ft_isspace(input[i]))
				i++;
		}
		i++;
	}
	return (commands);
}

size_t	commandlen(char *input)
{
	size_t	i;

	i = 0;
	while (input[i] && !ft_isspace(input[i]))
		i++;
	return (i);
}

void	skip_spaces(char *input, size_t *i)
{
	while (input[*i] == ' ')
		(*i)++;
}
