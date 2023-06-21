/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:05:28 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/21 20:05:11 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list args)
{
	int		num;
	char	*s;
	int		str_length;

	num = va_arg(args, int);
	s = ft_itoa(num);
	if (!s)
		return (-1);
	ft_putstr_fd(s, 1);
	str_length = (int)ft_strlen(s);
	free(s);
	return (str_length);
}
