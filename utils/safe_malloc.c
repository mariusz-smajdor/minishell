/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 22:15:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/06/03 22:15:01 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*safe_malloc(size_t size)
{
    void	*ptr;

    ptr = malloc(size);
    if (!ptr)
        exit_program("Memory allocation failed!", EXIT_FAILURE);
    return (ptr);
}


3


123123123
hjkhjkhjk

store = asdasdasd

map_str = str = 
map = [][][]