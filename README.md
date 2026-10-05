# ft_printf

> 42 Common Core · Rank 01

The purpose of this project is to learn about *variadic functions* by recoding `libc`'s [`printf`](https://man7.org/linux/man-pages/man3/printf.3.html). It handles the `cspdiuxX%` type conversions and is built as a static library (`libftprintf.a`).

```c
int ft_printf(const char *format, ...);
```

## Supported conversions
| Conversion | Output |
|:--:|--|
| `%c` | single character |
| `%s` | string |
| `%p` | pointer address in hexadecimal |
| `%d` / `%i` | signed decimal integer |
| `%u` | unsigned decimal integer |
| `%x` / `%X` | hexadecimal (lower / upper case) |
| `%%` | percent sign |

## Allowed Functions
- [`malloc`](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`va_start, va_arg, va_end & va_copy`](https://man7.org/linux/man-pages/man3/stdarg.3.html)

## Clone
Clone the repository:
```bash
git clone https://github.com/HowardHoJiaHao/ft_printf.git
```

## Compile and Run
To compile, `cd` into the cloned directory and:
```bash
make
```

This will compile the associated functions using the Makefile into the `libftprintf.a` library, which can be used in future 42 projects. To use it in your own program, include the header and link the library:
```c
#include "ft_printf.h"   // then compile with: cc main.c -L. -lftprintf
```
