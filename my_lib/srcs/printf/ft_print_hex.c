/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:08:27 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:43:19 by mwiacek          ###   ########.fr       */
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
		num /= 16;
		counter++;
	}
	return (counter);
}

int	ft_print_hex(unsigned int num, int is_lowercase)
{
	char	*result;
	char	*possible_letters;
	int		num_length;
	int		num_cpy;

	possible_letters = "0123456789abcdef";
	if (is_lowercase == 0)
		possible_letters = "0123456789ABCDEF";
	num_length = ft_count_digits(num);
	num_cpy = ft_count_digits(num);
	result = (char *)malloc(sizeof(char) * (num_length + 1));
	if (!result)
		return (0);
	result[num_length] = '\0';
	while (num_length-- > 0)
	{
		result[num_length] = possible_letters[num % 16];
		num /= 16;
	}
	ft_putstr_fd(result, 1);
	free(result);
	return (num_cpy);
}
