/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:58:04 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/21 19:57:11 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format_specifier(char format, va_list args)
{
	int	str_length;

	str_length = 0;
	if (format == 'c')
		str_length = print_char(args);
	else if (format == 's')
		str_length = print_str(args);
	else if (format == 'p')
		str_length = print_pointer(args);
	else if (format == 'd' || format == 'i')
		str_length = print_integer(args);
	else if (format == 'u')
		str_length = print_unsigned_int(args);
	else if (format == 'x')
		str_length = print_lower_hex(args);
	else if (format == 'X')
		str_length = print_upper_hex(args);
	else if (format == '%')
	{
		ft_putchar_fd('%', 1);
		str_length++;
	}
	else
		str_length = -1;
	return (str_length);
}

int	is_valid_args(char *str, va_list args)
{
	int	is_format_specifier;
	int	str_length;

	is_format_specifier = 0;
	str_length = 0;
	while (str && *str)
	{
		if (*str == '%' && (str + 1) && *(str + 1))
		{
			is_format_specifier = print_format_specifier(*(str + 1), args);
			if (is_format_specifier == -1)
			{
				write(1, "malloc failure or incomplete format specifier\n", 46);
				return (str_length + 46);
			}
			if (is_format_specifier != -2)
				str_length += is_format_specifier;
		}
		else if (*str == '%')
		{
			write(1, "incomplete format specifier\n", 29);
			return (str_length + 29);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str_length++;
		}
		if (is_format_specifier > 0 || is_format_specifier == -2)
			str++;
		if (*str != '\0')
			str++;
		is_format_specifier = 0;
	}
	return (str_length);
}
