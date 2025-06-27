#include "printf.h"

void ft_putchar(char a)
{
    write(STDERR_FILENO, &a, 1);
}

int ft_putstr(char *c)
{
    int count;

    count = 0;
    while(*c)
    {
        write(STDERR_FILENO, c, 1);
        count++;
    }
    return (count);
}

int ft_putptr(unsigned int *p)
{
    const char *hex_digit = "0123456789abcdef";
    char buffer[22];
    int index;

    index = 0;
    if (p == 0)
    {
        buffer[index++] = '0';
        buffer[index++] = '\0';
        ft_putstr(buffer);
        return(index);
    }
    
    buffer[index++] = '0';
    buffer[index++] = 'x';
    
    while (p > 0)
    {
        buffer[index++] = hex_digit[p%16];
        p /= 16;
    }
    buffer[index] = '\0';
    while (p > 0)
    {
        ft_putchar(buffer[--index]);
    }
    return (index);
}


int ft_print_num(unsigned int num, int base, int is_signed) {
    char buffer[32];
    char *ptr = &buffer[31];
    *ptr = '\0';

    int is_negative = 0;
    if (is_signed && (int)num < 0) {
        is_negative = 1;
        num = (unsigned int)(-(int)num);
    }

    do {
        *--ptr = "0123456789abcdef"[num % base];
        num /= base;
    } while (num != 0);

    if (is_negative) {
        *--ptr = '-';
    }

    fputs(ptr, stdout);
}

// Helper: Print a floating-point number (simplified)
void ft_print_float(double num) {
    if (num < 0) {
        putchar('-');
        num = -num;
    }

    int int_part = (int)num;
    ft_print_num(int_part, 10, 1);

    putchar('.');

    // Print first 6 decimal places
    double frac_part = num - int_part;
    for (int i = 0; i < 6; i++) {
        frac_part *= 10;
        int digit = (int)frac_part;
        putchar('0' + digit);
        frac_part -= digit;
    }
}