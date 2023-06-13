/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuendo <yuendo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:43 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/13 16:43:02 by yuendo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_printf(const char *str, ...){
    va_list args;
    size_t i;
    char c;
    char *s;

    if(!str){
        write(1, "some kind of error message?\n", 28);
        return 1;
    }
    va_start(args, str);
    i = 0;
    while(str[i]){
        if(str[i] == '%' && str[i+1] == 'c'){
            c = va_arg(args, int);
            write(1, &c, 1);
        }
        else if(str[i] == '%' && str[i+1] == 's'){
            s = va_arg(args, char*);
            write(1, s, ft_strlen(s));
        }
        else if(str[i] == '%' && str[i+1] == 'p'){
            s = va_arg(args, void*);
            write(1, s, ft_strlen(s));
        }
        i++;
    }
    va_end(args);
    return 0;
}

#include <stdio.h>

int main(void){
    char a = 'a';
    char *s = "hello\n";
    ft_printf("%c\n", a);
    ft_printf("%s\n", s);
    ft_printf("%p\n", s);
    return 0;
}