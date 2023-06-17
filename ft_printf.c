/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:45:43 by yuendo            #+#    #+#             */
/*   Updated: 2023/06/17 23:19:27 by yutoendo         ###   ########.fr       */
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

// // Function above are from libft and should be deleted before handing in

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

int print_char(va_list args){
    char c;

    c = va_arg(args, int);
    ft_putchar_fd(c, 1);
    return 1;
}

int print_str(va_list args){
    char *s;

    s = va_arg(args, char*);
    ft_putstr_fd(s, 1);
    return 1;
}

int print_pointer(va_list args){
    void *p;

    p = va_arg(args, void*);
    put_hex_pointer(p);
    return 1;
}

int print_integer(va_list args){
    int num;
    char *s;

    num = va_arg(args, int);
    s = ft_itoa(num);
    if(!s)
        return 0;
    ft_putstr_fd(s, 1);
    free(s);
    return 1;
}

int print_unsigned_int(va_list args){
    unsigned int num;
    char *s;

    num = va_arg(args, unsigned int);
    s = uitoa(num);
    if(!s)
        return 0;
    ft_putstr_fd(s, 1);
    return 1;
}

int print_lower_hex(va_list args) {
    unsigned int num;
    
    num = va_arg(args, unsigned int);
    put_lower_hex(num);
    return 1;
}

int print_upper_hex(va_list args){
    unsigned int num;
    num = va_arg(args, unsigned int);
    put_upper_hex(num);
    return 1;
}

int print_format_specifier(char format, va_list args){
    int is_format_specifier;

    is_format_specifier = 0;
    if(format == 'c')
        is_format_specifier = print_char(args);
    else if(format == 's')
        is_format_specifier =  print_str(args);
    else if(format == 'p')
        is_format_specifier = print_pointer(args);
    else if(format == 'd' || format == 'i')
        is_format_specifier = print_integer(args);
    else if(format == 'u')
        is_format_specifier = print_unsigned_int(args);
    else if(format == 'x')
        is_format_specifier = print_lower_hex(args);
    else if(format == 'X')
        is_format_specifier = print_upper_hex(args);
    else if(format == '%'){
        ft_putchar_fd('%', 1);
        is_format_specifier++;
    }
    else{
        write(1, "unhandled or incomplete format specifier\n", 41);
    }
    return is_format_specifier;
}

int is_valid_args(const char *str, va_list args){
    int is_format_specifier;
    int occurrence_of_format_specifier;

    is_format_specifier = 0;
    occurrence_of_format_specifier = 0;
    while(str && *str){
        if(*str == '%' && (str+1) && *(str + 1)){
            is_format_specifier =  print_format_specifier(*(str+1), args);
            if(!is_format_specifier)
                return 0;   // This is when something went wrong like malloc failure
            occurrence_of_format_specifier++;
        }
        else if(*str == '%'){
            write(1, "incomplete format specifier\n", 29);
            return 0;
        }
        else
            ft_putchar_fd(*str, 1);
        if(is_format_specifier)
            str++;
        if(*str != '\0')
            str++;
        is_format_specifier = 0;
    }
    return occurrence_of_format_specifier;
}

int ft_printf(const char *str, ...){
    va_list args;
    int length_of_format_specifier;
    
    char *str_copy = (char *)str;
    if(!str){
        write(1, "some kind of error message?\n", 28);
        return 1;
    }
    va_start(args, str);
    length_of_format_specifier = is_valid_args(str_copy, args);
    va_end(args);
    if(!length_of_format_specifier)
        return 0;
    return (ft_strlen(str) - length_of_format_specifier);
}

#include <stdio.h>

int main(void){
    int a;
    int b;

    a = ft_printf("%s", "Hello"); 
    printf("%d", a); 
    
    b = printf("%s", "Hello");
    printf("%d\n", b); 

    return 0;
}