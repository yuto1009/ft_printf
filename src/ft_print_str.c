/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:03:26 by yutoendo          #+#    #+#             */
/*   Updated: 2023/11/03 23:12:37 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_str(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	else if (*s == '\0')
	{
		return (NULL_EXCEPTION);
	}
	ft_putstr_fd(s, STDOUT_FILENO);
	return ((int)ft_strlen(s));
}
