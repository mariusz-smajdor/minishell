/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inlines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool is_operator(const char c)
{
	return (c == '|' || c == '<' || c == '>');
}

bool is_space(const char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

bool is_quote(const char c)
{
	return (c == '\'' || c == '\"' || c == '`');
}
