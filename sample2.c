#include "ft_printf.h"

#include <stdio.h>
int count_va_list(va_list args){
    size_t i;
    int p;

    i = 0;
    while(1){
        p = va_arg(args, void*);
        if(!p)
            break;
        i++;
    }
    va_end(args);
    return i;
}
int ft_printf(const char *format, ...){
    va_list args, args_copy;
    char *p;
    size_t i;
    size_t count;

    va_start(args, format);
    va_copy(args_copy, args);
    count = count_va_list(args_copy);
    i = 0;
    while(1){
        p = va_arg(args, void*);
        if(!p)
            break;
        printf("%s", p);
        i++;
    }
    va_end(args);
    return count;
}
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
#include <stdio.h>
int main(void){
    int a;

    a = ft_printf("Hello\n", "good\n", "Bye\n", "Banana\n");
    printf("number of arguments is %d\n", a);
    return 0;
}