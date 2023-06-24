/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:07:08 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/24 14:54:59 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>	// DELETE

// todo : display hex and return length
static int	put_lower_hex(unsigned int n)
{
	int length;
	int num;
	
	while(n == 0){
		num = n / 16;
		ft_putchar_fd(num, fd);
		num = n % 16;
		ft_putchar_fd(num % )
	}
}

int	print_lower_hex(va_list args)
{
	unsigned int	num;
	int				str_length;

	num = va_arg(args, unsigned int);
	str_length = put_lower_hex(num);
	return (str_length);
}
