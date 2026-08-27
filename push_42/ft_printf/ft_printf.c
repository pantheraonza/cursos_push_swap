/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:05:50 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:05:53 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int		bytes;

	if (str == NULL)
		return (write(1, "(null)", 6));
	bytes = write(1, str, ft_strlen(str));
	return (bytes);
}

int	ft_print_char(char c)
{
	int		bytes;

	bytes = write(1, &c, 1);
	return (bytes);
}

int	ft_dispatch(char conv_type, va_list args)
{
	if (conv_type == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (conv_type == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (conv_type == 'd' || conv_type == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (conv_type == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (conv_type == 'x')
		return (ft_print_hexa(va_arg(args, unsigned int), "0123456789abcdef"));
	if (conv_type == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (conv_type == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (conv_type == '%')
		return (ft_print_char('%'));
	return (ft_print_char('%'));
}

int	ft_scan(char const *format, va_list args)
{
	size_t		i;
	int			total_bytes;
	int			partial_bytes;

	i = 0;
	total_bytes = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			partial_bytes = ft_dispatch(format[i + 1], args);
			i = i + 2;
		}
		else
		{
			partial_bytes = ft_print_char(format[i]);
			i = i + 1;
		}
		total_bytes = total_bytes + partial_bytes;
	}
	return (total_bytes);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			total_bytes;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	total_bytes = ft_scan(format, args);
	va_end(args);
	return (total_bytes);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	emul;
// 	int	orig;
// 	int	x;

// 	x = 42;
// 	emul = ft_printf("Todo: c=%c s=%s d=%d u=%u x=%x X=%X p=%p pct=%%\n",
// 			'A', "hola", -42, 42, 255, 255, &x);
// 	orig = printf("Todo: c=%c s=%s d=%d u=%u x=%x X=%X p=%p pct=%%\n",
// 			'A', "hola", -42, 42, 255, 255, &x);
// 	ft_printf("Test 0 (mezcla) -> orig=%d emul=%d\n\n", orig, emul);
// 	emul = ft_printf("nulo_s=%s nulo_p=%p\n", (char *) NULL, (void *) NULL);
// 	orig = printf("nulo_s=%s nulo_p=%p\n", (char *) NULL, (void *) NULL);
// 	ft_printf("Test 1 (nulos) -> orig=%d emul=%d\n\n", orig, emul);
// 	emul = ft_printf("vacio=[%s] cero_d=%d cero_x=%x\n", "", 0, 0);
// 	orig = printf("vacio=[%s] cero_d=%d cero_x=%x\n", "", 0, 0);
// 	ft_printf("Test 2 (vacios y ceros) -> orig=%d emul=%d\n\n", orig, emul);
// 	return (0);
// }