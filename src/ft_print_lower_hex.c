/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:07:08 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/03 23:12:24 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	put_lower_hex(unsigned int n, int str_length)
{
	int	num;

	num = n % 16;
	n = n / 16;
	if (n > 0)
	{
		str_length = put_lower_hex(n, str_length);
	}
	if (num < 10)
	{
		ft_putchar_fd(num + '0', STDOUT_FILENO);
		str_length++;
	}
	else
	{
		ft_putchar_fd('a' + num - 10, STDOUT_FILENO);
		str_length++;
	}
	return (str_length);
}

int	print_lower_hex(va_list args)
{
	unsigned int	num;
	int				str_length;

	str_length = 0;
	num = va_arg(args, unsigned int);
	str_length = put_lower_hex(num, str_length);
	return (str_length);
}
