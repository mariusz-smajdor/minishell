/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:41:22 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:43:44 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/printf.h"

int	ft_handle_placeholders(va_list *args, char c)
{
	size_t	length;

	length = 0;
	if (c == 'c')
		length += (ft_print_char(va_arg(*args, int)));
	if (c == 's')
		length += (ft_print_str(va_arg(*args, char *)));
	if (c == 'd' || c == 'i')
		length += (ft_print_int(va_arg(*args, int)));
	if (c == 'u')
		length += (ft_print_unsigned_int(va_arg(*args, unsigned int)));
	if (c == 'x' || c == 'X')
		length += (ft_print_hex(va_arg(*args, unsigned int), c == 'x'));
	if (c == 'p')
		length += (ft_print_pointer(va_arg(*args, void *)));
	if (c == '%')
		length += (ft_print_char('%'));
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	size_t			counter;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			counter += ft_handle_placeholders(&args, str[i + 1]);
			i++;
		}
		else
			counter += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
