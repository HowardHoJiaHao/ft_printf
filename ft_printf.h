/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hho-jia- <hho-jia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:52:53 by hho-jia-          #+#    #+#             */
/*   Updated: 2025/07/02 10:55:56 by hho-jia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BASEU16 "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
void	checkhex(const char *format, int *count, va_list args);
void	checkcases(const char	*format, int *count, va_list args);
int		ft_strlen(char *str);
void	ft_putchr(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putint(long number, int *count);
void	ft_puthexa(unsigned int number, int big, int base10, int *count);
void	ft_puthexaptr(unsigned long number, int big, int base10, int *count);
void	ft_putptr(void *ptr, int *count);

#endif