/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:17:43 by mevangel          #+#    #+#             */
/*   Updated: 2023/05/17 18:45:16 by mevangel         ###   ########.fr       */
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
#include "ft_printf.h"

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

//int	ft_print_p()

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
	else if (type == '%')
		return(write(1, "%", 1));
	// else if (type == 'p')
	// 	return();
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

// int	ft_print_s(va_list args)
// {
	
// }

// #include <stdio.h>

// int main(void)
// {
// 	unsigned int i = 4294967295;
// 	int a;
// 	int b;
// 	char x = 'y';
// 	char *str = "Hello world, MK here!";
	
// 	a = ft_printf("the ft_number is: %u\n", i);
// 	b = printf("the or_number is: %u\n", i);
// 	//a = ft_printf("The character is %c\n", x);
// 	// a = ft_printf("Mine gives: abcd%%efg\n");
// 	// b = printf("Orig gives: abcd%%efg\n");
// 	//b = printf("original  gives: %d\n", i);
// 	//b = printf("The character is %c\n", x);
// 	printf("Value returned from my printf is: %d\n", a);
// 	printf("Value returned from original printf is: %d\n", b);
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



