/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:02:05 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/03 23:12:15 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(va_list args)
{
	unsigned char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}
