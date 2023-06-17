/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:09:09 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/17 20:40:47 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_upper_hex(unsigned int n){
    int num;
    if(n == 0) 
        return;

    put_upper_hex(n / 16);

    num = n % 16;
    
    if(num < 10)
        num += '0';
    else
        num += 'A' - 10;

    ft_putchar_fd(num, 1);
}

int print_upper_hex(va_list args){
    unsigned int num;
    num = va_arg(args, unsigned int);
    put_upper_hex(num);
    return 1;
}
