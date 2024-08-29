/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:25:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 08:05:26 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_envp(t_env *env, char **envp)
{
	int	i;

	i = -1;
	while (++i, envp[i])
		;
	env->envp = safe_malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (++i, envp[i])
		env->envp[i] = ft_strdup(envp[i]);
	env->envp[i] = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_hell	*hell;
	t_env	env;

	((void)argc, (void)argv);
	init_envp(&env, envp);
	while (true)
	{
		input = readline("hell$ ");
		if (!input)
			break ;
		add_history(input);
		hell = parse_input(&env, &input);
		if (!hell)
			continue ;
		execute(&env, hell);
		free_hell(hell);
		free(input);
	}
	return (0);
}
