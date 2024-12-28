/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:57:39 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 08:18:35 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	await_processes(t_hell *hell, t_env *env)
{
	int	i;
	int	exit_status;

	i = -1;
	while (hell[++i].cmd)
		wait(&exit_status);
	if (hell[i - 1].pid == 0)
		return (env->last_result);
	return (0);
}

static int	execute_command(t_env *env, t_hell hell, bool fork)
{
	if (fork)
	{
		if (ft_strncmp(hell.cmd, "echo", ft_strlen(hell.cmd)) == 0)
			return (mini_echo(hell));
		if (ft_strncmp(hell.cmd, "pwd", ft_strlen(hell.cmd)) == 0)
			return (mini_pwd(env));
		if (ft_strncmp(hell.cmd, "env", ft_strlen(hell.cmd)) == 0)
			return (mini_env(env));
		return (search_bin(env, hell));
	}
	if (ft_strncmp(hell.cmd, "cd", ft_strlen(hell.cmd)) == 0)
		return (mini_cd(env, hell));
	if (ft_strncmp(hell.cmd, "exit", ft_strlen(hell.cmd)) == 0)
		return (mini_exit(env, hell));
	if (ft_strncmp(hell.cmd, "export", ft_strlen(hell.cmd)) == 0)
		return (mini_export(env, hell));
	if (ft_strncmp(hell.cmd, "unset", ft_strlen(hell.cmd)) == 0)
		return (mini_unset(env, hell));
	return (-1);
}


static void	execute_forked(t_env *env, t_hell *hell, int i)
{
	hell[i].pid = fork();
	if (hell[i].pid == -1)
		exit_program(env, "fork failed\n", 2);
	if (hell[i].pid == 0)
	{
		close_unused_pipes(hell, i);
		redirect(&(hell[i]));
		if (hell[i + 1].cmd)
			dup2(hell[i].fd[1], STDOUT_FILENO);
		if (i != 0)
			dup2(hell[i - 1].fd[0], STDIN_FILENO);
		env->last_result = execute_command(env, hell[i], true);
		close(hell[i].fd[1]);
		if (i != 0)
			close(hell[i - 1].fd[0]);
		exit(0);
	}
}

void	execute(t_env *env, t_hell *hell)
{
	int	i;
	int	result;

	create_pipes(hell, env);
	i = 0;
	while (hell[i].cmd)
	{
		result = execute_command(env, hell[i], false);
		hell[i].pid = 0;
		if (result == -1)
			execute_forked(env, hell, i);
		else
			env->last_result = result;
		i++;
	}
	close_pipes(hell);
	env->last_result = await_processes(hell, env);
}
