/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:53:49 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 08:36:00 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static bool	is_overflow(char *str)
{
	int	val;
	int	i;
	int	digit;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (ft_isdigit(str[i]) && str[i + 1] == '\0')
		return (true);
	val = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (val > (INT_MAX - digit) / 10)
				return (true);
			val = val * 10 + digit;
			i++;
		}
		else
			return (true);
	}
	return (false);
}

static bool	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	mini_exit(t_env *env, t_hell hell)
{
	int	status;

	if (!hell.argv[0])
	{
		free_env(env);
		exit(0);
	}
	if (hell.argv[0] && hell.argv[1])
	{
		ft_putstr_fd("too many arguments\n", 2);
		return (1);
	}
	if (!is_num(hell.argv[0]) || is_overflow(hell.argv[0]))
	{
		ft_putstr_fd("numeric argument required\n", 2);
		return (1);
	}
	else
	{
		free_env(env);
		status = ft_atoi(hell.argv[0]);
		if (status < 0)
			exit(0);
		exit(status);
	}
}
