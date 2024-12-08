/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:11:24 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 20:56:58 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_count(int x, int fd)
{
	int	bytes;

	bytes = 0;
	if (x == -2147483648)
	{
		bytes += ft_putstr_count("-2147483648", fd);
		return (bytes);
	}
	if (x < 0)
	{
		bytes += ft_putchar_count('-', fd);
		x = -x;
	}
	if (x >= 10)
		bytes += ft_putnbr_count(x / 10, fd);
	bytes += ft_putchar_count((x % 10) + '0', fd);
	return (bytes);
}

int	specifiers(char format, va_list args, int fd)
{
	int	bytes;

	bytes = 0;
	if (format == 'c')
		bytes += ft_putchar_count(va_arg(args, int), fd);
	else if (format == 's')
		bytes += ft_putstr_count(va_arg(args, char *), fd);
	else if (format == 'p')
		bytes += ft_putpointer_count(va_arg(args, void *), fd);
	else if (format == 'i' || format == 'd')
		bytes += ft_putnbr_count(va_arg(args, int), fd);
	else if (format == 'u')
		bytes += ft_putunsigned_count(va_arg(args, unsigned int), fd);
	else if (format == 'x')
		bytes += ft_puthex_count(va_arg(args, unsigned int), 0, fd);
	else if (format == 'X')
		bytes += ft_puthex_count(va_arg(args, unsigned int), 1, fd);
	return (bytes);
}

int	ft_printf_format(int fd, const char *format, va_list args)
{
	int		bytes;

	bytes = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				bytes += ft_putchar_count('%', fd);
			else
				bytes += specifiers(*format, args, fd);
		}
		else
			bytes += ft_putchar_count(*format, fd);
		format++;
	}
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;

	va_start(args, format);
	bytes = ft_printf_format(1, format, args);
	va_end(args);
	return (bytes);
}

/*int	main()
{
	ft_printf("Testing %%c: %c\n", 'A');
	ft_printf("Testing %%s: %s\n", "Hello, World!");
	ft_printf("Testing %%p: %p\n", (void *)main);
	ft_printf("Testing %%d: %d\n", -12345);
	ft_printf("Testing %%i: %i\n", 6789);
	ft_printf("Testing %%u: %u\n", 1234567890);
	ft_printf("Testing %%x: %x\n", 0xDEADBEEF);
	ft_printf("Testing %%X: %X\n", 0xDEADBEEF);
	ft_printf("Testing %%: 100%% complete\n");

	printf("Testing %%c: %c\n", 'A');
	printf("Testing %%s: %s\n", "Hello, World!");
	printf("Testing %%p: %p\n", (void *)main);
	printf("Testing %%d: %d\n", -12345);
	printf("Testing %%i: %i\n", 6789);
	printf("Testing %%u: %u\n", 1234567890);
	printf("Testing %%x: %x\n", 0xDEADBEEF);
	printf("Testing %%X: %X\n", 0xDEADBEEF);
	printf("Testing %%: 100%% complete\n");
	return (0);
}*/
