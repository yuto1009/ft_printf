/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:43 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/13 00:20:44 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...){
    va_list args;

    if(!str){
        write(1, "some kind of error message?\n", 28);
        return 1;
    }
    va_start(args, str);
    while(*str){
        write(1, str++, 1);
    }
    str = va_arg(args, char*);
    while(*str)
        write(1, str++, 1);
    va_end(args);
    return 0;
}

#include <stdio.h>
#include <assert.h>
int main(void){
    ft_printf(NULL);
    // printf(NULL);
    ft_printf("Hello\n", "good\n");
    // printf("a\t");
    // printf("b\v");
    // printf("c\f");
    // printf("d\r");
    return 0;
}