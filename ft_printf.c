/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:43 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/17 17:02:46 by yutoendo         ###   ########.fr       */
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
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	if (s && *s)
		write(fd, s, ft_strlen(s));
}

static unsigned int	my_getdigit(long int n)
{
	unsigned int	digit;

	digit = 0;
	if (n <= 0)
	{
		n /= -1;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static char	my_tostr(int n)
{
	char	s;

	s = n + '0';
	return (s);
}

char	*ft_itoa(int num)
{
	char			*s;
	unsigned int	digit;
	unsigned int	i;
	long int		n;

	n = num;
	digit = my_getdigit(n);
	s = malloc(sizeof(char) * (digit + 1));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n /= -1;
	}
	s[digit] = '\0';
	i = digit - 1;
	if (n == 0)
		s[i] = '0';
	while (n > 0)
	{
		s[i--] = my_tostr(n % 10);
		n /= 10;
	}
	return (s);
}

// Function above are from libft and should be deleted before handing in

void put_hex_pointer(void *p){
    const char *hex = "0123456789abcdef";
    unsigned long long address = (unsigned long long)p;
    char str[19];
    size_t i;
    size_t start;

    str[0] = '0';
    str[1] = 'x';
    i = 18;
    while(i > 1){
        str[i] = hex[address % 16];
        address /= 16;
        i--;
    }
    start = 2;
    while(str[start] == '0' && start < 18)
        start++;
    write(1, str, 2);
    write(1, str+start, 19-start);
}

char	*uitoa(unsigned int num)
{
	char			*s;
	unsigned int	digit;
	unsigned int	i;
	long int		n;

	n = num;
	digit = my_getdigit(n);
	s = malloc(sizeof(char) * (digit + 1));
	if (!s)
		return (NULL);
	s[digit] = '\0';
	i = digit - 1;
	if (n == 0)
		s[i] = '0';
	while (n > 0)
	{
		s[i--] = my_tostr(n % 10);
		n /= 10;
	}
	return (s);
}

void put_lower_hex(unsigned int n){
    int num;
    if(n == 0) 
        return;

    put_lower_hex(n / 16);

    num = n % 16;
    
    if(num < 10)
        num += '0';
    else
        num += 'a' - 10;

    ft_putchar_fd(num, 1);
}

void put_upper_hex(unsigned int n){
    int num;
    if(n == 0) 
        return;

    put_upper_hex(n / 16);

    num = n % 16;
    
    if(num < 10)
        num += '0';
    else
        num += 'A' - 10;

    ft_putchar_fd(num, 1);
}

void print_char(va_list args){
    char c;

    c = va_arg(args, int);
    ft_putchar_fd(c, 1);
}

void print_str(va_list args){
    char *s;

    s = va_arg(args, char*);
    ft_putstr_fd(s, 1);
}

void print_pointer(va_list args){
    void *p;

    p = va_arg(args, void*);
    put_hex_pointer(p);
}

void print_integer(va_list args){
    int num;
    char *s;

    num = va_arg(args, int);
    s = ft_itoa(num);
    if(!s)
        return;
    ft_putstr_fd(s, 1);
    free(s);
    
}

void print_unsigned_int(va_list args){
    unsigned int num;
    char *s;

    num = va_arg(args, unsigned int);
    s = uitoa(num);
    if(!s)
        return;
    ft_putstr_fd(s, 1);
}

void print_lower_hex(va_list args) {
    unsigned int num;
    
    num = va_arg(args, unsigned int);
    put_lower_hex(num);
}

void print_upper_hex(va_list args){
    unsigned int num;
    num = va_arg(args, unsigned int);
    put_upper_hex(num);
}

int print_format_specifier(char format, va_list args){
    int is_format_specifier;

    is_format_specifier = 0;
    if(format == 'c'){
        print_char(args);
        is_format_specifier = 1;
    }
    else if(format == 's'){
        print_str(args);
        is_format_specifier = 1;
    }
    else if(format == 'p'){
        print_pointer(args);
        is_format_specifier = 1;
    }
    else if(format == 'd' || format == 'i'){
        print_integer(args);
        is_format_specifier = 1;
    }
    else if(format == 'u'){
        print_unsigned_int(args);
        is_format_specifier = 1;
    }
    else if(format == 'x'){
        print_lower_hex(args);
        is_format_specifier = 1;
    }
    else if(format == 'X'){
        print_upper_hex(args);
        is_format_specifier = 1;
    }
    else if(format == '%'){  
        ft_putchar_fd('%', 1);
        is_format_specifier = 1;
    }
    // probaby make another else to snap odd %
    return is_format_specifier;
}

int is_valid_args(const char *str, va_list args){
    int is_format_specifier;

    is_format_specifier = 0;
    while(str && *str){
        if(*str == '%' && (str+1) && *(str + 1)){
            is_format_specifier =  print_format_specifier(*(str+1), args); 
        }
        else
            ft_putchar_fd(*str, 1);
        if(is_format_specifier)
            str++;
        if(*str != '\0')
            str++;
        is_format_specifier = 0;
    }
    return 1;
}

int ft_printf(const char *str, ...){
    va_list args;
    
    char *str_copy = (char *)str;
    if(!str){
        write(1, "some kind of error message?\n", 28);
        return 1;
    }
    va_start(args, str);
    is_valid_args(str_copy, args);
    va_end(args);
    return 0;
}

#include <stdio.h>

int main(void){
    char a = 'a';
    char *s = "hello";
    char *s2 = "goodbye";
    int num = 2147483647;
    unsigned int num2 = 4294967295;
    
    ft_printf("%c\n", a); printf("%c\n\n", a);
    ft_printf("%s\n", s); printf("%s\n\n", s);
    ft_printf("%s\n", s2); printf("%s\n\n", s2);
    ft_printf("hello%%hello\n"); printf("hello%%hello\n\n");
    ft_printf("%p\n", s); printf("%p\n\n", s);
    ft_printf("%p\n", s2); printf("%p\n\n", s2);
    ft_printf("%dis%d\n", num, num); printf("%dis%d\n\n", num, num);
    ft_printf("%u\n", num2); printf("%u\n\n", num2);
    ft_printf("%x\n", -100); printf("%x\n\n", -100);
    ft_printf("%X\n", -100); printf("%X\n\n", -100);

    return 0;
}