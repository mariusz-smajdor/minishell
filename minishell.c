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
	char	*input;

	cmd = safe_malloc(sizeof(t_cmd));
	while (true)
	{
		input = readline("minishell$ ");
		if (!input)
			break ;
		process_input(cmd, input);
		add_history(input);
		free(input);
	}
	return (0);
}