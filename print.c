#include <stdio.h>

int main(void){
    unsigned int num = 2147483648;
    unsigned int num2 = -1;
    int num3 = (int)num2;
    unsigned int num4 = 4294967295;
    int num5 = 1000;
    printf("%u\n", num);    // 2147483648
    printf("%u\n", num2);   // 4294967295
    printf("%u\n", num3);   // 4294967295
    printf("%u\n", num4);   // 4294967295
    // printf("%u", -4294967295);
    printf("%x\n", num5);
    printf("%X\n", num5);
    return 0;
}