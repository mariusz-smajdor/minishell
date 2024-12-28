/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:57:45 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/27 20:16:21 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_absolute_path(char *script, t_env *env)
{
	char	*tmp;
	char	*tmp2;
	char	*result;

	if (script[0] == '.')
	{
		tmp = ft_substr(script, 1, ft_strlen(script) - 1);
		tmp2 = get_env(env, "PWD");
		result = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
		return (result);
	}
	else
		return (script);
}

char	*join_path(char *p1, char *p2)
{
	char	*tmp2;
	char	*tmp1;

	if (!p2 || !p1)
		return (NULL);
	if (!ft_strncmp(p1, "/", 1))
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2));
		else
		{
			tmp1 = ft_strjoin(p1, "/");
			tmp2 = ft_strjoin(tmp1, p2);
			free(tmp1);
			return (tmp2);
		}
	}
	else
	{
		if (p2[0] == '/')
			return (ft_strjoin(p1, p2 + 1));
		else
			return (ft_strjoin(p1, p2));
	}
}
