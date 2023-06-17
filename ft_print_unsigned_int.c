/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutoendo <yutoendo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:06:01 by yutoendo          #+#    #+#             */
/*   Updated: 2023/06/17 20:32:38 by yutoendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*uitoa(unsigned int num)
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