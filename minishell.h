/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:03:24 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/16 18:53:48 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_cmd	t_cmd;

typedef enum e_ops
{
	PIPE,
	LT,
	GT,
	LTLT,
	GTGT,
	END,
}	t_ops;

typedef struct s_cmd
{
	char	**av;
	t_ops	op;
	t_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	t_token	*token;
	t_cmd	*cmd;
	char	**envp;
	bool	exit;
}	t_shell;

// UTILS
void	exit_program(const char *message, const int status);
bool	is_space(const char c);
bool	is_quote(const char c);
void	skip_spaces(char **input);
void	*safe_malloc(size_t size);

// PARSE
void	parse_input(t_shell *shell, char *input);
char	**fill_commands(char *input);

#endif
