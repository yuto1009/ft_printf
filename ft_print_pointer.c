/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:03:59 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/22 19:18:35 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	put_hex_pointer_utils(char *str)
// {
// 	size_t	start;
// 	int		str_length;

// 	start = 2;
// 	while (str[start] == '0' && start < 18)
// 		start++;
// 	write(1, str, 2);
// 	write(1, str + start, 19 - start);
// 	str_length = 21 - (int)start;
// 	return (str_length);
// }

static int	put_hex_pointer(void *p)
{
	const char			*hex;
	unsigned long long	address;
	char				str[19];
	size_t				i;

	size_t				start;
	int					str_length;
	hex = "0123456789abcdef";
	address = (unsigned long long)p;
	str[0] = '0';
	str[1] = 'x';
	i = 18;
	while (i > 1)
	{
		str[i] = hex[address % 16];
		address /= 16;
		i--;
	}
	start = 2;
	while (str[start] == '0' && start < 18)
		start++;
	write(1, str, 2);
	write(1, str + start, 19 - start);
	str_length = 21 - (int)start;
	// return (put_hex_pointer_utils(str));
	return str_length;
}

int	print_pointer(va_list args)
{
	void	*p;
	int		str_length;

	p = va_arg(args, void *);
	str_length = put_hex_pointer(p);
	return (str_length);
}
