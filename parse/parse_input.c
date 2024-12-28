/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:33:51 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 10:43:19 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	expand_env(t_env *env, char **input, char **result)
{
	int		i;
	int		j;
	char	*name;
	char	*value;

	i = env->x + 1;
	while (is_env_char((*input)[i]) && !is_quote((*input)[i])
		&& (*input)[i])
		i++;
	name = ft_substr(*input, env->x + 1, i - env->x - 1);
	if (ft_strncmp(name, "?", 1) == 0)
		value = ft_itoa(env->last_result);
	else
		value = get_env(env, name);
	j = 0;
	if (value)
		while (value[j])
			(*result)[env->y++] = value[j++];
	env->x += ft_strlen(name) + 1;
	free(name);
	free(value);
}

static void	handle_envp(t_env *env, char **input, char **result)
{
	env->x = 0;
	env->y = 0;
	while ((*input)[env->x])
	{
		if ((*input)[env->x] == '\'' && !check_unclosed_quotes(*input, env->x))
		{
			(*result)[env->y++] = (*input)[env->x++];
			while ((*input)[env->x] && (*input)[env->x] != '\'')
				(*result)[env->y++] = (*input)[env->x++];
			if ((*input)[env->x] == '\'')
				(*result)[env->y++] = (*input)[env->x++];
		}
		else if ((*input)[env->x] == '$' && (*input)[env->x + 1] != ' ')
			expand_env(env, input, result);
		else
			(*result)[env->y++] = (*input)[env->x++];
	}
	(*result)[env->y] = '\0';
}

static void	expand_envp(t_env *env, char **input)
{
	char	*result;

	result = safe_malloc(ft_strlen(*input) * sizeof(char *));
	handle_envp(env, input, &result);
	free(*input);
	*input = result;
}

static void trim_input(char **input)
{
	char	*result;
	char	quote;

	result = safe_malloc(ft_strlen(*input) + 1);
	trim_spaces(input, &quote, &result);
	free(*input);
	if (quote != '\0')
	{
		free(result);
		*input = NULL;
	}
	else
		*input = result;
}

t_hell	*parse_input(t_env *env, char **input)
{
	trim_input(input);
	if (!*input || !**input)
		return (NULL);
	expand_envp(env, input);
	if (!input)
		exit_program(env, "Invalid input", 1);
	return (init_hell(input));
}
