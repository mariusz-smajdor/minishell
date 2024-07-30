/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:39:02 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:42:59 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_to_trim(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	end_index = ft_strlen(s1);
	while (ft_to_trim(s1[start_index], set))
		start_index++;
	if (start_index == end_index)
		return (ft_strdup(""));
	while (ft_to_trim(s1[end_index - 1], set))
		end_index--;
	trimmed = ft_substr(s1, start_index, end_index - start_index);
	return (trimmed);
}
