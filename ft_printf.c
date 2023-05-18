/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:17:43 by mevangel          #+#    #+#             */
/*   Updated: 2023/05/18 20:01:45 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the return type of printf is int, indicating the number of characters printed, 
//or a negative value if an error occurs

//i have to handle these 9 format specifiers: cspdiuxX%

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

#include <stdarg.h>
#include <unistd.h>
#include "printf.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

int	ft_print_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return(write(1, "(null)", 6));
	while(str[i])
		i++;
	return (write(1, str, i));
}

int	ft_print_number(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
		count++;
	}
	if (n > 9)
		count += ft_print_number(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	count++;
	return (count);
}

int	ft_print_hexa(size_t dec, char type)
{
	char	*hexadigits;
	char	num[16];
	int		i;

	i = 16;
	hexadigits = "0123456789abcdef";
	if (dec == 0)
		return (write(1, "0", 1));
	if (type == 'X')
		hexadigits = "0123456789ABCDEF";
	while(dec > 0 && i >= 0)
	{
		num[--i] = hexadigits[dec % 16];
		dec = dec / 16;
	}
	return (write(1, num + i, 16 - i));
}

int	ft_print_p(void *ptr)
{
	if (ptr == NULL)
		return (write(1, "0x0", 3));
	if (write(1, "0x", 2) < 0)
		return (-1);
	return(ft_print_hexa((size_t)ptr, 'x') + 2);
}

int	format_specifiers(char type, va_list args)
{
	if (type == 'c')
		return(ft_print_c(va_arg(args, int)));
	else if (type == 's')
		return(ft_print_s(va_arg(args, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_number(va_arg(args, int)));
	else if (type == 'u')
		return (ft_print_number(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hexa((size_t)va_arg(args, unsigned int), type));
	else if (type == 'p')
		return (ft_print_p(va_arg(args, void *)));
	else
		return(write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	pr_chars; //for pr_chars
	char *specifiers;
	int	i;

	va_start(args, str);
	pr_chars = 0;
	specifiers = "cspdiuxX%";
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			pr_chars += format_specifiers(str[i + 1], args);
			i += 2;
		}
		else
		{
			pr_chars += (int)(write(1, &str[i], 1));
			i++;
		}
	}
	va_end(args);
	return (pr_chars);
}

// #include <stdio.h>

// int main(void)
// {
// 	unsigned int i = 234567;
// 	int a;
// 	int b;
// 	char x = 'y';
// 	char *str = "Hello world, MK here!";
	
// 	a = ft_printf("the ft_number is: %p\n", str);
// 	b = printf("the or_number is: %p\n", str);
// 	//a = ft_printf("The character is %c\n", x);
// 	// a = ft_printf("Mine gives: abcd%%efg\n");
// 	// b = printf("Orig gives: abcd%%efg\n");
// 	//b = printf("original  gives: %d\n", i);
// 	//b = printf("The character is %c\n", x);
// 	printf("Value returned from my printf is: %d\n", a);
// 	printf("Value returned from original printf is: %d\n", b);
// 	//system("leaks a.out");
// 	return 0;
// }


// #include <stdio.h>

// int main() {
//     int num = 42;
//     int* ptr = &num;

//     printf("Pointer Value: %p\n", ptr);
//     printf("Hexadecimal Value: %p\n", (void*)ptr);

//     return 0;
// }



// //testing the printing of (null)

// #include <stdio.h>

// int main() {
//     char *str = NULL;
//     int ret = printf("%s", str);
//     printf("\nReturn value: %d\n", ret);
//     return 0;
// }

//the part of hexafunnction that i deleted:

//count = 0;
	// while (i < 16)
	// {
	// 	// if (write(1, &num[i++], 1) < 0)
	// 	// 	return (-1);
	// 	if (write(1, num + i, 16 - i) < 0)
	// 		return (-1);
	// 	count++;
	// }
	// return (count);

