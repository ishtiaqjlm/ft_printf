/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:25:55 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/09/11 12:47:45 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	nb;
	char	print;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >=10)
		count = count + ft_print_nbr( nb / 10);
	print = nb % 10 + '0';
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
