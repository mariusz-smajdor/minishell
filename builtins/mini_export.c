/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:40:43 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/20 15:13:43 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	is_valid_key(char *key)
{
	size_t	i;

	i = 0;
	while (key[i])
	{
		if (!((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= '0' && key[i] <= '9')))
			return (false);
		i++;
	}
	return (true);
}

static void	add_var(t_envp *envp, char *input)
{
	t_envp	*key_item;
	char	*key;
	char	*value;

	key = ft_strndup(input, ft_strchr(input, '=') - input);
	if (!key)
		return ;
	if (!is_valid_key(key))
	{
		printf("minishell: export: '%s': not a valid identifier\n", key);
		free(key);
		return ;
	}
	value = ft_strdup(ft_strchr(input, '=') + 1);
	if (!value)
	{
		free(key);
		return ;
	}
	key_item = search_var(envp, key);
	if (key_item)
	{
		free(key_item->value);
		key_item->value = ft_strdup(value);
	}
	else
		envp_add_back(&envp, key, value);
	free(key);
	free(value);
}

int	mini_export(t_envp *envp, t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while(cmd->av[i])
	{
		if (ft_strchr(cmd->av[i], '='))
			add_var(envp, cmd->av[i]);
		else if (!is_valid_key(cmd->av[i]))
		{
			printf("minishell: export: '%s': not a valid identifier\n", cmd->av[i]);
		}
		i++;
	}
	return (0);
}