# ft_printf

> 42 Common Core · Rank 01

A re-implementation of the libc `printf` function, built as a static library (`libftprintf.a`).

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

## Key concepts
Variadic functions (`va_start`, `va_arg`, `va_end`), number base conversion, writing a reusable static library.

## Usage
```bash
make                                  # builds libftprintf.a
cc main.c -L. -lftprintf
```
