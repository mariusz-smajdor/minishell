/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:56:31 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/25 21:05:16 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exit_program(t_env *env, char *msg, int status)
{
	free_env(env);
	if (status)
	{
		printf("%s\n", msg);
		exit(status);
	}
	exit(status);
}
