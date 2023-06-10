#include <stdarg.h>
#include <stdio.h>

void print_two(const char *format, ...)
{
    va_list args1, args2;

    va_start(args1, format);
    va_copy(args2, args1);

    // 最初の引数リストを使用します
    vprintf(format, args1);
    va_end(args1);

    printf("\n");

    // コピーした引数リストを再度使用します
    vprintf(format, args2);
    va_end(args2);
}

int main(void)
{
    print_two("Int: %d, Double: %.2f, Char: %c", 5, 2.3, 'A');

    return 0;
}