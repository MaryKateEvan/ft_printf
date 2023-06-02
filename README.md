# ft_printf

> The goal of this project was pretty straightforward. We recoded `printf()`, learning on the way how to handle a variable number of arguments.

The following **9 conversions** had to be implemented in the project:<br>
* `%c` Prints a single character.<br>
* `%s` Prints a string (as defined by the common C convention).<br>
* `%p` The void * pointer argument has to be printed in *hexadecimal* format.<br>
* `%d` Prints a decimal (base 10) number.<br>
* `%i` Prints an integer in base 10.<br>
* `%u` Prints an unsigned decimal (base 10) number.<br>
* `%x` Prints a number in hexadecimal (base 16) lowercase format.<br>
* `%X` Prints a number in hexadecimal (base 16) uppercase format.<br>
* `%%` Prints a percent sign.<br>

~~this was mistaken~~

__option 2 for bold__<br>
_option 2 for italic_<sub>This is a subscript text</sub>

***all bold and italic***<sup>This is a superscript text</sup><br>

> text that is a quote

The prototype of `ft_printf()` is:<br>
`int ft_printf(const char *, ...);`

Many lines of code:
```
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars;

	printed_chars = 0;
	va_start(args, str);
	printed_chars = mainfunction(str, args, 0);
	va_end(args);
	return (printed_chars);
}
```

My intra profile [here](https://profile.intra.42.fr/users/mevangel)<br>

![Screenshot of a comment on a GitHub issue showing an image, added in the Markdown, of an Octocat smiling and raising a tentacle.](https://myoctocat.com/assets/images/base-octocat.svg)

- George Washington
* John Adams
+ Thomas Jefferson
+ Thom Jef
* John Adams

- 42 Community:
  - Bocal
  - students
    - MK
	- Harsh
	- Eugen