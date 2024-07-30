/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:19:23 by mwiacek           #+#    #+#             */
/*   Updated: 2024/03/16 17:29:46 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <inttypes.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_int(int num);
int	ft_print_unsigned_int(unsigned int num);
int	ft_print_hex(unsigned int num, int is_lowercase);
int	ft_print_pointer(void *ptr);

#endif
