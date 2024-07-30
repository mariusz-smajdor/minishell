/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:33:12 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:43:02 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_handle_wrong_start(void)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * 1);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlen;
	size_t	i;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen(s);
	i = 0;
	if (start >= strlen)
		return (ft_handle_wrong_start());
	if (strlen - start < len)
		len = strlen - start;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (len > i)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
