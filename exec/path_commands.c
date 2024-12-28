/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 22:57:21 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/29 08:26:05 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

static bool	is_executable(struct stat file)
{
	if ((file.st_mode > 0) && (S_IEXEC & file.st_mode) && S_ISREG(file.st_mode))
	{
		if (file.st_mode & S_IXUSR)
			return (true);
		else
			ft_putstr_fd("file is not executable", 2);
	}
	else
		ft_putstr_fd("file not found", 2);
	return (false);
}

static int	find_bin(t_env *env, t_hell hell, char *bin_path, char **path)
{
	struct stat	file;
	int			i;

	i = -1;
	while (path && path[++i])
	{
		bin_path = join_path(path[i], hell.cmd);
		if (lstat(bin_path, &file) != -1)
		{
			free_arr(path);
			if (is_executable(file))
				return (execute_bin(bin_path, env, hell));
		}
		else
			free(bin_path);
	}
	return (1);
}

int	search_bin(t_env *env, t_hell hell) // maybe somewhere else
{
	char		*bin_path;
	char		**path;
	char		*tmp;
	int			ret_val;

	if (hell.cmd[0] == '.' || hell.cmd[0] == '/')
	{
		bin_path = get_absolute_path(hell.cmd, env);
		return (execute_bin(bin_path, env, hell));
	}
	tmp = get_env(env, "PATH");
	if (!tmp)
		return (1);
	path = ft_split(tmp, ':');
	free(tmp);
	bin_path = 0;
	ret_val = find_bin(env, hell, bin_path, path);
	if (ret_val == 1)
	{
		ft_putstr_fd("command not found\n", 2);
		free_arr(path);
	}
	return (ret_val);
}

static char	**set_argv(t_hell hell)
{
	char	**args;
	int		i;
	int		j;

	i = 0;
	while (hell.argv[i])
		i++;
	args = safe_malloc(sizeof(char *) * (i + 3));
	i = 0;
	args[i] = ft_strdup(hell.cmd);
	if (hell.flags)
		args[++i] = ft_strjoin("-", hell.flags);
	j = 0;
	if (hell.argv)
	{
		while (hell.argv[j])
			args[++i] = ft_strdup(hell.argv[j++]);
	}
	args[++i] = NULL;
	return (args);
}

int	execute_bin(char *bin_path, t_env *env, t_hell hell)
{
	pid_t	pid;
	int		result;
	char	**argv;

	pid = fork();
	argv = 0;
	result = 0;
	if (pid == 0)
	{
		argv = set_argv(hell);
		result = execve(bin_path, argv, env->envp);
	}
	else if (pid < 0)
	{
		free(bin_path);
		ft_putstr_fd("fork failed", 2);
		return (-1);
	}
	wait(&result);
	free(bin_path);
	free_arr(argv);
	env->last_result = result;
	return (result);
}
