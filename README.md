*This project has been created as part of the 42 curriculum by ishtiahm.*

# ft_printf

## Description

`ft_printf` is a 42 Common Core project that consists of recreating the behavior of the standard C `printf()` function.

The goal of this project is to understand variadic functions in C using `va_list`, `va_start`, `va_arg`, and `va_end`, while practicing formatted output, type handling, recursion, pointers, and modular program design.

The mandatory implementation supports the following conversions:

* `%c` — character
* `%s` — string
* `%p` — pointer address
* `%d` — decimal integer
* `%i` — integer
* `%u` — unsigned decimal integer
* `%x` — hexadecimal in lowercase
* `%X` — hexadecimal in uppercase
* `%%` — percent sign

The project produces a static library named `libftprintf.a`.

## Instructions

### Compilation

Clone the repository and enter the project directory:

```bash
git clone git@vogsphere.42prague.com:vogsphere/intra-uuid-35ce8fed-3b5e-44e1-a550-012bcfa7ccf2-7661114-ishtiahm
cd ft_printf
```

Compile the library using:

```bash
make
```

This creates:

```text
libftprintf.a
```

To remove object files:

```bash
make clean
```

To remove object files and the library:

```bash
make fclean
```

To rebuild everything:

```bash
make re
```

### Using the library

Include the project header:

```c
#include "ft_printf.h"
```

Compile your program together with the library:

```bash
cc main.c -L. -lftprintf
```

Then run:

```bash
./a.out
```

## Algorithm and Data Structure

### Format parsing

The main algorithm scans the format string from left to right.

For each character:

1. If it is a normal character, it is written directly using `write()`.
2. If it is `%`, the following character is interpreted as a conversion specifier.
3. The corresponding argument is retrieved from the `va_list`.
4. A dedicated printing function handles the conversion.
5. The number of characters written is added to the total return value.

The general flow is:

```text
format string
     |
     v
scan character by character
     |
     +---- normal character ---> write()
     |
     +---- '%' ---> read specifier
                         |
                         v
                    ft_format()
                         |
        +----------------+----------------+
        |       |        |       |        |
       %c      %s       %d      %x       %p ...
        |       |        |       |        |
        v       v        v       v        v
    print functions
```

### Integer conversion

Decimal and unsigned integers are printed recursively.

For a number greater than or equal to 10, the function first processes the higher digits by recursively dividing the number by 10. The current last digit is then converted to its character representation.

For example:

```text
1234
 |
123
 |
12
 |
1
```

The digits are then written while the recursive calls return:

```text
1 -> 2 -> 3 -> 4
```

For negative integers, the value is converted to `long` before negation. This allows the implementation to correctly handle `INT_MIN` (`-2147483648`), which cannot be safely negated while stored as a regular `int`.

### Hexadecimal conversion

Hexadecimal values are processed recursively by dividing the number by 16.

The remainder determines the hexadecimal digit:

```text
0-9 -> '0'-'9'
10-15 -> 'a'-'f'   for %x
10-15 -> 'A'-'F'   for %X
```

The same function is used for both lowercase and uppercase output.

### Pointer conversion

For `%p`, the pointer is converted to an `unsigned long` integer representing its address.

The output begins with:

```text
0x
```

followed by the address represented in lowercase hexadecimal.

A `NULL` pointer is represented as:

```text
0x0
```

### Data structures

The project mainly uses simple C data types rather than complex data structures.

The main data structures are:

* `va_list` for accessing variable arguments.
* Character arrays for format strings and string arguments.
* Primitive integer types for numeric conversions.
* `void *` for pointer arguments.

The implementation was intentionally kept modular by using separate functions for each conversion instead of storing conversion information in a complex data structure.

This keeps the code easier to understand and maintain while satisfying the mandatory requirements.

## Project Structure

```text
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_format.c
├── ft_print_char.c
├── ft_print_str.c
├── ft_print_nbr.c
├── ft_print_unsigned.c
├── ft_print_hex.c
├── ft_print_ptr.c
└── README.md
```

## Testing

The implementation was tested individually for every mandatory conversion and then tested using combinations of multiple conversions.

Important edge cases include:

* `NULL` strings
* `NULL` pointers
* zero values
* negative integers
* `INT_MAX`
* `INT_MIN`
* `UINT_MAX`
* hexadecimal zero
* maximum unsigned hexadecimal values
* multiple conversions in one format string
* return value of `ft_printf()`

The return value was also compared with the standard `printf()` for equivalent test cases.

Example:

```c
printf("Hello %d %x test!\n", 42, 255);
ft_printf("Hello %d %x test!\n", 42, 255);
```

Both functions should produce the same output and return the same number of characters written.

## Resources

### C documentation

* `printf()` — C formatted output
* `stdarg.h` — variable argument handling
* `write()` — low-level output
* Integer limits and integer types

Useful concepts studied during the project include:

* Variadic functions
* `va_list`
* `va_start`
* `va_arg`
* `va_end`
* Recursion
* Pointers
* Integer representation
* Static libraries
* Makefiles

### 42 Resources

The main reference for the project was the official `ft_printf` project subject provided by the 42 curriculum.

The project also builds on concepts learned during the 42 C Piscine and Libft projects.

### AI usage

AI was used as a learning and debugging assistant during the project.

It was used for:

* Understanding the requirements of the `ft_printf` project.
* Explaining variadic functions and `va_list`.
* Reasoning about how each conversion should work.
* Debugging compilation errors and segmentation faults.
* Understanding C types and conversions, especially `void *`, `unsigned int`, and `unsigned long`.
* Debugging edge cases such as `NULL` strings and `INT_MIN`.
* Understanding Makefile syntax and targets.
* Explaining Norminette errors and variable declaration alignment.
* Suggesting test cases and testing strategies.

The implementation was written and tested by the student. AI assistance was primarily used to explain concepts, identify problems, and provide debugging hints rather than replacing the development and testing process.

## Author

**Ishtiaq Ahmed**

42 Prague

