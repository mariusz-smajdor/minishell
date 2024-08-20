/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:03:24 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/18 15:37:21 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef enum e_ops
{
	PIPE,
	LT,
	GT,
	LTLT,
	GTGT,
	END,
}	t_ops;

typedef struct s_envp	t_envp;
typedef struct s_cmd	t_cmd;

typedef struct s_envp
{
	char	*key;
	char	*value;
	t_envp	*next;
}	t_envp;

typedef struct s_cmd
{
	char	**av;
	t_ops	op;
	t_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	t_cmd	*cmd;
	t_envp	*envp;
	bool	exit;
}	t_shell;

void	init_shell(t_shell *shell, char **envp);

// PARSE
void	parse_input(t_shell *shell, char *input);
char	**fill_commands(t_shell *shell, char *input);
size_t	get_commands_len(char *input);
size_t	get_command_len(t_shell *shell, char *input);
size_t	get_env_len(t_shell *shell, char **input);
void	parse_commands(t_shell *shell, char **commands);

// UTILS
void	exit_program(const char *message, const int status);
bool	is_space(const char c);
bool	is_quote(const char c);
void	skip_spaces(char **input);
void	*safe_malloc(size_t size);
char	*search_envp(char **envp, char *key);

// BUILTINS
int		mini_cd(t_cmd *cmd);
int		mini_echo(t_cmd *cmd, char **argv);
int		mini_env(t_cmd *cmd);
int		mini_exec(t_cmd *cmd);
int		mini_pwd(t_cmd *cmd);

#endif
