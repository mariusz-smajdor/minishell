/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:17:17 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/17 19:29:54 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t l;
	char *d;

	l = ft_strnlen(s, n);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, l);
	d[l] = 0;
	return (d);
}
