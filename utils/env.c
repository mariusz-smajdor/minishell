/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:13:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/27 00:47:28 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_env_char(char c)
{
	return (ft_isalnum(c) || c == '?' || c == '_');
}

char	*get_env(t_env *env, char *value)
{
	int			i;
	size_t		tmp;

	i = 0;
	while (env->envp[i])
	{
		tmp = ft_strchrn(env->envp[i], '=');
		if (ft_strncmp(env->envp[i], value, ft_strlen(value)) == 0
			&& tmp == ft_strlen(value))
			return (ft_strdup(env->envp[i] + tmp + 1));
		i++;
	}
	return (NULL);
}

void	add_env(t_env *env, char *name, char *val)
{
	char	**new;
	char	*tmp;
	int		i;

	i = -1;
	while (++i, env->envp[i])
		;
	new = safe_malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (++i, env->envp[i])
		new[i] = ft_strdup(env->envp[i]);
	tmp = ft_strjoin(name, "=");
	new[i] = ft_strjoin(tmp, val);
	free(tmp);
	new[++i] = 0;
	free_arr(env->envp);
	env->envp = new;
}

void	del_env(t_env *env, char *name)
{
	char	**new;
	int		tmp;
	int		i;
	int		j;

	while (++i, env->envp[i])
		;
	new = safe_malloc(sizeof(char *) * (i + 1));
	i = -1;
	j = 0;
	while (env->envp[++i])
	{
		tmp = ft_strchrn(env->envp[i], '=');
		if (ft_strncmp(env->envp[i], name, ft_strlen(name)) == 0
			&& (size_t)tmp == ft_strlen(name))
			continue ;
		new[j] = ft_strdup(env->envp[i]);
		j++;
	}
	new[j] = NULL;
	free_arr(env->envp);
	env->envp = new;
}
