#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main(void){
    size_t count = 100;
    int a = INT_MAX;
    unsigned int b = INT_MIN;
    int c = -9999;
    char d = 30;
    char *s = NULL;
    char *s2 = "Hello_World!";
    int e = -10;
    int my_length, original_length;

    while(count--){
        my_length = ft_printf("\\%%%dd%i %x%X%u %c %s%s%p%p%x %X %x\n", a, b, c, c, c, d, s, s2, s2, s2-count, e, a, b);
        original_length = printf("\\%%%dd%i %x%X%u %c %s%s%p%p%x %X %x\n", a, b, c, c, c, d, s, s2, s2, s2-count, e, a, b);
        ft_printf("my length is %d original length is %d\n", my_length, original_length);
        a++;b++;c++;d++;e++;
    }
    
    return (0);
}