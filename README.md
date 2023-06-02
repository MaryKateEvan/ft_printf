# <p align="center">**ft_printf**</p>
# <p align="center"> <sup>My own version of </sup> [![My Skills](https://skillicons.dev/icons?i=c)](https://skillicons.dev)<sup>'s famous function `printf()`</sup> </p>

> The goal of this project was pretty straightforward. We had to recode `printf()`, in order to learn on the way how to handle a variable number of arguments.

### **Conversions** that had to be implemented in the project:
* `%c` Prints a single character.
* `%s` Prints a string (as defined by the common C convention).
* `%p` The void * pointer argument has to be printed in *hexadecimal* format.
* `%d` Prints a decimal (base 10) number.
* `%i` Prints an integer in base 10.
* `%u` Prints an unsigned decimal (base 10) number.
* `%x` Prints a number in hexadecimal (base 16) lowercase format.
* `%X` Prints a number in hexadecimal (base 16) uppercase format.
* `%%` Prints a percent sign.<br>

### Structure of the project: 
- One Makefile
- One header file
- Two `.c` files that contain the main code of ***8 functions in total***:
	- `ft_printf.c` that has the 3 main functions
	- `printing_functions.c` that has the 5 functions that print the wanted output in the Standard Output using the `write()` command.

### Additional information/notes about the code: 
- `paco --strict` was handled also, apart from simple `francinette`/`paco`. <br>
	[In order to do that, I had to protect every `write()` return, and that's why I use the `int writefail;` variable.]
- `static` was used to limit the scope of helper functions only inside the `ft_printf.c` file, since the 5 functions of `printing_functions.c` file are all called outside of that file. 
- **No memory allocation** was used in the project

