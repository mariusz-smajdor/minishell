/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:01:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/18 15:31:06 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

		///////////////////////////////////////////////////
		t_cmd *tempcmd = shell.cmd;
		while (tempcmd) {
			for (size_t i = 0; tempcmd->av[i]; i++)
				printf("av: %s ", tempcmd->av[i]);
			printf("op: %d\n", tempcmd->op);
			tempcmd = tempcmd->next;
			printf("next\n");
		}		
		///////////////////////////////////////////////////
		
		add_history(input);
		free(input);
	}
	return (0);
}
