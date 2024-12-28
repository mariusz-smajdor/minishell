/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:32:55 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/26 01:45:51 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	hide_quoted_pipes(char **input)
{
	int	i;
	int	j;

	i = 0;
	while ((*input)[i])
	{
		if (is_quote((*input)[i]))
		{
			j = i + 1;
			while ((*input)[j] != (*input)[i] && (*input)[j])
			{
				if ((*input)[j] == '|')
					(*input)[j] = 1;
				j++;
			}
			i = j + 1;
		}
		else
			i++;
	}
}

char	**restore_quoted_pipes(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][j] == 1)
				input[i][j] = '|';
			j++;
		}
		i++;
	}
	return (input);
}

int	count_args(char *command, int i)
{
	int		j;
	int		result;

	result = 0;
	while (command && command[i])
	{
		j = 1;
		if (is_quote(command[i]))
		{
			while (command[i + j] != command[i] && command[i + j])
				j++;
			result++;
		}
		else
		{
			while (command[i + j] != ' ' && command[i + j])
				j++;
			result++;
		}
		while ((--j + 2) && command[i])
			i++;
	}
	return (result);
}

void	add_arg(t_hell *hell, int *k, char *arg)
{
	if (arg[0] != '\0')
		hell->argv[(*k)++] = arg;
	else
		free(arg);
}

char	**validate_input(char **input)
{
	char		**input_arr;
	bool		all_spaces;
	int			i;
	int			j;

	hide_quoted_pipes(input);
	input_arr = ft_split(*input, '|');
	input_arr = restore_quoted_pipes(input_arr);
	i = 0;
	while (input_arr[i])
	{
		j = 0;
		all_spaces = true;
		while (input_arr[i][j])
		{
			if (input_arr[i][j++] != ' ')
				all_spaces = false;
		}
		if (all_spaces)
			return (NULL);
		i++;
	}
	return (input_arr);
}
