/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishtiahm <ishtiahm@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:51:58 by ishtiahm          #+#    #+#             */
/*   Updated: 2026/09/11 17:51:58 by ishtiahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_print_hex(unsigned int n, int uppercase)
{
    char	print;
    int		count;

    count = 0;
    if (n >= 16)
        count = count + ft_print_hex( n / 16, uppercase);
    print = n % 16;
    if (print > 9)
    {
        if (uppercase)
            print = print + 'A' - 10;
        else
            print = print + 'a' - 10;
    }
    else
        print = print + '0';
    write(1, &print, 1);
    count ++;
    return (count);
}
