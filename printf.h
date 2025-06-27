#ifndef PRINTF_HEADER
#define PRINTF_HEADER

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

void ft_putchar(char c);
int ft_print_num(unsigned int num, int base, int is_signed) ;
void ft_print_float(double num);

#endif
