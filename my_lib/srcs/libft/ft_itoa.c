/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:51 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:41:39 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_numlen(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	nbr;
	int				num_length;
	int				is_negative;

	num_length = ft_numlen(n);
	is_negative = n < 0;
	nbr = n;
	if (n < 0)
		nbr *= -1;
	result = (char *)malloc(sizeof(char) * (num_length + 1));
	if (result == NULL)
		return (NULL);
	result[num_length] = '\0';
	while (num_length-- > 0)
	{
		result[num_length] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (is_negative == 1)
		result[0] = '-';
	return (result);
}
