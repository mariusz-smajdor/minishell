/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:50:32 by mwiacek           #+#    #+#             */
/*   Updated: 2024/08/21 15:16:38 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_env(t_envp *envp)
{
	t_envp	*tmp;

	if (!envp)
		return (EXIT_FAILURE);
	tmp = envp;
	while (tmp)
	{
		ft_putstr_fd(tmp->key, STDIN_FILENO);
		ft_putchar_fd('=', STDIN_FILENO);
		ft_putstr_fd(tmp->value, STDIN_FILENO);
		ft_putchar_fd('\n', STDIN_FILENO);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
