/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:17:43 by mevangel          #+#    #+#             */
/*   Updated: 2023/05/14 17:50:58 by mevangel         ###   ########.fr       */
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
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
	return (NULL);
}

int	ft_print_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	format_specifiers(char spcfr, va_list args, int *printed_chars)
{
	if (spcfr == 'c')
		*printed_chars = ft_print_c(args);
	// if (spcfr == 's')
	// 	*printed_chars = ft_print_s(va_arg(args, char *));
	return (*printed_chars);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	printed_chars; //for printed chars
	char *specifiers;
	int	i;

	va_start(args, str);
	printed_chars = 0;
	specifiers = "cspdiuxX%";
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr(specifiers, str[i + 1]))
		{
			printed_chars += format_specifiers(str[i + 1], args, &printed_chars);
			i += 2;
		}
		else
		{
			printed_chars += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (printed_chars);
}

// int	ft_print_s(va_list args)
// {
	
// }

#include <stdio.h>

int main(void)
{
	char b = 'a';
	
	//ft_printf("%c", b);
	printf("result with original ft: %c", b);
	return 0;
}





// //testing the printing of (null)

// #include <stdio.h>

// int main() {
//     char *str = NULL;
//     int ret = printf("%s", str);
//     printf("\nReturn value: %d\n", ret);
//     return 0;
// }



