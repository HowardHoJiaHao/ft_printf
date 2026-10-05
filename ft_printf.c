/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:52:33 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/07/02 10:56:08 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	number;

	number = (unsigned long)ptr;
	if (ptr == 0)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_puthexaptr(number, 0, 0, count);
}

void	ft_puthexaptr(unsigned long number, int big, int base10, int *count)
{
	char	*usebase;
	char	buffer[20];
	int		i;

	usebase = BASE16;
	if (number == 0)
	{
		ft_putchr('0', count);
		return ;
	}
	if (big)
		usebase = BASEU16;
	if (base10)
		usebase = BASE10;
	i = 0;
	while (number > 0)
	{
		buffer[i++] = usebase[number % ft_strlen(usebase)];
		number = number / ft_strlen(usebase);
	}
	i--;
	while (i >= 0)
		ft_putchr(buffer[i--], count);
}

void	checkhex(const char *format, int *count, va_list args)
{
	if (*format == 'X')
		ft_puthexa(va_arg(args, unsigned int), 1, 0, count);
	else
		ft_puthexa(va_arg(args, unsigned int), 0, 0, count);
}

void	checkcases(const char	*format, int *count, va_list args)
{
	if (*format == 'c')
		ft_putchr ((char)va_arg(args, int), count);
	else if (*format == 's')
		ft_putstr (va_arg(args, char *), count);
	else if (*format == 'd' || *format == 'i')
		ft_putint((long)va_arg(args, int), count);
	else if (*format == 'x' || *format == 'X')
		checkhex(format, count, args);
	else if (*format == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (*format == 'u')
		ft_puthexa(va_arg(args, unsigned int), 0, 1, count);
	else if (*format == '%')
		ft_putchr ('%', count);
	else
		ft_putchr (*format, count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchr (*format, &count);
			format++;
			continue ;
		}
		format++;
		checkcases(format, &count, args);
		format++;
	}
	va_end (args);
	return (count);
}