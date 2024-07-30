/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:50:22 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:43:36 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_count_digits(unsigned int num)
{
	int	counter;

	counter = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

int	ft_print_unsigned_int(unsigned int num)
{
	int		num_length;
	int		len;
	char	*result;

	num_length = ft_count_digits(num);
	len = num_length;
	result = (char *)malloc(sizeof(char) * (num_length + 1));
	if (!result)
		return (0);
	result[num_length] = '\0';
	while (num_length-- != 0)
	{
		result[num_length] = (num % 10) + '0';
		num /= 10;
	}
	ft_putstr_fd(result, 1);
	free(result);
	return (len);
}
