/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:48:53 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/17 20:33:49 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int ft_printf(const char *, ...);
int is_valid_args(const char *str, va_list args);
int print_upper_hex(va_list args);
int print_lower_hex(va_list args);
int print_unsigned_int(va_list args);
int print_integer(va_list args);
int print_pointer(va_list args);
int print_str(va_list args);
int print_char(va_list args);


#endif