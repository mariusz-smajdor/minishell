/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:56:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 08:27:39 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_export(t_env *env, t_hell hell)
{
	char	*key;
	char	*value;
	int		equal_index;

	if (!hell.argv[0] || hell.argv[1])
		return (1);
	equal_index = ft_strchrn(hell.argv[0], '=');
	if (!equal_index)
		return (1);
	key = ft_substr(hell.argv[0], 0, equal_index);
	del_env(env, key);
	value = ft_substr(hell.argv[0], equal_index + 1,
			ft_strlen(hell.argv[0]) - ft_strlen(key) - 1);
	add_env(env, key, value);
	free(key);
	free(value);
	return (0);
}