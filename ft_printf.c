/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:43 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/21 19:52:53 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (s == NULL)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }
// void	ft_putstr_fd(char *s, int fd)
// {
// 	if (s && *s)
// 		write(fd, s, ft_strlen(s));
// }

// static unsigned int	my_getdigit(long int n) // INCLUDED IN UNSINGED INT
// {
// 	unsigned int	digit;

// 	digit = 0;
// 	if (n <= 0)
// 	{
// 		n /= -1;
// 		digit++;
// 	}
// 	while (n > 0)
// 	{
// 		n /= 10;
// 		digit++;
// 	}
// 	return (digit);
// }

// static char	my_tostr(int n) // INCLUDED IN UNSINGED INT
// {
// 	char	s;

// 	s = n + '0';
// 	return (s);
// }

// char	*ft_itoa(int num)
// {
// 	char			*s;
// 	unsigned int	digit;
// 	unsigned int	i;
// 	long int		n;

// 	n = num;
// 	digit = my_getdigit(n);
// 	s = malloc(sizeof(char) * (digit + 1));
// 	if (!s)
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		s[0] = '-';
// 		n /= -1;
// 	}
// 	s[digit] = '\0';
// 	i = digit - 1;
// 	if (n == 0)
// 		s[i] = '0';
// 	while (n > 0)
// 	{
// 		s[i--] = my_tostr(n % 10);
// 		n /= 10;
// 	}
// 	return (s);
// }

// // Function above are from libft and should be deleted before handing in

// static int put_hex_pointer(void *p){
//     const char *hex = "0123456789abcdef";
//     unsigned long long address = (unsigned long long)p;
//     char str[19];
//     size_t i;
//     size_t start;
//     int str_length;

//     str[0] = '0';
//     str[1] = 'x';
//     i = 18;
//     while(i > 1){
//         str[i] = hex[address % 16];
//         address /= 16;
//         i--;
//     }
//     start = 2;
//     while(str[start] == '0' && start < 18)
//         start++;
//     write(1, str, 2);
//     write(1, str+start, 19-start);
//     str_length = 21 - (int)start;
//     return (str_length);
// }

// static char	*uitoa(unsigned int num)
// {
// 	char			*s;
// 	unsigned int	digit;
// 	unsigned int	i;
// 	long int		n;

// 	n = num;
// 	digit = my_getdigit(n);
// 	s = malloc(sizeof(char) * (digit + 1));
// 	if (!s)
// 		return (NULL);
// 	s[digit] = '\0';
// 	i = digit - 1;
// 	if (n == 0)
// 		s[i] = '0';
// 	while (n > 0)
// 	{
// 		s[i--] = my_tostr(n % 10);
// 		n /= 10;
// 	}
// 	return (s);
// }

// static int put_lower_hex(unsigned int n){
//     int num;
//     int length;

//     length = 0;
//     if(n == 0)
//         return (length);

//     length = put_lower_hex(n / 16);

//     num = n % 16;

//     if(num < 10)
//         num += '0';
//     else
//         num += 'a' - 10;

//     ft_putchar_fd(num, 1);
//     return (length + 1);
// }

// static int put_upper_hex(unsigned int n){
//     int num;
//     int length;

//     length = 0;
//     if(n == 0)
//         return (length);

//     length = put_upper_hex(n / 16);

//     num = n % 16;

//     if(num < 10)
//         num += '0';
//     else
//         num += 'A' - 10;

//     ft_putchar_fd(num, 1);
//     return (length + 1);
// }

// int print_char(va_list args){
//     char c;

//     c = va_arg(args, int);
//     if(c == 0){
//         return (-2);
//     }
//     ft_putchar_fd(c, 1);
//     return (1);
// }

// int print_str(va_list args){
//     char *s;

//     s = va_arg(args, char*);
//     if(!s){
//         write(1, "(null)", 6);
//         return (6);
//     }
//     else if(*s == '\0'){
//         return (-2);
//     }
//     ft_putstr_fd(s, 1);
//     return (int)ft_strlen(s);
// }

// int print_pointer(va_list args){
//     void *p;
//     int str_length;

//     p = va_arg(args, void*);
//     str_length = put_hex_pointer(p);
//     return (str_length);
// }

// int print_integer(va_list args){
//     int num;
//     char *s;
//     int str_length;

//     num = va_arg(args, int);
//     s = ft_itoa(num);
//     if(!s)
//         return (-1);
//     ft_putstr_fd(s, 1);
//     str_length = (int)ft_strlen(s);
//     free(s);
//     return (str_length);
// }

// int print_unsigned_int(va_list args){
//     unsigned int num;
//     char *s;
//     int str_length;

//     num = va_arg(args, unsigned int);
//     s = uitoa(num);
//     if(!s)
//         return (-1);
//     ft_putstr_fd(s, 1);
//     str_length = (int)ft_strlen(s);
//     free(s);
//     return (str_length);
// }

// int print_lower_hex(va_list args) {
//     unsigned int num;
//     int str_length;

//     num = va_arg(args, unsigned int);
//     str_length = put_lower_hex(num);
//     return (str_length);
// }

// int print_upper_hex(va_list args){
//     unsigned int num;
//     int str_length;

//     num = va_arg(args, unsigned int);
//     str_length = put_upper_hex(num);
//     return (str_length);
// }

// static int print_format_specifier(char format, va_list args){
//     int str_length;

//     str_length = 0;
//     if(format == 'c')
//         str_length = print_char(args);
//     else if(format == 's')
//         str_length =  print_str(args);
//     else if(format == 'p')
//         str_length = print_pointer(args);
//     else if(format == 'd' || format == 'i')
//         str_length = print_integer(args);
//     else if(format == 'u')
//         str_length = print_unsigned_int(args);
//     else if(format == 'x')
//         str_length = print_lower_hex(args);
//     else if(format == 'X')
//         str_length = print_upper_hex(args);
//     else if(format == '%'){
//         ft_putchar_fd('%', 1);
//         str_length++;
//     }
//     else
//         str_length = -1;
//     return (str_length);
// }

// int is_valid_args(char *str, va_list args){
//     int is_format_specifier;
//     int str_length;

//     is_format_specifier = 0;
//     str_length = 0;
//     while(str && *str){
//         if(*str == '%' && (str+1) && *(str + 1)){
//             is_format_specifier = print_format_specifier(*(str+1), args);
//             if(is_format_specifier == -1){
//                 write(1, "malloc failure or incomplete format specifier\n",
// 46);
//                 return (str_length+46);
//             }
//             if(is_format_specifier != -2)
//                 str_length += is_format_specifier;
//         }
//         else if(*str == '%'){
//             write(1, "incomplete format specifier\n", 29);
//             return (str_length+29);
//         }
//         else{
//             ft_putchar_fd(*str, 1);
//             str_length++;
//         }
//         if(is_format_specifier > 0 || is_format_specifier == -2)
//             str++;
//         if(*str != '\0')
//             str++;
//         is_format_specifier = 0;
//     }
//     return (str_length);
// }

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_list	args_copy;
	int		str_length;
	char	*str_copy;

	str_copy = (char *)str;
	if (!str)
		return (0);
	va_start(args, str);
	va_copy(args_copy, args);
	str_length = is_valid_args(str_copy, args);
	va_end(args);
	if (!str_length)
		return (0);
	return (str_length);
}

// #include <stdio.h>
// #include <limits.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int main(void){
//     size_t count = 100;
//     int a = INT_MAX;
//     unsigned int b = INT_MIN;
//     int c = -9999;
//     char d = 30;
//     char *s = NULL;
//     char *s2 = "Hello_World!";
//     int e = -10;
//     int my_length, original_length;

//     while(count--){
//         my_length = ft_printf("\\%%%dd%i %x%X%u %c %s%s%p%p%x\n", a, b, c, c,
// c, d, s, s2, s2, s2-count, e);
//         original_length = printf("\\%%%dd%i %x%X%u %c %s%s%p%p%x\n", a, b, c,
// c, c, d, s, s2, s2, s2-count, e);
//         ft_printf("my length is %d original length is %d\n", my_length,
// original_length);
//         a++;b++;c++;d++;e++;
//     }
//     return (0);
// }