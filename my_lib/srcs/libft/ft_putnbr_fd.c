/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:31:07 by mwiacek           #+#    #+#             */
/*   Updated: 2024/04/12 09:42:19 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	ft_print(char str, int fd)
{
	write (fd, &str, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_print('-', fd);
		ft_putnbr_fd(-(n / 10), fd);
		ft_print(-(n % 10) + '0', fd);
		return ;
	}
	if (n < 0)
	{
		ft_print('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_print(n % 10 + '0', fd);
	}
	else if (n < 10)
	{
		ft_print(n % 10 + '0', fd);
		return ;
	}
}
