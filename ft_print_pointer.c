/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:03:59 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/17 20:04:58 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_hex_pointer(void *p){
    const char *hex = "0123456789abcdef";
    unsigned long long address = (unsigned long long)p;
    char str[19];
    size_t i;
    size_t start;

    str[0] = '0';
    str[1] = 'x';
    i = 18;
    while(i > 1){
        str[i] = hex[address % 16];
        address /= 16;
        i--;
    }
    start = 2;
    while(str[start] == '0' && start < 18)
        start++;
    write(1, str, 2);
    write(1, str+start, 19-start);
}

int print_pointer(va_list args){
    void *p;

    p = va_arg(args, void*);
    put_hex_pointer(p);
    return 1;
}