/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:00:36 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 08:34:22 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_flags(t_hell *hell, bool *add_nl)
{
	int	i;

	i = 0;
	if (hell->flags)
	{
		while (hell->flags[i])
		{
			if (hell->flags[i++] != 'n')
			{
				ft_putstr_fd("invalid flag\n", 2);
				return (-1);
			}
		}
		if (hell->flags[0] == 'n')
			*add_nl = false;
	}
	return (0);
}

int	mini_echo(t_hell hell)
{
	bool	add_nl;
	int		status;
	int		i;

	i = 0;
	add_nl = true;
	status = check_flags(&hell, &add_nl);
	if (hell.argv && hell.argv[0] != NULL)
	{
		ft_putstr_fd(hell.argv[i], 1);
		i++;
		while (hell.argv[i])
		{
			ft_putstr_fd(" ", 1);
			ft_putstr_fd(hell.argv[i], 1);
			i++;
		}
	}
	if (add_nl)
		ft_putstr_fd("\n", 1);
	return (status);
}
