/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:07:20 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/24 23:19:23 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *find_path(char *cmd)
{
	char *env_path;
	char *path;
	char **paths;
	
	env_path = getenv("PATH"); // do zmiany na wlasna funckcje ktora szuka w shell->envp
	paths = ft_split(env_path, ':');
	for (int i = 0; paths[i]; i++) // change to while
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
	}
	return (NULL);
}

int	get_filein(t_cmd *cmd)
{
	int fd;
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp->op == GT || tmp->op == GTGT)
	{
		if (tmp->op == GT)
			fd = open(tmp->next->av[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			fd = open(tmp->next->av[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
		tmp = tmp->next;
		if (tmp->op == GT || tmp->op == GTGT)
			close(fd);
		else
			return (fd);
	}
	return (1);
}

void	exec(t_shell *shell)
{
	pid_t	pid;
	int		filein;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		filein = get_filein(shell->cmd);
		if (filein != 1)
			dup2(filein, 1);
		if (mini_exec(shell, shell->cmd) == -1)
		{
			path = find_path(shell->cmd->av[0]);
			execve(path, shell->cmd->av, NULL);
		}
		else
			exit(0);
	}
	waitpid(pid, NULL, 0);
}
