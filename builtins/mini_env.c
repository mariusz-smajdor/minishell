/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:07:48 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/26 22:22:08 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_env(t_env *env)
{
	int	i;

	if (!env->envp)
		return (0);
	i = -1;
	while (++i, env->envp[i])
		printf("%s\n", env->envp[i]);
	return (0);
}
