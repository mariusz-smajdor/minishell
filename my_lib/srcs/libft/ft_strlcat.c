/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:59:46 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:42:39 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	total_len;
	size_t	i;
	size_t	j;

	dst_len = 0;
	if (!dst && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	total_len = dst_len + ft_strlen(src);
	if (size <= dst_len)
		return (total_len);
	i = dst_len;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (total_len);
}
