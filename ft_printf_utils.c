/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:52:45 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/07/01 14:42:37 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchr(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_putstr(char *s, int *count)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s, 1);
		(*count)++;
		s++;
	}
}

void	ft_putint(long num, int *count)
{
	int		i;
	char	buffer[20];

	i = 0;
	if (num == 0)
	{
		ft_putchr ('0', count);
		return ;
	}
	if (num < 0)
	{
		num = -num;
		ft_putchr ('-', count);
	}
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num = num / 10;
	}
	i--;
	while (i >= 0)
		ft_putchr(buffer[i--], count);
}

void	ft_puthexa(unsigned int number, int big, int base10, int *count)
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
