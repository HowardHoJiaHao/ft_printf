#include "printf.h"

// Main printf function
int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format != '%') {
            ft_putchar(*format);
            count++;
            format++;
            continue;
        }

        format++; // Skip '%'

        if (*format == '\0') break; // Handle case where '%' is last character

        if (*format == 'd') {
            int num = va_arg(args, int);
            count += ft_print_num(num, 10, 1);
        }
        else if (*format == 'u') {
            unsigned int num = va_arg(args, unsigned int);
            count += ft_print_num(num, 10, 0);
        }
        else if (*format == 'x') {
            unsigned int num = va_arg(args, unsigned int);
            count += ft_print_num(num, 16, 0);
        }
        else if (*format == 'c') {
            char c = (char)va_arg(args, int);
            ft_putchar(c);
            count++;
        }
        else if (*format == 's') {
            char *str = va_arg(args, char *);
            if (!str) str = "(null)";
            int len = 0;
            while (str[len]) {
                ft_putchar(str[len++]);
            }
            count += len;
        }
        else if (*format == '%') {
            ft_putchar('%');
            count++;
        }
        else {
            // Handle unknown specifier by printing % and the character
            // ft_putchar('%');
            ft_putchar(*format);
            count += 2;
        }
        format++;
    }

    va_end(args);
    return count;
}
// Test the implementation
int main() {
    ft_printf("Hello, %s \n", "world");
    ft_printf("Integer: %d, Unsigned: %u, Hex: %x\n", -42, 42, 255);
    ft_printf("Char: %c, Float: %f\n", 'A', 3.14159);
    ft_printf("Escaped %% symbol\n");
    return 0;
}