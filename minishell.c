/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	t_cmd	*cmd;
	t_token	*token;
	char	*input;

	while (true)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		tokenize(&token, ft_strtrim(input, " \t\n\r\v\f"));
		fill_commands(&cmd, &token);
		add_history(input);
		free(input);
	}
	return (0);
}
