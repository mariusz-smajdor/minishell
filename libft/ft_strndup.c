/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:17:17 by msmajdor          #+#    #+#             */
/*   Updated: 2024/08/17 19:18:40 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strndup(const char *s, size_t n)
{
	size_t l;
	char *d;

	l = strnlen(s, n);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	memcpy(d, s, l);
	d[l] = 0;
	return (d);
}
