/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 12:38:09 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/09/09 15:26:56 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		ret;
	char	specifier;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			specifier = format[i + 1];
			if (specifier == '%')
				ret = ft_putchar_conv('%');
			else if (specifier == 'c')
				ret = ft_putchar_conv(va_arg(args, int));
			else if (specifier == 's')
				ret = ft_putstr_conv(va_arg(args, char *));
			else if (specifier == 'd' || specifier == 'i')
				ret = ft_putnbr_conv(va_arg(args, int));
			else if (specifier == 'u')
				ret = ft_putunbr_conv(va_arg(args, unsigned int));
			else if (specifier == 'x')
				ret = ft_puthex_conv(va_arg(args, unsigned int), 0);
			else if (specifier == 'X')
				ret = ft_puthex_conv(va_arg(args, unsigned int), 1);
			else if (specifier == 'p')
				ret = ft_putptr_conv(va_arg(args, void *));
			count += ret;
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
