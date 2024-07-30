/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:29:40 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:42:13 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;
	int		i;

	tmp = b;
	i = 0;
	while (len > 0)
	{
		tmp[i] = c;
		i++;
		len--;
	}
	return (tmp);
}
