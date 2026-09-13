/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 12:25:55 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/09/13 13:52:24 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_nbr_helper(long nb)
{
	char	print;
	int		count;

	count = 0;
	if (nb >= 10)
		count = count + ft_print_nbr_helper(nb / 10);
	print = nb % 10 + '0';
	write(1, &print, 1);
	count ++;
	return (count);
}

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		count++;
	}
	if (nb >= 10)
		count = count + ft_print_nbr_helper(nb);
	return (count);
}
