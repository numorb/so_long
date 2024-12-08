/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:54:51 by blnunez-          #+#    #+#             */
/*   Updated: 2024/10/26 20:29:17 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer_count(void *p, int fd)
{
	int	bytes;

	bytes = 0;
	if (p == NULL || p == 0)
	{
		bytes += ft_putstr_count("(nil)", fd);
		return (bytes);
	}
	bytes += ft_putstr_count("0x", fd);
	bytes += ft_puthex_count((unsigned long)p, 0, fd);
	return (bytes);
}

int	ft_putunsigned_count(unsigned int x, int fd)
{
	int	bytes;

	bytes = 0;
	if (x >= 10)
		bytes += ft_putunsigned_count(x / 10, fd);
	bytes += ft_putchar_count((x % 10) + '0', fd);
	return (bytes);
}

int	ft_puthex_count(unsigned long x, int upcase, int fd)
{
	char	*str;
	int		bytes;

	if (upcase)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	bytes = 0;
	if (x >= 16)
		bytes += ft_puthex_count(x / 16, upcase, fd);
	bytes += ft_putchar_count(str[x % 16], fd);
	return (bytes);
}

int	ft_putchar_count(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_putstr_count(char *s, int fd)
{
	int	bytes;

	bytes = ft_strlen(s);
	ft_putstr_fd(s, fd);
	return (bytes);
}
