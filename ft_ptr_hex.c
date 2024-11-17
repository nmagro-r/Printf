/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:48:31 by nmagro-r          #+#    #+#             */
/*   Updated: 2024/11/13 09:27:05 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_hex(unsigned long long p)
{
	int	result;
	int	hex;

	if (!p)
		return (write (1, "(nil)", 5));
	result = ft_putstr("0x");
	if (result == -1)
		return (-1);
	hex = ft_hex_low(p);
	if (hex == -1)
		return (-1);
	return (result + hex);
}
