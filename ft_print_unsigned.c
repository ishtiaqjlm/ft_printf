/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:47:41 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/09/11 17:47:41 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	print;
	int		count;

	count = 0;
	if (n >= 10)
		count = count + ft_print_unsigned( n / 10);
	print = n % 10 + '0';
	write(1, &print, 1);
	count ++;
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int	result;
	result = ft_print_nbr(-123);
	printf("result: %d\n", result);
}*/
