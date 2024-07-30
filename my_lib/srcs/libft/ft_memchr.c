/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:44:08 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:42:03 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	tmp_c;
	size_t			i;

	tmp_s = (unsigned char *) s;
	tmp_c = c;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == tmp_c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
