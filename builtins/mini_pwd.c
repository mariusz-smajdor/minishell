/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:06:45 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 08:27:31 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_pwd(t_env *env)
{
	char	*value;

	value = get_env(env, "PWD");
	if (!value || value[0] == '\0')
	{
		ft_putstr_fd("PWD variable is unset", 2);
		if (value[0] == '\0')
			free(value);
		return (1);
	}
	ft_putstr_fd(value, 1);
	ft_putstr_fd("\n", 1);
	free(value);
	return (0);
}
