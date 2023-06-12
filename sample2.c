#include "ft_printf.h"

int ft_printf(const char *format, ...){
    va_list args;
    va_start(args, format);
    while(*format)
        write(1, format++, 1);
    format = va_arg(args, char*);
    while(*format)
        write(1, format++, 1);
    va_end(args);
    return 0;
}

#include <stdio.h>
int main(void){
    ft_printf("Hello\n", "good\n");
    return 0;
}