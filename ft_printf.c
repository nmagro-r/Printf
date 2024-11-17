/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagro-r <nmagro-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:53:38 by nmagro-r          #+#    #+#             */
/*   Updated: 2024/11/17 13:00:19 by nmagro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convertion(va_list args, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_ptr_hex(va_arg(args, unsigned long));
	else if (specifier == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += ft_hex_low(va_arg(args, unsigned int));
	else if (specifier == 'X')
		count += ft_hex_upp(va_arg(args, unsigned int));
	else
		count += ft_putchar(specifier);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_convertion(args, format[i]);
		}
		else
			count += ft_putchar(format[i]);
		if (format[i])
			i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	// Prueba básica con varios tipos de formato
	ft_printf("Prueba con caracteres: %c %c %c\n", 'A', 'B', 'C');
	printf("Prueba con caracteres: %c %c %c\n\n", 'A', 'B', 'C');

	// Prueba con cadenas de texto
	ft_printf("Prueba con cadenas: %s %s\n", "Hola", "Mundo");
	printf("Prueba con cadenas: %s %s\n\n", "Hola", "Mundo");

	// Prueba con números enteros
	ft_printf("Prueba con números enteros: %d %i\n", 2147483648, -42);
	printf("Prueba con números enteros: %d %i\n\n", 2147483648, -42);

	// Prueba con números sin signo
	ft_printf("Prueba con números sin signo: %u %u\n", -4466, 4000000000);
	printf("Prueba con números sin signo: %u %u\n\n", -4466, 4000000000);

	// Prueba con números hexadecimales
	ft_printf("Prueba con hexadecimales: %x %X\n", -2147483647, 255);
	printf("Prueba con hexadecimales: %x %X\n\n", -2147483647, 255);

	// Prueba con punteros
	int var = 42;
	ft_printf("Prueba con punteros: %p\n", &var);
	printf("Prueba con punteros: %p\n\n", &var);

	// Prueba con el porcentaje literal
	ft_printf("Prueba con porcentaje: %% %% %%\n");
	printf("Prueba con porcentaje: %% %% %%\n\n");

	return (0);
}*/