/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:41:56 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/27 19:42:41 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_pipes(t_hell *hell, t_env *env)
{
	int	i;

	i = 0;
	while (hell[i].cmd)
	{
		if (pipe(hell[i].fd) < 0)
			exit_program(env, "pipe failed\n", 2);
		i++;
	}
}

void	close_pipes(t_hell *hell)
{
	int	i;

	i = 0;
	while (hell[i].cmd)
	{
		close(hell[i].fd[0]);
		close(hell[i].fd[1]);
		i++;
	}
}

void	close_unused_pipes(t_hell *hell, int i)
{
	int	j;

	j = 0;
	while (hell[j].cmd)
	{
		if (i != j)
			close(hell[j].fd[1]);
		if (i - 1 != j)
			close(hell[j].fd[0]);
		j++;
	}
}
