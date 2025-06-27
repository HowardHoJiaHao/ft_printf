#include "printf.h"

// Main printf function
int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format != '%') {
            ft_putstr(*format);
            count++;
            format++;
            continue;
        }

        format++; // Skip '%'
        
        if (*format == 'c')
        {
            char c = (char)va_arg(args, int); // char promoted to int
            ft_putstr(c);
            count++;
        }
        else if (*format == 's')
        {
            char *str = va_arg(args, char *);
            count += ft_putstr(str);
        }
        // else if (*format == 'p')
        // {
        //     char *p = va_arg(args, void *);
        //     count += ft_putptr(p);
        // }
        else if (*format == 'd' || *format == 'i')
        {
            int num = va_arg(args, int);
            ft_print_num(num, 10, 1);
            count += (num < 0) ? 1 : 0; // Account for '-'
            while (num /= 10) count++;
        }
        else if ( *format == 'u')
        {
            unsigned int num = va_arg(args, unsigned int);
            ft_print_num(num, 10, 0);
            while (num /= 10) count++;
        }
        else if (*format == 'x' || *format == 'X')
        {
            unsigned int num = va_arg(args, unsigned int);
            ft_print_num(num, 16, 0);
            while (num /= 16) count++;
        }
        
        // else if (*format == 'f')
        // {
        //     double num = va_arg(args, double);
        //     ft_print_float(num);
        //     // Simplified: Assume 6 decimal digits + '.'
        //     count += 8; // Rough estimate
            
        // }
        else
        // (*format == '%')
        {   
            ft_putstr('%');
            count++;
            
        }
        format++;
        count++;
    }

    va_end(args);
    return count;
}

// Test the implementation
// int main() {
//     int x = 0;
//     x = ft_printf("Hello, %s \n", "world");
//     printf(" the length is : %d \n", x);

//     x = ft_printf("Integer: %d, Unsigned: %u, Hex: %x\n", -42, 42, 255);
//     printf(" the length is : %d \n", x);

//     x = ft_printf("Char: %c, Float: %f\n", 'A', 3.14159);
//     printf(" the length is : %d \n", x);
    
//     x = ft_printf("Escaped %% symbol\n");
//     printf(" the length is : %d \n", x);

//     return 0;
// }