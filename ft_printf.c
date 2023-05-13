/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:17:43 by mevangel          #+#    #+#             */
/*   Updated: 2023/05/13 22:45:43 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the return type of printf is int, indicating the number of characters printed, 
//or a negative value if an error occurs

//i have to handle these 9 format specifiers: cspdiuxX%

#include <stdarg.h>
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}
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
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int	pr_chars; //for printed chars
	va_list	args;
	const char *specifiers;

	va_start(args, format);
	pr_chars = 0;
	specifiers = "cspdiuxX%";
	while (*format)
	{
		if ()
		if (*format == '%')
		{
			pr_chars += format_specifiers(*(format + 1), args);
		}
		else
		{
			
		}
		format++;
	}
	
}

int	format_specifiers(const char *str, va_list args)
{
	
}



#include <stdio.h>

int main() {
    char *str = NULL;
    int ret = printf("%s", str);
    printf("\nReturn value: %d\n", ret);
    return 0;
}



