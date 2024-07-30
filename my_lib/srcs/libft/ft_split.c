/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:50:03 by mwiacek           #+#    #+#             */
/*   Updated: 2024/06/29 23:52:42 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	malloc_handler(char **result, int pos, int buffer)
{
	int	i;

	i = 0;
	result[pos] = malloc(buffer);
	if (result[pos] == NULL)
	{
		while (i < pos)
			free(result[i++]);
		free(result);
		return (1);
	}
	return (0);
}

int	copy_words(char **result, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (malloc_handler(result, i, len + 1))
				return (1);
			ft_strlcpy(result[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

size_t	count_words(char const *s, char c)
{
	size_t	words;
	int		new_word;

	words = 0;
	while (*s)
	{
		new_word = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (new_word == 0)
			{
				words++;
				new_word = 1;
			}
			s++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;

	if (!s)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[words] = NULL;
	if (copy_words(result, s, c))
		return (NULL);
	return (result);
}
