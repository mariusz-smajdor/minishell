/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:57:34 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/27 18:10:34 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_hell(t_hell *hell)
{
	int	i;

	i = 0;
	while (hell[i].cmd)
	{
		if (hell[i].cmd)
			free(hell[i].cmd);
		if (hell[i].flags)
			free(hell[i].flags);
		if (hell[i].argv)
			free_arr(hell[i].argv);
		i++;
	}
	free(hell);
}

void	free_env(t_env *env)
{
	int	i;

	i = -1;
	if (env->envp)
	{
		while (++i, env->envp[i])
			free(env->envp[i]);
		free(env->envp);
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (++i, arr[i])
			free(arr[i]);
		free(arr);
	}
}
