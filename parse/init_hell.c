/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:30:20 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/27 21:03:17 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	change_flags(char *command, t_hell *hell, int i, int *j)
{
	char	*new_flag;
	char	*combined_flags;

	while (command[i + *j] != ' ' && command[i + *j])
		(*j)++;
	if (hell->flags)
	{
		combined_flags = ft_substr(command, i + 1, (*j) - 1);
		new_flag = ft_strjoin(hell->flags, combined_flags);
		free(hell->flags);
		free(combined_flags);
		hell->flags = new_flag;
	}
	else
		hell->flags = ft_substr(command, i + 1, (*j) - 1);
}

static int	change_quoted_arg(t_hell *hell, char *command, int i, int *k)
{
	int	j;

	j = 1;
	while (command[i + j] != command[i])
		j++;
	if (command[i] == command[i + 1] && j++)
		hell->argv[(*k)++] = ft_strdup("\0");
	else
		add_arg(hell, k, ft_substr(command, i + 1, j++ - 1));
	return (j);
}

static void	update_cmd(char *command, t_hell *hell, int i)
{
	int		j;
	int		k;

	k = 0;
	while (command[i])
	{
		j = 1;
		if (command[i] == '-' && command[i + 1] && ft_isalpha(command[i + 1]))
			change_flags(command, hell, i, &j);
		else if (is_quote(command[i]))
			j = change_quoted_arg(hell, command, i, &k);
		else
		{
			while (command[i + j] != ' ' && command[i + j])
				j++;
			add_arg(hell, &k, ft_substr(command, i, j));
		}
		while ((--j + 2) && command[i])
			i++;
	}
	hell->argv[k] = 0;
}

static void	get_command(char *command, t_hell *hell)
{
	int		i;

	i = 0;
	if (command[i] == ' ')
		command++;
	while (command[i] && command[i] != ' ')
		i++;
	hell->cmd = ft_substr(command, 0, i);
	hell->fd[0] = 0;
	hell->fd[1] = 1;
	hell->argv = safe_malloc(sizeof(char *) * (count_args(command, i) + 1));
	hell->argv[0] = NULL;
	if (!command[i] || !command[i + 1])
		return ;
	i++;
	update_cmd(command, hell, i);
}

t_hell	*init_hell(char **input)
{
	char	**input_arr;
	t_hell	*hell_arr;
	int		i;

	input_arr = validate_input(input);
	if (!input_arr)
		return (NULL);
	hell_arr = malloc(sizeof(t_hell) * (words_count(*input, '|') + 1));
	i = 0;
	while (input_arr[i])
	{
		hell_arr[i].flags = NULL;
		hell_arr[i].cmd = NULL;
		hell_arr[i].argv = NULL;
		get_command(input_arr[i], &(hell_arr[i]));
		i++;
	}
	hell_arr[i].cmd = 0;
	free_arr(input_arr);
	return (hell_arr);
}
