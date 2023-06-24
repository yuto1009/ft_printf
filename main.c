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
        my_length = ft_printf("\\%%%dd%i %x%X%u %c %s%s%p%p%x\n", a, b, c, c, c, d, s, s2, s2, s2-count, e);
        original_length = printf("\\%%%dd%i %x%X%u %c %s%s%p%p%x\n", a, b, c, c, c, d, s, s2, s2, s2-count, e);
        ft_printf("my length is %d original length is %d\n", my_length, original_length);
        a++;b++;c++;d++;e++;
    }
    int num = 0;
    int my_len, ori_len;

	my_len = ft_printf("%x\n", num);
	ori_len =  printf("%x\n", num);
    ft_printf("mine is %X\n", num);
	printf("original is %X\n", num);

    ft_printf("%d %d\n", my_len, ori_len);

    return (0);
}