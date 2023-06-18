#include <stdio.h>

int main(void){
    char *s = "Hello\n";
    char *s2 = "Helsslo\n";
    char *s3 = "Hsssello\n";
    int a = 1000;
    printf("%p\n", s);
    printf("%p\n", s2);
    printf("%p\n", s);
    printf("%p\n", s);
    return 0;
}