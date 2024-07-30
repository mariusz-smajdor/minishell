/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:13:37 by mwiacek           #+#    #+#             */
/*   Updated: 2024/06/29 23:52:09 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	b;

	b = nmemb * size;
	if (size && ((b / size) != nmemb))
		return (NULL);
	ptr = malloc(b);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, b);
	return (ptr);
}
