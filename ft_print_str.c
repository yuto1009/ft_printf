/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:03:26 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/21 19:59:14 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else if (*s == '\0')
	{
		return (-2);
	}
	ft_putstr_fd(s, 1);
	return ((int)ft_strlen(s));
}
