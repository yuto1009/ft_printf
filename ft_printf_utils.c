/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:58:04 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/17 23:12:12 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int print_format_specifier(char format, va_list args){
    int is_format_specifier;

    is_format_specifier = 0;
    if(format == 'c')
        is_format_specifier = print_char(args);
    else if(format == 's')
        is_format_specifier =  print_str(args);
    else if(format == 'p')
        is_format_specifier = print_pointer(args);
    else if(format == 'd' || format == 'i')
        is_format_specifier = print_integer(args);
    else if(format == 'u')
        is_format_specifier = print_unsigned_int(args);
    else if(format == 'x')
        is_format_specifier = print_lower_hex(args);
    else if(format == 'X')
        is_format_specifier = print_upper_hex(args);
    else if(format == '%'){
        ft_putchar_fd('%', 1);
        is_format_specifier++;
    }
    else{
        write(1, "unhandled or incomplete format specifier\n", 41);
    }
    return is_format_specifier;
}

int is_valid_args(const char *str, va_list args){
    int is_format_specifier;
    int occurrence_of_format_specifier;

    is_format_specifier = 0;
    occurrence_of_format_specifier = 0;
    while(str && *str){
        if(*str == '%' && (str+1) && *(str + 1)){
            is_format_specifier =  print_format_specifier(*(str+1), args);
            if(!is_format_specifier)
                return 0;   // This is when something went wrong like malloc failure
            occurrence_of_format_specifier++;
        }
        else if(*str == '%'){
            write(1, "incomplete format specifier\n", 29);
            return 0;
        }
        else
            ft_putchar_fd(*str, 1);
        if(is_format_specifier)
            str++;
        if(*str != '\0')
            str++;
        is_format_specifier = 0;
    }
    return occurrence_of_format_specifier;
}