/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:02:05 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/28 15:58:53 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list args)
{
	unsigned char	c;

	c = va_arg(args, int);
	if (c == 0)
	{
		return (NULL_EXCEPTION);
	}
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
