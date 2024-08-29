/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:25:23 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/28 13:52:40 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_env
{
	char	**envp;
	int		last_result;
	int		x;
	int		y;
}	t_env;

typedef struct s_hell
{
	char	**argv;
	char	*cmd;
	char	*flags;
	int		fd[2];
	int		pid;
}	t_hell;

// UTILS
void	free_arr(char **arr);
void	free_env(t_env *env);
void	free_hell(t_hell *hell);
void	*safe_malloc(size_t size);
void	exit_program(t_env *env, char *msg, int status);
char	*get_env(t_env *env, char *value);
void	add_env(t_env *env, char *name, char *val);
void	del_env(t_env *env, char *name);
bool	is_env_char(char c);
int		words_count(char const *s, char c);

// PARSING
t_hell	*parse_input(t_env *env, char **input);
void	trim_spaces(char **input, char *quote, char	**result);
int		check_unclosed_quotes(char *str, int n);
int		is_quote(char c);
t_hell	*init_hell(char **input);
char	**validate_input(char **input);
void	add_arg(t_hell *hell, int *k, char *arg);
int		count_args(char *str_com, int i);

// BUILTINS
int		mini_cd(t_env *env, t_hell hell);
int		mini_echo(t_hell hell);
int		mini_env(t_env *env);
int		mini_exit(t_env *env, t_hell hell);
int		mini_export(t_env *env, t_hell hell);
int		mini_pwd(t_env *env);
int		mini_unset(t_env *env, t_hell hell);

// EXECUTION
void	execute(t_env *env, t_hell *hell);
void	create_pipes(t_hell *hell, t_env *env);
void	close_pipes(t_hell *hell);
void	close_unused_pipes(t_hell *hell, int i);
int		search_bin(t_env *env, t_hell hell);
void	redirect(t_hell *hell);
char	*get_absolute_path(char *script, t_env *env);
int		execute_bin(char *bin_path, t_env *env, t_hell hell);
char	*join_path(char *p1, char *p2);

#endif
