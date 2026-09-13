/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 10:01:49 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/09/13 14:41:24 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	address;

	if (!ptr)
		return (write(1, "0x0", 3));
	count = 0;
	write(1, "0x", 2);
	count = 2;
	address = (unsigned long)ptr;
	count = count + ft_print_hex(address, 0);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int	count;
	int n = 42;
	count = ft_print_ptr(&n);
	write(1, "\n", 1);
	ft_printf("count = %d\n", count);
	return (0);
}*/
