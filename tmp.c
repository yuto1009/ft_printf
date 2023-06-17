#include <stdlib.h>
#include <stdio.h>

#include <stdarg.h>
#include <stdio.h>

void print_hex(unsigned int n) {
    int num;
    if(n == 0) return;

    print_hex(n / 16);

    num = n % 16;
    
    // Convert numerical digit to hexadecimal representation
    if(num < 10)
        num += '0';
    else
        num += 'A' - 10;

    putchar(num);
}

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'x') {
                unsigned int i = va_arg(args, unsigned int);
                if(i == 0)
                    putchar('0');
                else
                    print_hex(i);
            }
        } else {
            putchar(*format);
        }
        format++;
    }

    va_end(args);
}

int main() {
    my_printf("Hello %x World\n", -2000);
    return 0;
}
