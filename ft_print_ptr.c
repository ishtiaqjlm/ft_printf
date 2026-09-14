/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 10:01:49 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/09/14 18:45:13 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!address)
		return (write(1, "(nil)", 5));
	count = 0;
	write(1, "0x", 2);
	count = 2;
	count = count + ft_print_hex(address, 0);
	return (count);
}
