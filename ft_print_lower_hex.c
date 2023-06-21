/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:07:08 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/21 19:45:00 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_lower_hex(unsigned int n)
{
	int	num;
	int	length;

	length = 0;
	if (n == 0)
		return (length);
	length = put_lower_hex(n / 16);
	num = n % 16;
	if (num < 10)
		num += '0';
	else
		num += 'a' - 10;
	ft_putchar_fd(num, 1);
	return (length + 1);
}

int	print_lower_hex(va_list args)
{
	unsigned int	num;
	int				str_length;

	num = va_arg(args, unsigned int);
	str_length = put_lower_hex(num);
	return (str_length);
}
