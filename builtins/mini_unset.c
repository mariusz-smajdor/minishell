/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:59:06 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 08:27:26 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_unset(t_env *env, t_hell hell)
{
	char	*key;
	int		equal_index;

	if (!hell.argv[0] || hell.argv[1])
		return (1);
	equal_index = ft_strchrn(hell.argv[0], '=');
	if (!equal_index)
		return (1);
	key = ft_substr(hell.argv[0], 0, equal_index);
	del_env(env, key);
	free(key);
	return (0);
}
