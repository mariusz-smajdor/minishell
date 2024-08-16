/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:01:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/15 13:39:28 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_shell(t_shell *shell, char **envp)
{
	shell->token = malloc(sizeof(t_token));
	shell->cmd = malloc(sizeof(t_cmd));
	shell->envp = envp;
	shell->exit = false;
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char	*input;
	t_shell	shell;

	init_shell(&shell, envp);
	while (shell.exit == false)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		parse_input(&shell, ft_strtrim(input, " \t\n\r\v\f"));
		add_history(input);
		free(input);
	}
	return (0);
}