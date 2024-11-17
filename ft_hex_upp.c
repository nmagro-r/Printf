/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_upp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:50:39 by nmagro-r          #+#    #+#             */
/*   Updated: 2024/11/13 09:25:48 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_upp(unsigned long long n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_hex_upp(n / 16);
		count += ft_putchar(base[n % 16]);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}
